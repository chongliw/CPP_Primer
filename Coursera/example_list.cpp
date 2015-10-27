//
// Created by Chongli Wang on 10/26/15.
//

#include <iostream>
#include <list>
using std::list;
using std::cout;
using std::endl;

template <typename T1, typename T2>
class Pair;

template <typename T1, typename T2>
bool operator<(const Pair<T1, T2>&, const Pair<T1, T2>&);

template <typename T1, typename T2>
bool operator==(const Pair<T1, T2>&, const Pair<T1, T2>&);

template <typename T1, typename T2>
auto operator<<(std::ostream&, const Pair<T1, T2>&)->std::ostream&;

template <typename T1, typename T2>
class Pair {
    friend bool operator< <>(const Pair<T1, T2>&, const Pair<T1, T2>&);
    // add <> to make a specialization to be a friend
    friend bool operator== <>(const Pair<T1, T2>&, const Pair<T1, T2>&);
    friend auto operator<< <>(std::ostream&, const Pair<T1, T2>&)->std::ostream&;
public:
    Pair(const T1 &_v1, const T2 &_v2) : v1(_v1), v2(_v2) {}
private:
    T1 v1;
    T2 v2;
};

template <typename T1, typename T2>
bool operator<(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs) {
    return (lhs.v1 < rhs.v1) || (lhs.v1 == rhs.v1 && lhs.v2 < rhs.v2);
}

template <typename T1, typename T2>
bool operator==(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs) {
    return (lhs.v1 == rhs.v1 && lhs.v2 == rhs.v2);
}

template <typename T1, typename T2>
auto operator<<(std::ostream& os, const Pair<T1, T2> &rhs)->std::ostream& {
    os << "(" << rhs.v1 << ", " << rhs.v2 << ")";
    return os;
};


int main() {
    list<Pair<int, int>> data;
    using makePair = Pair<int, int>;
    data.push_back(makePair(0, 1));
    data.push_back(makePair(2, 2));
    data.push_back(makePair(0, 3));
    data.sort();
    for (auto it = data.begin(); it != data.end(); ++it)
        cout << *it << endl;
    return 0;
}