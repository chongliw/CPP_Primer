//
// Created by Chongli Wang on 10/30/15.
//

#include <iostream>
#include <map>

using namespace std;
class A {
public:
    static int count;
    A(int __val = 0) : val(__val){
        ++count;
    }
    virtual ~A() {
        cout << "A::destructor" << endl;
        --count;
    }
protected:
    int val;
};

class B : public A{
public:
    B(int __val = 0) : A(__val) {};
    B(const B &rhs) : B(rhs.val) {};
    ~B() {
        cout << "B::destructor" << endl;
    }
};
int A::count = 0;

void func(B b) { }

int main() {
    A a1(5), a2;
    cout << A::count << endl;
    B b1(4);
    cout << A::count << endl;
    func(b1);
    cout << A::count << endl;
    A *pa = new B(4);
    cout << A::count << endl;
    delete pa;
    cout << A::count << endl;
    return 0;
}

//Output:
//2
//3
//B::destructor
//A::destructor
//3
//4
//B::destructor
//A::destructor
//3
//B::destructor
//A::destructor
//A::destructor
//A::destructor