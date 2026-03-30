/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;


void test_count_empty();
void test_count_regular();
void test_sum_small_data_set();
void test_sum_big_data_set();
void test_mean_one_element();
void test_mean_large_data_set();
void test_median_one_element();
void test_median_large_data_set();
void test_min_one_element();
void test_min_large_data_set();
void test_max_one_element();
void test_max_large_data_set();
void test_stdev_big_data_set();
void test_stdev_small_data_set();
void test_percentile_zero();
void test_percentile_one();
void test_filter_empty();
void test_filter_no_target();
void test_filter_small_data_set();
void test_filter_big_data_set();


int main() {
  test_count_empty();
  test_count_regular();
  test_sum_small_data_set();
  test_sum_big_data_set();
  test_mean_one_element();
  test_mean_large_data_set();
  test_median_one_element();
  test_median_large_data_set();
  test_min_one_element();
  test_min_large_data_set();
  test_max_one_element();
  test_max_large_data_set();
  test_stdev_big_data_set();
  test_stdev_small_data_set();
  test_percentile_zero();
  test_percentile_one();
  test_filter_empty();
  test_filter_no_target();
  test_filter_small_data_set();
  test_filter_big_data_set();

  cout << "PASS!" << endl;
  return 0;
}

void test_count_empty(){
  vector<double> v {};
  assert(count(v) == 0);
  cout << "Pass: count_empty" << endl;
}

void test_count_regular(){
  vector<double> v {4, 9, 1, 30, 2};
  assert(count(v) == 5);
  cout << "Pass: count_regular" << endl;
}

void test_sum_small_data_set() {
  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  assert(sum(data) == 6);
  cout << "Pass: sum_small_data_set" << endl;
}

void test_sum_big_data_set(){
  vector<double> v {1, 6, 3, 5, 8, 3, 4, 9, 11, 30, 5, 5, 5, 5};
  assert(sum(v) == 100);
  cout << "Pass: sum_big_data_set" << endl;
}

void test_mean_one_element(){
  vector<double> v {72};
  assert(mean(v) == 72);
  cout << "Pass: mean_one_element" << endl;
}

void test_mean_large_data_set(){
  vector<double> v {7, 7, 8, 3, 5, 12, 64, 22, 6, 5, 8, 10, 0, 4};
  assert(mean(v) == 11.5);
  cout << "Pass: mean_large_data_set" << endl;
}

void test_median_one_element(){
  vector<double> v {0};
  assert(median(v) == 0);
  cout << "Pass: median_one_element" << endl;
}

void test_median_large_data_set(){
  vector<double> v {7, 4, 5, 1, 76, 44, 777, 1, 4, 78, 8, 8, 8, 8};
  assert(median(v) == 8);
  cout << "Pass: median_large_data_set" << endl;
}

void test_min_one_element(){
  vector<double> v {6};
  assert(min(v) == 6);
  cout << "Pass: min_one_element" << endl;
}

void test_min_large_data_set(){
  vector<double> v {8, 4, 7, 3, 7, 9, 6, 23, 787, 44, 6, 7, 3, 1, 8, 1, 5};
  assert(min(v) == 1);
  cout << "Pass: min_large_data_set" << endl;
}

void test_max_one_element(){
  vector<double> v {3};
  assert(max(v) == 3);
  cout << "Pass: max_one_element" << endl;
}

void test_max_large_data_set(){
  vector<double> v {1, 2, 3, 4, 5, 6, 7, 444, 8, 9, 10};
  assert(max(v) == 444);
  cout << "Pass: max_large_data_set" << endl;
}

const double epsilon = 0.0001;

void test_stdev_big_data_set(){
  vector<double> v {3.6, 4.5, 3, 7, 4, 4, 5, 1,0, 40.8};
  double expected = 11.9369;
  double actual = stdev(v);
  assert(abs(actual - expected) < epsilon);
  cout << "Pass: stdev_big_data_set" << endl;
}

void test_stdev_small_data_set(){
  vector<double> v {8.6, 1};
  double expected = 5.374;
  double actual = stdev(v);
  assert(abs(actual - expected) < epsilon);

  cout << "Pass: stdev_one_element" << endl;
}

void test_percentile_zero(){
  vector<double> v {4, 9, 1, 30, 2};
  double p = 0;
  assert(percentile(v, p) == 1);
  cout << "Pass: percentile_zero" << endl;
}

void test_percentile_one(){
  vector<double> v {4, 9, 1, 30, 2};
  double p = 1;
  assert(percentile(v, p) == 30);
  cout << "Pass: percentile_one" << endl;
}

void test_filter_empty(){
  vector<double> v;
  vector<double> criteria;
  double target = 3;
  vector<double> newV;
  assert(filter(v, criteria, target) == newV);
  cout << "Pass: filter_empty" << endl;
}

void test_filter_no_target(){
  vector<double> v {52.9, 45, 3, 4, 6.43, 24,5, 25.6, 3, 3, 3, 22.1};
  vector<double> criteria {0, 1, 2, 3, 2, 1, 2, 3, 2, 1, 0};
  double target = 4;
  vector<double> newV;
  assert(filter(v, criteria, target) == newV);
  cout << "Pass: filter_no_target" << endl;
}

void test_filter_small_data_set(){
  vector<double> v {3.5, 4.5, 3.2, 6};
  vector<double> criteria {0, 0, 4, 7};
  double target = 0;
  vector<double> newV {3.5, 4.5};
  assert(filter(v, criteria, target) == newV);
  cout << "Pass: filter_small_data" << endl;
}

void test_filter_big_data_set(){
  vector<double> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  vector<double> criteria {6, 6.1, 5, 4, 5, 6.1, 6.1, 5, 4, 6, 6.1, 6};
  double target = 6.1;
  vector<double> newV {2, 6, 7, 11};
  assert(filter(v, criteria, target) == newV);
  cout << "Pass: filter_big_data" << endl;
}
