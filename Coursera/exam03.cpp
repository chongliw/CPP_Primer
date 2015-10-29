//
// Created by Chongli Wang on 10/28/15.
//

#include <iostream>

using namespace std;

template<typename _Tp, typename _Binary_Op>
_Tp sum(_Tp *arr, _Tp sz, _Binary_Op func) {
    _Tp total = 0;
    for (_Tp i = 0; i < sz; ++i) {
        total += func(arr[i]);
    }
    return total;
}

int sqr(int n) {
    return n * n;
}

int main() {
    int t, n, a[0x100];
    cin >> t;
    for (int c = 0; c < t; ++c) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << sum(a, n, sqr) << endl;
    }
    return 0;
}