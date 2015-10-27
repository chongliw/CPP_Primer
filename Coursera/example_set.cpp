//
// Created by Chongli Wang on 10/27/15.
//

#include <iostream>
#include <set>
#include <vector>

using std::set;
using std::pair;
using std::cout;
using std::endl;
using std::make_pair;
using std::string;
using std::vector;

class my_compare {
public:
    bool operator()(pair<int, int> lhs, pair<int, int> rhs) {
        return (lhs.first) * (lhs.first) + (lhs.second) * (lhs.second) < (rhs.first) * (rhs.first) + (rhs.second) * (rhs.second);
    }
};


int main() {
    set<pair<int, int>, my_compare> my_set;
    my_set.insert(make_pair(2, 4));
    my_set.insert(make_pair(1, 5));
    for (auto begin = my_set.begin(); begin != my_set.end(); ++begin)
        cout << begin->first << begin->second << endl;
    const char *a = "this";
    char *b = const_cast<char*>(a);
    cout << b << endl;

    vector<int> ls{1, 3, 3, 2, 5, 6, 7};
    std::multiset<int> mp(ls.begin(), ls.end());
    for (auto num: mp) cout << num << endl;
    cout << *mp.lower_bound(4) << endl;
    cout << *mp.upper_bound(4) << endl;
    return 0;
}