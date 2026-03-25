#include <iostream>
#include <vector>
#include "statistic.h"
#include "source.h"
#include "slicedStatisticSource.h"
#include "statisticSource.h"
using namespace std;

int main() {
    vector<int>array = initArray();
    Statistic statistic(array);
    Statistic sliced_statistic;
    bool isSliceExists = false;

    int choice = 1;
    while (choice != 0) {
        if (isSliceExists) {
            cout << "1 - manage overall statistic\n2 - manage statistic for this period: ";
            sliced_statistic.printArray();
            cout << "3 - delete periodic statistic\n0 - exit\n";
            cin >> choice;
        }
        enum options{OVERALL_STATISTIC = 1, SLICED_STATISTIC = 2,DELETE_SLICE = 3};
        switch (choice) {
            case OVERALL_STATISTIC:
                mainStatistic(statistic,isSliceExists,sliced_statistic);
                break;
            case SLICED_STATISTIC:
                slicedStatistic(sliced_statistic);
                break;
            case options::DELETE_SLICE: {
                cout << "Statistic deleted\n";

                break;
            }
        }
    }


    return 0;
}