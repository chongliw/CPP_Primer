//
// Created by Chongli Wang on 10/27/15.
//

#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> my_vect{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v(my_vect.begin(), my_vect.begin() + 5);
    for (int num: v) cout << num << endl;
    std::random_shuffle(v.begin(), v.end());
    std::ostream_iterator<int> os(cout, "|");
    std::copy(v.begin(), v.end(), os);

    std::for_each(v.begin(), v.end(), [](int n){n = n + 1; cout << n << endl;});
    for (auto num: v) cout << num << endl;

    cout << std::accumulate(v.begin(), v.end(), 0, [](int total, int num){return total + num * num;}) << endl;
    cout << "---------------------" << endl;

    vector<int> newv{1, 2, 3, 2, 5};
    auto p = std::remove(newv.begin(), newv.end(), 2);
    std::copy(newv.begin(), newv.end(), os); cout << endl;
    cout << p - newv.begin() << endl;
    cout << "---------------------" << endl;

    while (std::next_permutation(newv.begin(), newv.end())) {
        std::copy(newv.begin(), newv.end(), os);
        cout << endl;
    }
    cout << "---------------------" << endl;
    std::map<int, int> mymap;
    mymap.insert({2, 3});
    cout << mymap[2] << endl;
    return 0;
}