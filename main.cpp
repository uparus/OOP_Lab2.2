#include <iostream>
#include <vector>
#include "statistic.h"
#include "exceptions.h"
#include "source.h"
using namespace std;

int main() {
    Exceptions Exception;

    int size;
    while (true) {
        cout << "\nEnter initial size of data array (max: 20)\n";
        cin >> size;

        if (Exception.incorrectDataType()) continue;
        if (Exception.indexOutOfRange(size,20,1)) continue;
        break;
    }

    cout << "Enter initial selling data\n";
    vector<int> array(size);
    for (int i = 0; i < size; i++) {
        while (true) {
            cin >> array[i];
            if (Exception.incorrectDataType()) continue;
            if (Exception.indexOutOfRange(array[i], 1000,0)) continue;
            break;
        }       
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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