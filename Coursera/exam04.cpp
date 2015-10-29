//
// Created by Chongli Wang on 10/28/15.
//

#include <iostream>

using namespace std;

class CType {
    friend ostream &operator<<(ostream&, const CType&);
public:
    void setvalue(int __val) {
        val = __val;
    }
    CType operator++(int){
        CType tmp(*this);
        val *= val;
        return tmp;
    }
private:
    int val;
};

ostream &operator<<(ostream &os, const CType &rhs) {
    os << rhs.val;
    return os;
}

// 在此处补充你的代码
int main(int argc, char *argv[]) {
    CType obj;
    int n;
    cin >> n;
    while (n) {
        obj.setvalue(n);
        cout << obj++ << " " << obj << endl;
        cin >> n;
    }
    return 0;
}

//Input:
//1 5 8 9 0
//Output:
//1 1
//5 25
//8 64
//9 81