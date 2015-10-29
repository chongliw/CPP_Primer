//
// Created by Chongli Wang on 10/28/15.
//

#include <iostream>
#include <string>

using namespace std;

template<typename _Tp>
class CMyistream_iterator : public iterator<input_iterator_tag, _Tp> {
public:
    CMyistream_iterator(istream &__is) : is(__is) {
        is >> __value;
    }

    CMyistream_iterator &operator++(int) {
        is >> __value;
        return *this;
    }

    _Tp operator*() {
        return __value;
    }

private:
    _Tp __value;
    istream &is;
};

// 在此处补充你的代码
int main() {
    CMyistream_iterator<int> inputInt(cin);
    int n1, n2, n3;
    n1 = *inputInt; //读入 n1
    int tmp = *inputInt;
    cout << tmp << endl;
    inputInt++;
    n2 = *inputInt; //读入 n2
    inputInt++;
    n3 = *inputInt; //读入 n3
    cout << n1 << "," << n2 << "," << n3 << endl;
    CMyistream_iterator<string> inputStr(cin);
    string s1, s2;
    s1 = *inputStr;
    inputStr++;
    s2 = *inputStr;
    cout << s1 << "," << s2 << endl;
    return 0;
}
