//
// Created by Chongli Wang on 10/26/15.
//

#include <iostream>
using std::cout;
using std::endl;

class Base {
public:
    Base(int _i, int _j) : i(_i), j(_j) {}
    virtual void print() {
        cout << i << " " << j << " ";
    }
private:
    int i, j;
};
class Derived : public Base {
public:
    Derived(const Base &_b, int _k) : Base(_b), k(_k) {}
    void print() {
        Base::print();
        cout << k << " ";
    }

private:
    int k;
};

int main() {
    Base b(1, 2);
    Derived d(b, 3);
    b.print();
    cout << endl;
    d.print();
    cout << endl;
    Base b1 = d;
    b1.print();
    cout << endl;
    Base *pd = &d;
    pd->print();
    Derived *pd1  = &d;
    pd1->print();
    // Derived d2 = b;
    return 0;
}