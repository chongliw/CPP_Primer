//
// Created by Chongli Wang on 10/27/15.
//

#include <memory>
#include <iostream>

using std::cout;
using std::endl;
using std::shared_ptr;

class MyInt {
public:
    MyInt(int __val) : val(__val) {}
    ~MyInt() {cout << "~MyInt" << endl;}
    int val;
};

int main() {
    int n = 1, m = 12;
    shared_ptr<int> sp1(new int(10));
    cout << *sp1 << endl;
    shared_ptr<int> sp2(sp1);
    sp1.reset();

    shared_ptr<MyInt> p1(new MyInt(10));
    shared_ptr<MyInt> p2(p1);
    p1.reset(); // auto destructor called
    MyInt *p = new MyInt(20);
    p2.reset(p);
    cout << "------" << endl;
    p2.reset();
    cout << p->val << endl;
    cout << "______" << endl;
    return 0;
}