//
// Created by Chongli Wang on 10/28/15.
//

#include<iostream>

using namespace std;

class Number {
    friend Number operator*(const Number&, const Number&);
public:
    Number(int n = 0) : num(n) { }
    Number(const Number &rhs) {
        num = rhs.num;
    }
    Number &operator=(const Number &rhs) {
        num = rhs.num;
        return *this;
    }
    Number &operator*=(const Number &rhs) {
        num *= rhs.num;
        return *this;
    }
    operator int() const {return num;}
private:
    int num;
};

Number operator*(const Number &lhs, const Number &rhs) {
    Number tmp(lhs);
    tmp *= rhs;
    return tmp;
}

int main() {
    Number n1(10), n2(20);
    Number n3;
    n3 = n1 * n2;
    cout << int(n3) << endl;
    return 0;
}

//Ouput
//200