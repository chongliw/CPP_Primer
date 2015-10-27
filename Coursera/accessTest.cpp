//
// Created by Chongli Wang on 10/26/15.
//

#include <iostream>

using std::cout;
using std::endl;

class Base {
public:
    int _public = 0;
private:
    int _private = 0;
protected:
    int _protected = 0;
};

class Derived: private Base {
public:
    void access() {
        _public = 1;
        // _private = 1;
        _protected = 2;
        cout << _protected << endl;
        Base b;
        // b._protected = 1;
    }
};

int main() {
    Base b;
    b._public = 2;
    Derived c;
    c.access();
    return 0;
}