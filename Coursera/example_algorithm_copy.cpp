//
// Created by Chongli Wang on 10/28/15.
//

#include <iostream>
#include <iterator>
#include <vector>
#include <set>

using namespace std;

int main() {
    int a[] = {8, 7, 8, 9, 6, 2, 1};
// 在此处补充你的代码
    set<int> v(a, a + sizeof(a) / sizeof(int));
    ostream_iterator<int> o(cout, " ");
    copy(v.begin(), v.end(), o);
    return 0;
}

// 1 2 6 7 8 9