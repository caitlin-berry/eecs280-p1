# Project 1 - Statistics Analysis Program

## Overview
This project implements a C++ statistics library and a two-sample analysis program. It computes descriptive statistics and performs statistical comparisons between two groups of data, including generating confidence intervals using bootstrap resampling.

The program processes real datasets (CSV/TSV files), filters data into groups, and outputs detailed statistical summaries for each group.

## Features
- Computes descriptive statistics:
  - count, sum, mean, median
  - minimum and maximum
  - standard deviation
  - percentiles
- Filters datasets based on criteria to create comparison groups
- Performs two-sample analysis between groups
- Generates 95% confidence intervals using bootstrap resampling
- Works with real-world datasets (CSV/TSV format)
- Includes both public and custom unit tests

## How to Run
Compile the program:
```bash
g++ stats.cpp library.cpp two_sample.cpp -o two_sample
```
Run with default dataset:
```bash
./two_sample
```
Run with custom dataset:
```bash
./two_sample <filename> <filter_column> <groupA> <groupB> <data_column>
```
Example:
```bash
./two_sample HCMST_ver_3.04.tsv q24_met_online 1 0 ppage

```

## Concepts Used
- Vectors and data processing
- Modular programming and abstraction
- Statistical computation (mean, stdev, percentiles)
- Bootstrap resampling for confidence intervals
- File input and parsing
- Unit testing with assertions
- Algorithmic problem solving

## Program Structure
- `stats.cpp`: Implementation of statistical functions
- `stats.hpp`: Function declarations for statistics library
- `two_sample.cpp`: Main analysis program
- `library.cpp` / `library.hpp`: Provided helper functions (data handling and resampling)
- `stats_tests.cpp`: Custom unit tests
- `stats_public_tests.cpp`: Instructor-provided tests

## Example Output
The program outputs statistics for two groups and a confidence interval comparison:

Group A:
- count, mean, stdev, median, percentiles, etc.

Group B:
- same statistics for comparison group

Confidence interval:
95% [lower_bound, upper_bound]
