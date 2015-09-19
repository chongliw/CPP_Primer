//
// Created by Chongli Wang on 9/17/15.
//

#include "ch04.h"
#include <iostream>
#include <vector>
using namespace std;
void ch0401() {
//    ex 4.2
//    vector<int> vint{0, 10, 20};
//    cout << *(vint.begin()) + 1 << endl;
//    cout << *(vint.begin() + 1) << endl;
//    cout << *vint.begin() + 1 << endl; // 1

//    cout << 21 / (-5) << " " << 21 % -5 << endl;
//    cout << -30 / 3 * 21 % 4 << endl;

//    ex4.6
//    int n;
//    cin >> n;
//    string test;
//    test = (n % 2)? "odd": "even";
//    cout << test << endl;

//    ex4.9
//    const char *ch{"Hello world!"};
//    const char *ch1{""};
//    if (ch1)
//        cout << "test " << ch1 << endl;
}

void ch0404() {
//    int a[10];
//    a = {}; // error, only okay for initialization
//    for(int num: a)
//        cout << num << endl;

    int q = 10;
    int *p = &q;
    cout << sizeof(*p) << endl;
}
