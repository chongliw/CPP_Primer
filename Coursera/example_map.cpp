//
// Created by Chongli Wang on 10/27/15.
//

#include <iostream>
#include <map>
using std::cout;
using std::endl;
using std::map;
using std::multimap;
using std::make_pair;

int main() {
    multimap<int, int> dict;
    dict.insert(make_pair(0, 11));
    dict.insert(make_pair(0, 21));
    dict.insert(make_pair(1, 2));
    dict.insert(make_pair(2, 2));
    dict.insert(make_pair(3, 4));
    auto p = dict.equal_range(0);
    auto begin = p.first;
    auto end = p.second;
    for (; begin != end; ++begin)
        cout << begin->second << endl;

    map<int, int, std::less<double>> mp;
    mp.insert(make_pair(2.5, 2));
    cout << mp[9] << endl;
    return 0;
}