#include <iostream>
#include <vector>
#include "statistic.h"
#include <sstream>
using namespace std;

Statistic::Statistic(vector<int> const& a) : sales(a){}
Statistic::Statistic(int *a, size_t n) : sales(a,a+n){}
Statistic::Statistic(std::string a) {
        std::istringstream iss(a);
        int value;
        while (iss >> value) {
            sales.push_back(value);
        }
    }

Statistic Statistic::getSlice(const size_t start, const size_t finish) const {
    if (start > finish) throw invalid_argument("Invalid data format");
    if (sales.size() < start || finish > sales.size()) throw out_of_range("Index is out of range");

    return Statistic(vector<int>(sales.begin() + start - 1, sales.begin() + finish));
}
void Statistic::deleteSlice(const size_t start, const size_t finish) {
    if (start > finish) throw invalid_argument("Invalid data format");
    if (start < sales.size() || finish > sales.size()) throw out_of_range("Index is out of range");
    sales.erase(sales.begin() + start, sales.begin() + finish);
}
vector<int> Statistic::getSales() const {return sales;}

Statistic& Statistic::operator +=(Statistic const& v) {
    sales.insert(sales.end(), v.sales.begin(), v.sales.end());
    return *this;
}
const int Statistic::operator [] (const size_t index) const {
    return sales[index];
}
int& Statistic::operator [] (const size_t index) {
    if (index >= sales.size()) {
        throw out_of_range("index out of range");
    }
    return sales[index];
}

long long Statistic::sum_sales() const {
    long long sum = 0;
    for (auto i : sales) {
        sum += i;
    }
    return sum;
}
int Statistic::average_sales() const {return static_cast<int>(sum_sales() / sales.size());}

int Statistic::months_sales_below_average() const {
    int average = average_sales();
    int count = 0;
    for (int i = 0; i < sales.size(); i++) {
        if (sales[i] < average) count++;
    }
    return count;
}
int Statistic::months_sales_above_average() const{
    int average = average_sales();
    int count = 0;
    for (int i = 0; i < sales.size(); i++) {
        if (sales[i] > average) count++;
    }
    return count;
}

vector<int> Statistic::max_sales() const {
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
vector<int> Statistic::min_sales() const {
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

void Statistic::printArray() const {
    for (auto i : sales) {
        cout << i << " ";
    }
    cout << endl;
}

bool operator ==(Statistic const& t, Statistic const& other) {
    return (t.getSales() == other.getSales());
}
bool operator !=(Statistic const& t, Statistic const& other) {
    return !(t.getSales() == other.getSales());
}