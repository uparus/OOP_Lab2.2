#include<iostream>
#include "source.h"
#include "exceptions.h"
#include "statistic.h"
using namespace std;

Exceptions Exception;
Statistics Statistic;

int optionsMenu() {
    cout << "Menu:\n"
    << "1 - find sum of all sales\n"
    << "2 - find average sales\n"
    << "3 - find months where sales were below average\n"
    << "4 - find months where sales were above average\n"
    << "5 - find sales with maximum price\n"
    << "6 - find sales with minimum price\n"
    << "0 - exit" << endl;

    int n;
    while (true) {
        cin >> n;
        if (Exception.incorrectDataType()) continue;
        if (Exception.indexOutOfRange(n,6,0)) continue;
        break;
    }

    return n;
}

void printArray(vector<int>const& array) {
    for (auto i : array) {
        cout << i << " ";
    }
    cout << endl;
}

