#ifndef STATISTIC_H
#define STATISTIC_H
#include <iostream>
#include <vector>
using namespace std;

class Statistics
{
private:
    vector<int> sales;
public:
    Statistics(vector<int> const& a); 
    Statistics() = default;

    long long sum_sales() const;
    int average_sales() const;

    int months_sales_below_average() const;
    int months_sales_above_average() const;

    vector<int> max_sales() const;
    vector<int> min_sales() const;

    void printArray() const;

    ~Statistics() {}
};

#endif