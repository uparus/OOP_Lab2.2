#include <iostream>
#include "source.h"
#include "exceptions.h"
#include "statistic.h"
#include "slicedStatisticSource.h"

Exceptions exceptionForSlicedSt;
int optionsSlicedMenu() {
    cout << "Menu:\n"
    << "1 - find sum of all sales\n"
    << "2 - find average sales\n"
    << "3 - find months where sales were below average\n"
    << "4 - find months where sales were above average\n"
    << "5 - find sales with maximum price\n"
    << "6 - find sales with minimum price\n"
    << "0 - back" << endl;

    int n;
    while (true) {
        cin >> n;
        if (exceptionForSlicedSt.incorrectDataType()) continue;
        if (exceptionForSlicedSt.indexOutOfRange(n,6,0)) continue;
        break;
    }

    return n;
}
void slicedStatistic(Statistic& statistic) {
    enum options{SUM = 1,AVERAGE = 2, BELOW_AVERAGE = 3, ABOVE_AVERAGE = 4, SALES_MAX = 5, SALES_MIN = 6, EXIT = 0};
    int n;
    do {
        cout << "Current array: ";
        statistic.printArray();
        n = optionsSlicedMenu();
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
        }

    }while (n != 0);
}
