#include <iostream>
#include <vector>
#include "statistic.h"
using namespace std;


long long Statistics::sum_sales() const {
    long long sum = 0;
    for (auto i : sales) {
        sum += i;
    }
    return sum;
}
int Statistics::average_sales() const {return static_cast<int>(sum_sales() / sales.size());}

int Statistics::months_sales_below_average() const {
    int average = average_sales();
    int count = 0;
    for (int i = 0; i < sales.size(); i++) {
        if (sales[i] < average) count++;
    }
    return count;
}
int Statistics::months_sales_above_average() const{
    int average = average_sales();
    int count = 0;
    for (int i = 0; i < sales.size(); i++) {
        if (sales[i] > average) count++;
    }
    return count;
}

vector<int> Statistics::max_sales() const {
    vector<int> maxSale;
    int maxValue = sales[0];
    for (int i = 1; i < sales.size(); i++) {
        if (maxValue < sales[i]) maxValue = sales[i];
    }

    for (int i = 0; i < sales.size(); i++) {
        if (maxValue == sales[i]) maxSale.push_back(i);
    }

    return maxSale;
}
vector<int> Statistics::min_sales() const {
    vector<int> minSales;
    int minValue = sales[0];
    for (int i = 1; i < sales.size(); i++) {
        if (minValue > sales[i]) minValue = sales[i];
    }
    for (int i = 0; i < sales.size();i++) {
        if (minValue == sales[i]) minSales.push_back(i);
    }
    return minSales;
}

void Statistics::printArray() const {
    cout << "Current array: ";
    for (auto i : sales) {
        cout << i << " ";
    }
    cout << endl;
}
