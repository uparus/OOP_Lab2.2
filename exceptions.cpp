#include <iostream>
#include <limits>
#include "exceptions.h"
using namespace std;



bool Exceptions::indexOutOfRange(int n,int upperBound, int lowerBound) {
    if (n > upperBound || n < lowerBound){
        cout << "Number is out of bounds!\nEnter number between " << lowerBound << " and " << upperBound << endl;
        return true;
    }
    return false;
}

bool Exceptions::incorrectDataType() {
    if (!cin) {
        cout << "Wrond data type!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return true;
    }
    return false;
}
