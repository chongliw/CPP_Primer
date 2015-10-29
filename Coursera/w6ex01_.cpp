//
// Created by Chongli Wang on 10/28/15.
//

#include <iostream>

using namespace std;

class A {
private:
    int nVal;
public:
    void Fun() const { cout << "A::Fun" << endl; }

    void Do() const{ cout << "A::Do" << endl; }
};

class B : public A {
public:
    virtual void Do() const { cout << "B::Do" << endl; }
};

class C : public B {
public:
    void Do() const { cout << "C::Do" << endl; }

    void Fun() const { cout << "C::Fun" << endl; }
};

void Call(const B &p) {
    p.Fun();
    p.Do();
}

int main() {
    C c;
    Call(c);
    return 0;
}

//Output
//A::Fun
//C::Do