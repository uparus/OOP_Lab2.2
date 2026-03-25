#ifndef STATISTIC_H
#define STATISTIC_H
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

class Statistic
{
private:
    vector<int> sales;
public:
    Statistic(vector<int> const& a);
    Statistic(int * a, size_t n);
    Statistic(string a);
    Statistic() = default;

    Statistic getSlice(const size_t start, const size_t finish) const;
    void deleteSlice(const size_t start, const size_t finish);
    vector<int> getSales() const;

    Statistic& operator +=(Statistic const& v);
    const int operator [] (const size_t) const;
    int& operator [] (const size_t index);

    long long sum_sales() const;
    int average_sales() const;

    int months_sales_below_average() const;
    int months_sales_above_average() const;

    vector<int> max_sales() const;
    vector<int> min_sales() const;

    void printArray() const;

    ~Statistic() {}
};

bool operator ==(Statistic const& t, Statistic const& other);
bool operator !=(Statistic const& t, Statistic const& other);
#endif