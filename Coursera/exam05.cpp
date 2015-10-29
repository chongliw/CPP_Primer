//
// Created by Chongli Wang on 10/28/15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 在此处补充你的代码
class CMy_add {
public:
    CMy_add(int &__total) : total(__total) {}
    void operator()(int val) {
        total += val & ((1 << 3) - 1);
    }

private:
    int &total;
};

int main(int argc, char *argv[]) {
    int v, my_sum = 0;
    vector<int> vec;
    cin >> v;
    while (v) {
        vec.push_back(v);
        cin >> v;
    }
//    auto CMy_add = [&](int &_1, int val){ _1 += val * val;};
    for_each(vec.begin(), vec.end(), CMy_add(my_sum));
    cout << my_sum << endl;
    return 0;
}