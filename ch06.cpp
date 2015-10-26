//
// Created by Chongli Wang on 9/21/15.
//

#include "ch06.h"
#include <iostream>

void my_swap(int *i, int *j);

using namespace std;

void ch06_test() {
    int n, sum;
    while (cin >> n)
        sum += n;
    cout << sum << endl;
}

void my_swap(int *i, int *j) {
    auto temp = *i;
    *i = *j;
    *j = temp;
}

void my_swap2(int &i, int &j) {
    int temp = j;
    j = i;
    i = temp;
}

void ch06_pass_by_ref() {
    int i, j;
    cin >> i >> j;
    my_swap(&i, &j);
    my_swap2(i, j);
    cout << i << j;
}

