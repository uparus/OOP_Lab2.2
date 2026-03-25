#include<iostream>
#include <cstdlib>
#include <ctime>
#include "source.h"
#include "exceptions.h"
#include "statistic.h"
using namespace std;

vector<int> initArray() {
    srand(time(NULL));
    int sizeMin = 5;
    int sizeMax = 12;
    int size = rand() % (sizeMax - sizeMin + 1); //Generating array size between 5 and 12

    vector<int>array(size);
    int maxValue = 10000;
    for (int i = 0; i < size; i++) {
        array[i] = rand() % maxValue; // generating statistic with max value = 100000
    }
    return array;
}
void printArray(vector<int>const& array) {
    for (auto i : array) {
        cout << i << " ";
    }
    cout << endl;
}


