//
// Created by Chongli Wang on 10/25/15.
//

#include <iostream>
using namespace std;
class MyInt {
    int nVal;
public:
    MyInt(int n) { nVal = n; }
    int ReturnVal() { return nVal; }
    MyInt &operator-=(const MyInt &);
    MyInt &operator-(const MyInt &);
};

MyInt &MyInt::operator-=(const MyInt &rhs) {
    nVal -= rhs.nVal;
    return *this;
}

MyInt &MyInt::operator-(const MyInt & rhs) {
    *this -= rhs;
    return *this;
}

int main () {
    MyInt objInt(10);
    objInt-2-1-3;
    cout << objInt.ReturnVal();
    cout <<",";
    objInt-2-1;
    cout << objInt.ReturnVal();
    return 0;
}