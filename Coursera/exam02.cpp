//
// Created by Chongli Wang on 10/28/15.
//

#include <iostream>

using namespace std;

class Number {
public:
    Number(int n) : num(n) {}
    int &value() {return num;}
    void operator+(const Number &rhs) {
        num += rhs.num;
    }
// 在此处补充你的代码
private:
    int num;
};

int main() {
    Number a(2);
    Number b = a;
    cout << a.value() << endl;
    cout << b.value() << endl;
    a.value() = 8;
    cout << a.value() << endl;
    a + b;
    cout << a.value() << endl;
    return 0;
}

//Output
//2
//2
//8
//10