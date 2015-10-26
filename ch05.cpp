//
// Created by Chongli Wang on 9/18/15.
//

#include "ch05.h"
#include <iostream>
using namespace std;

void ch05_null() {
    int i;
    int sought = 100;;  // inserting a null statement
    while(cin >> i && i != sought)
        ;   // null statement

    int j = 1, k = 2;
    i = (j, k); // comma operator
    cout << (++j, k++) << endl;
}

