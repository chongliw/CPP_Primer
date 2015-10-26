//
// Created by Chongli Wang on 10/25/15.
//
#include <iostream>
using std::cout;
using std::endl;

class Int {
    friend std::ostream &operator<<(std::ostream&, Int);
public:
    Int(int _val = 0) : val(_val) {}

    Int &operator++() {
        ++val;
        return *this;
    }
    Int operator++(int) {
        Int tmp(*this);
        ++val;
        return tmp;
    }
    Int &operator--() {
        --val;
        return *this;
    }
    operator int() {return val;}
private:
    int val;
};

std::ostream &operator<<(std::ostream &os, Int rhs) {
    os << rhs.val;
    return os;
}

int main() {
    Int a(9);
    int b = (int) a;
    cout << ++a << endl;
    cout << b << endl;
    return 0;
}