//
// Created by Chongli Wang on 10/25/15.
//

#include <iostream>
#include <string>

using namespace std;

class Complex {
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    Complex(double _r = 0.0, double _i = 0.0) : r(_r), i(_i) {}
    Complex &operator=(string s) {
        size_t pos = s.find('+');
        r = stod(s.substr(0, pos));
        i = stod(s.substr(pos + 1));
        return *this;
    }

private:
    double r, i;
};

int main() {
    Complex a;
    a = "3.6+-4.2i";
    a.Print();
    a = "5.2+-6.4i";
    a.Print();
    return 0;
}