//
// Created by Chongli Wang on 10/30/15.
//

#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;
class A {
public:
    A(int __age) : age(__age) {}
    friend bool operator<(const A &lhs, const A &rhs) {
        return lhs.age < rhs.age;
    }
    virtual void print() const {
        cout << "A " << age;
    }

protected:
    int age;
};

class B : public A {
public:
    B(int __age) : A(__age) {};
    void print() const {
        cout << "B " << age;
    }
};

class Comp {
public:
    bool operator()(const A *lhs, const A *rhs) const {
        const A l = *lhs;
        const A r = *rhs;
        return l < r;
    }
};

void Print(const A *lhs) {
    lhs->print();
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    set<A*, Comp> ct;
    while (t--) {
        int n;
        cin >> n;
        ct.clear();
        for (int i = 0; i < n; ++i) {
            char c;
            int k;
            cin >> c >> k;
            if (c == 'A')
                ct.insert(new A(k));
            else
                ct.insert(new B(k));
        }
        for_each(ct.begin(), ct.end(), Print);
        cout << "****" << endl;
    }
}