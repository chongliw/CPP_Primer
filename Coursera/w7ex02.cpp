//
// Created by Chongli Wang on 10/28/15.
//

#include <iostream>

using std::cout;
using std::endl;

class MyDouble {
public:
    MyDouble(double __val) : val(__val) { }

    void print(bool scientific = false) const {
        if (!scientific) {
            print(precision, val);
        }
        else {
            double my_val = val;
            int deg = 0;
            while (my_val < 1) {
                my_val *= 10.0;
                --deg;
            }
            while (my_val >= 10) {
                my_val /= 10.0;
                ++deg;
            }
            print(sci_precision, my_val);
            cout << "e" << ((deg < 0) ? "-" : "+") << abs(deg);
        }
    }

private:
    double val;

    void print(int __pres, double my_val) const {
        int major = static_cast<int>(my_val);
        cout << major << ".";
        my_val -= major;
        for (int i = 0; i < __pres; ++i) {
            my_val *= 10.0;
            major = static_cast<int>(my_val);
            cout << major;
            my_val -= major;
        }
    }

    static const int precision = 5;
    static const int sci_precision = 7;
};

int main() {
    double test = 13889;
    MyDouble num(test);
    num.print(1);
    cout << endl;
}