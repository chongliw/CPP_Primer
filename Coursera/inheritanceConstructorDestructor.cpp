//
// Created by Chongli Wang on 10/26/15.
//

#include <iostream>

using std::cout;
using std::endl;

class Base {
public:
    Base() {
        cout << "c from Base" << endl;
        hello();
    }
    virtual ~Base() {
        cout << "d from Base" << endl;
        bye();
    }
    virtual void hello() const {
        cout << "hello from Base" << endl;
    };
    virtual void bye() const {
        cout << "bye from Base" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "c from Derived" << endl;
        hello();
    }
    ~Derived() {
        cout << "d from Derived" << endl;
        bye();
    }
    void hello() const {
        cout << "hello from Derived" << endl;
    }
    void bye() const {
        cout << "bye from Derived" << endl;
    }
};

class MoreDerived : public Derived {
public:
    MoreDerived() {
        cout << "c from MoreDerived" << endl;
        hello();
    }
    ~MoreDerived() {
        cout << "d from MoreDerived" << endl;
        bye();
    }
};

int main() {
    MoreDerived md;
    cout << "----" << endl;
    Derived *pd;
    pd = &md;
    pd->hello();
    cout << "-----------" << endl;
    Base *derPtr = new Derived;
    delete derPtr;
    cout << "~~~~~~~~~~~" << endl;
    return 0;
}