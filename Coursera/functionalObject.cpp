//
// Created by Chongli Wang on 10/27/15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

template <typename _InputIt, typename _Tp, typename _BinaryOp>
_Tp accum(_InputIt __first, _InputIt __last, _Tp __init, _BinaryOp __binary_op) {
    for (; __first != __last; ++__first) {
        __init = __binary_op(__init, *__first);
    }
    return __init;
};

template <typename _Tp>
_Tp sumSquare(_Tp total, _Tp value) {
    return total + value * value;
}

template <typename T>
class SumPowers {
public:
    SumPowers(int __power = 1) : power(__power) {};
    const T operator()(const T &total, const T &value) {
        T v = value;
        for (int i = 0; i < power - 1; ++i)
            v *= value;
        return total + v;
    }
private:
    int power = 1;
};

class Compare {
public:
    Compare(size_t __n = 10) : n(__n) {};
    bool operator()(int lhs, int rhs) {
        return lhs % n < rhs % n || (lhs % n == rhs % n && lhs < rhs);
    }
private:
    size_t n;
};

int main() {
    int n = 10;
    vector<int> nums;
    for (int i = n; i >= 1; --i)
        nums.push_back(i * i);
    cout << sumSquare(2, 1);
    int result2 = accum(nums.begin(), nums.end(), 0, sumSquare<int>);
    // has to specify sumSquare<int>, sumSquare wont work
    int result3 = accum(nums.begin(), nums.end(), 0, SumPowers<int>(2));
    cout << result2 << result3 << endl;
    stable_sort(nums.begin(), nums.end(), Compare(7));
    for (int num: nums)
        cout << num << " ";
    cout << endl;
    return 0;
}