#include "stats.hpp"
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;


// Returns the sample size of the numbers in v
int count(vector<double> v){
  return v.size();
}

// Returns the sum of the numbers in v
double sum(vector<double> v){
  double sum = 0;
  for(size_t i = 0; i < v.size(); ++i){
    sum += v[i];
  }
  return sum;
}

// Returns the average of the numbers in v
double mean(vector<double> v){
  return (sum(v)) / count(v);
}

// Returns the median of the numbers in v
double median(vector<double> v){
  // sort the list
  sort(v.begin(), v.end());   
  int vLength = count(v);
  if (vLength % 2 == 1){
    // If the list has an odd number of digits, find the middle value
    int midDigit = vLength / 2;
    return v[midDigit];
  } else {
    // If the list is even, find the average of the two middle values
    int midDigit2 = vLength / 2;
    int midDigit1 = midDigit2 - 1;
    double val1 = v[midDigit1];
    double val2 = v[midDigit2];
    double sum = val1 + val2;
    return sum / 2;
  }
}

// Returns the min number in v
double min(vector<double> v){
  sort(v.begin(), v.end());
  return v[0];
}

// Returns the max number in v
double max(vector<double> v){
  sort(v.begin(), v.end());
  return v[v.size() - 1];
}

// Returns the corrected sample standard deviation of the numbers in v
double stdev(vector<double> v){
  sort(v.begin(), v.end());
  double avg = mean(v);
  double summation = 0;
  for (size_t i = 0; i < v.size(); ++i) {
    double subtract = avg - v[i];
    summation += pow(subtract, 2);
  }
  double denominator = v.size() - 1.0;
  double sample = static_cast<double>(summation) / denominator;
  return sqrt(sample);
}

//REQUIRES: v is not empty
//          p is between 0 and 1, inclusive
//EFFECTS: returns the percentile p of the numbers in v like Microsoft Excel.
//  Refer to the project spec for the formula to use.
//  NOTE: the definition in the spec uses indexing from 1.  You will need to
//  adapt it to use indexing from 0.
double percentile(vector<double> v, double p){
  sort(v.begin(), v.end());
  if (p == 1){
    return v[v.size() - 1];
  }
  int numValues = v.size() - 1;
  double rank = p * numValues;
  // intPart = k
  // fracPart = d
  double tempIntPart = 0;
  double fracPart = modf(rank, &tempIntPart);
  double intPart = static_cast<int>(tempIntPart);
  double vk1 = v[intPart];
  double vk2 = v[intPart + 1];
  double difference = vk2 - vk1;
  double vPercentile = vk1 + fracPart * difference;
  return vPercentile;
}

//REQUIRES: v and criteria have the same number of elements
//EFFECTS: returns a new, filtered version of v containing the elements (and
//         only those elements) at v[x] where criteria[x] is equal to target,
//         in the same order as they originally appear in v.
//         Note: For this function, compare values to the criteria using ==.
vector<double> filter(vector<double> v, vector<double> criteria, double target){
  vector<double> newV;
  for (size_t i = 0; i < v.size(); ++i){
    if (criteria[i] == target){
      newV.push_back(v[i]);
    }
  }
  return newV;
}
