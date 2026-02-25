#include <iostream>
#include <vector>
#include "statistic.h"
#include "exceptions.h"
#include "source.h"
using namespace std;

int main() {
    Exceptions Exception;

    cout << "Enter initial size of data array\n";
    int size;
    cin >> size;

    cout << "Enter initial selling data\n";
    vector<int> array(size);
    for (int i = 0; i < size; i++) {
        while (true) {
            cin >> array[i];
            if (Exception.incorrectDataType()) continue;
            break;
        }
    }
    Statistics Statistic(array);

    enum options{SUM = 1,AVERAGE = 2, BELOW_AVERAGE = 3, ABOVE_AVERAGE = 4, SALES_MAX = 5, SALES_MIN = 6, EXIT = 0};
    int n;
    do {
        Statistic.printArray();
        n = optionsMenu();
        switch (n) {
            case options::SUM: {
                long long sum = Statistic.sum_sales();
                cout << "The sum of all sales: " << sum << endl;
                break;
            }
            case options::AVERAGE: {
                int average = Statistic.average_sales();
                cout << "The average amount of sales: " << average << endl;
                break;
            }
            case options::BELOW_AVERAGE: {
                int count = Statistic.months_sales_above_average();
                cout << "Months when sales were below average: " << count << endl;
                break;
            }
            case options::ABOVE_AVERAGE: {
                int count = Statistic.months_sales_above_average();
                cout << "Months when sales were above average: " << count << endl;
                break;
            }
            case options::SALES_MAX: {
                vector<int>result;
                result = Statistic.max_sales();
                cout << "Indexes of months with max sales: ";
                printArray(result);
                cout << "\n";
                break;
            }
            case options::SALES_MIN: {
                vector<int>result;
                result = Statistic.min_sales();
                cout << "Indexes of months with min sales: ";
                printArray(result);
                cout << "\n";
                break;
            }
        }

    }while (n != 0);

    return 0;
}