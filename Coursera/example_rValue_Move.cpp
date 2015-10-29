//
// Created by Chongli Wang on 10/27/15.
//

#include <iostream>
#include <string>

using std::cout;
using std::endl;

class String {
    friend std::ostream &operator<<(std::ostream&, const String&);
public:
    String(): str(nullptr) {}
    String(const char *__str) {
        cout << "ordinary constructor called" << endl;
        str = new char[strlen(__str) + 1];
        strcpy(str, __str);
    }
    String(const String &s) {
        cout << "ordinary copy constructor called" << endl;
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }
    String(String &&s) : str(s.str){
        cout << "move copy constructor called" << endl;
        s.str = new char[1];
        s.str[0] = 0;
    }

    String &operator=(const String &s) {
        delete []str;
        if (s.str) {
            str = new char[strlen(s.str) + 1];
            strcpy(str, s.str);
        }
        else
            str = nullptr;
        return *this;
    }

    String &operator=(String &&s) {
        cout << "Rvalue assignment called" << endl;
        delete []str;
        str = s.str;
        s.str = new char[1];
        s.str[0] = 0;
        return *this;
    }

    ~String() {
        delete []str;
    }

private:
    char *str;
};

std::ostream &operator<<(std::ostream &os, const String &rhs) {
    os << rhs.str << endl;
    return os;
}

template <typename _Tp>
void move_swap(_Tp &a, _Tp &b) {
    _Tp tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}
int main() {
    String s;
    cout << "______" << endl;
    s = String("This");
    cout << "______" << endl;
    String s1 = "hello", s2 = "world";
    cout << "______" << endl;
    move_swap(s1, s2);
    cout << "______" << endl;
    cout << s2 << endl;
    return 0;
}