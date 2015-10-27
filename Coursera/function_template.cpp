//
// Created by Chongli Wang on 10/26/15.
//

#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

template <typename T>
T find_max(vector<T> arr) {
    using It = typename vector<T>::const_iterator;
    bool isInit = false;
    T tmp_max;
    for (It it = arr.begin(); it != arr.end(); ++it) {
        if (!isInit) {
            tmp_max = *it;
            isInit = true;
        }
        else
            if (*it > tmp_max)
                tmp_max = *it;
    }
    return tmp_max;
}

int main() {
    vector<string> strs{"abbc", "ddee", "ffff"};
    cout << find_max(strs) << endl;
    vector<int> ints{10, 9, 2, 1131};
    cout << find_max(ints) << endl;
    return 0;
}