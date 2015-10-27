//
// Created by Chongli Wang on 10/20/15.
//
#include <iostream>
using std::cout;
using std::endl;

class Complex1 {
public:
    friend bool operator==(const Complex1&, const Complex1&);
    friend std::ostream& operator<<(std::ostream&, const Complex1&);
    friend Complex1 operator-(const Complex1&);

    Complex1(int x = 0, int y = 0): re(x), im(y) {};
    Complex1(const Complex1 &c) {
        re = c.re;
        im = c.im;
        cout << "copy constructor called" << endl;
    }

    Complex1& operator+=(const Complex1&);
    Complex1& operator-=(const Complex1&);
    Complex1& operator*=(const Complex1&);

private:
    int re;
    int im;
};

inline bool operator==(const Complex1 &z1, const Complex1 &z2) {
    return (z1.re == z2.re && z1.im == z2.im);
}

inline bool operator!=(const Complex1 &z1, const Complex1 &z2) {
    return !(z1 == z2);
}

inline Complex1& Complex1::operator+=(const Complex1 &rhs) {
    re += rhs.re;
    im += rhs.im;
    return *this;
}

inline Complex1 operator+(const Complex1 &z1, const Complex1 &z2) {
    Complex1 result(z1);
    result += z2;
    return result;
}

inline Complex1 operator-(const Complex1 &lhs) {
    return Complex1(-lhs.re, -lhs.im);
}

inline Complex1& Complex1::operator-=(const Complex1 &rhs) {
    Complex1 neg_rhs = -rhs;
    *this += neg_rhs;
    return *this;
}

inline Complex1 operator-(const Complex1 &lhs, const Complex1 &rhs) {
    Complex1 result(lhs);
    result -= rhs;
    return result;
}

inline std::ostream& operator<<(std::ostream &os, const Complex1 &z) {
    if (!z.im) os << z.re;
    else {
        if (!z.re) os << (z.im == 1? "": std::to_string(z.im)) << 'i';
        else {
            if (z.im > 0) os << z.re << "+" << (z.im == 1? "" : std::to_string(z.im))<< 'i';
            else os << z.re << (z.im == 1? "" : std::to_string(z.im)) << 'i';
        }
    }
    return os;
}

inline Complex1& Complex1::operator*=(const Complex1 &rhs) {
    int temp_re = re;
    re = re * rhs.re - im * rhs.im;
    im = temp_re * rhs.im + im * rhs.re;
    return *this;
}

inline Complex1 operator*(const Complex1 &lhs, const Complex1 &rhs) {
    Complex1 result(lhs);
    result *= rhs;
    return result;
}

Complex1 test_call(Complex1 z1) {
    return z1;
}

int main() {
    Complex1 z1(1, 1);
    Complex1 z2(2, 3);
    cout << "cool";
    cout << "nice";
    cout << 1 + z1 << endl;
}
