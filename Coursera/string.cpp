//
// Created by Chongli Wang on 10/25/15.
//
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

class String {
public:
    String(): str(nullptr) {}
    String(const char *_str) {
        str = new char[strlen(_str) + 1];
        strcpy(str, _str);
    }
    String& operator=(const String&);
    ~String() {
        delete[] str;
        cout << "destructor called" << endl;
    };
    const char *get_str() {return str;}
private:
    char *str;
};

String& String::operator=(const String &s) {
    if (str)
        delete []str;
    if (s.str) {
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }
    else
        str = nullptr;
    return *this;
}

int main() {
    String s;
    s = "good";
    cout << s.get_str() << endl;
    s = s;
    cout << s.get_str() << endl;
    return 0;
}