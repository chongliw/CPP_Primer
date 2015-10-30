//
// Created by Chongli Wang on 10/30/15.
//

#include <iostream>
#include <string>
#include <list>

using namespace std;

template<typename _Tp>
class MyLarge {
public:
    bool operator()(const _Tp &lhs, const _Tp &rhs) const {
        return lhs.get_name() < rhs.get_name();
    }
};

class A {
private:
    string name;
public:
    A(string n) : name(n) { }

    friend bool operator<(const A &a1, const A &a2);

    friend bool operator==(const A &a1, const A &a2) {
        return a1.name.size() == a2.name.size();
    }

    friend ostream &operator<<(ostream &o, const A &a);

    string get_name() const {
        return name;
    }

    int get_size() const {
        return name.size();
    }
};

bool operator<(const A &a1, const A &a2) {
    return a1.name.size() < a2.name.size();
}

ostream &operator<<(ostream &os, const A &rhs) {
    os << rhs.name << " ";
    return os;
}

template<typename _It, typename _Op>
void Show(_It begin, _It end, _Op op) {
    for (; begin != end; ++begin) {
        op(*begin);
    }
};

template <typename _Tp>
class Print {
public:
    void operator()(const _Tp &rhs) {
        cout << rhs;
    }
};

int main(int argc, char *argv[]) {
    list<A> lst;
    int ncase, n, i = 1;
    string s;
    cin >> ncase;
    while (ncase--) {
        cout << "Case: " << i++ << endl;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s;
            lst.push_back(A(s));
        }
        lst.sort();
        Show(lst.begin(), lst.end(), Print<A>());

        cout << endl;
        lst.sort(MyLarge<A>());
        Show(lst.begin(), lst.end(), Print<A>());
        cout << endl;
        lst.clear();
    }
    return 0;
}