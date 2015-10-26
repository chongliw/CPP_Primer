//
// Created by Chongli Wang on 10/23/15.
//

#include <iostream>
using namespace std;
class Base {
public:
    int k;
    Base(int n):k(n) { }
};
class Big {
public:
    int v; Base b;
    Big(const Big &data) : b(data.b), v(data.b.k) {}
    Big(int n) : v(n), b(n) {}

};
int main() {
    Big a1(5); Big a2 = a1;
    cout << a1.v << "," << a1.b.k << endl;
    cout << a2.v << "," << a2.b.k << endl;
    return 0;
}