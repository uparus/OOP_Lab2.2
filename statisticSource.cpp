#include<iostream>
#include <cstdlib>
#include <ctime>
#include "source.h"
#include "exceptions.h"
#include "statistic.h"
#include "statisticSource.h"

Exceptions mainException;
int optionsMenu() {
    cout << "Menu:\n"
    << "1 - find sum of all sales\n"
    << "2 - find average sales\n"
    << "3 - find months where sales were below average\n"
    << "4 - find months where sales were above average\n"
    << "5 - find sales with maximum price\n"
    << "6 - find sales with minimum price\n"
    << "7 - get a statistic for a certain period\n"
    << "0 - back" << endl;

    int n;
    while (true) {
        cin >> n;
        if (mainException.incorrectDataType()) continue;
        if (mainException.indexOutOfRange(n,7,0)) continue;
        break;
    }

    return n;
}
void mainStatistic(Statistic& statistic, bool& isSliceExists,Statistic& sliced_statistic) {
    enum options{SUM = 1,AVERAGE = 2, BELOW_AVERAGE = 3, ABOVE_AVERAGE = 4, SALES_MAX = 5, SALES_MIN = 6, MAKE_SLICE = 7, EXIT = 0};
    int n;
    do {
        cout << "Current array: ";
        statistic.printArray();
        n = optionsMenu();
        switch (n) {
            case options::SUM: {
                long long sum = statistic.sum_sales();
                cout << "The sum of all sales: " << sum << endl;
                break;
            }
            case options::AVERAGE: {
                int average = statistic.average_sales();
                cout << "The average amount of sales: " << average << endl;
                break;
            }
            case options::BELOW_AVERAGE: {
                int count = statistic.months_sales_above_average();
                cout << "Months when sales were below average: " << count << endl;
                break;
            }
            case options::ABOVE_AVERAGE: {
                int count = statistic.months_sales_above_average();
                cout << "Months when sales were above average: " << count << endl;
                break;
            }
            case options::SALES_MAX: {
                vector<int>result;
                result = statistic.max_sales();
                cout << "Indexes of months with max sales: ";
                printArray(result);
                cout << "\n";
                break;
            }
            case options::SALES_MIN: {
                vector<int>result;
                result = statistic.min_sales();
                cout << "Indexes of months with min sales: ";
                printArray(result);
                cout << "\n";
                break;
            }
            case options::MAKE_SLICE: {
                cout << "In order to get a statistic for a certain period enter starter month and last month\n";
                size_t sliceStart, sliceEnd;
                cin >> sliceStart >> sliceEnd;
                try {
                    cout << "Statistic from chosen period: ";
                    sliced_statistic = statistic.getSlice(sliceStart, sliceEnd);
                    sliced_statistic.printArray();
                    isSliceExists = true;
                    n = 0;
                }catch (exception& e) {
                    cerr << e.what() << endl;
                }
                break;
            }
        }

    }while (n != 0);
}
