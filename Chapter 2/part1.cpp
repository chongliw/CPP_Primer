//
// Created by Chongli Wang on 9/10/15.
//

#include "part1.h"
#include "Sales_data.h"
void test() {
    cout << "this is a test" << std::endl;
}

void text01_type_conversion() {
//    bool b = 42;
//    cout << b << endl;
//    int i = b;
//    cout << i << endl;
//    i = 3.14;
//    cout << i << endl;
//    double pi = i;
//    cout << pi << endl;
//    unsigned char c = -2;
//    cout << c << endl;
//    signed char c2 = 256;
//    cout << c2 << endl;

//    unsigned u = 10;
//    int i = u;
//    cout << i << endl;
//    i = -11;
//    cout << u + i << endl;
///*
//    unsigned u1 = 10, u2 = 20;
//    cout << u1 - u2 << endl;
//    cout << u2 - u1 << endl;*/
//    unsigned u = 1;
//    int i = 10;
//    cout << u - i << endl;
//    cout << i - u << endl;

//    cout << 024 << endl;
//    cout << 0x1A << endl;
//    cout << 0X1A << endl;
//    cout << 3e-2 << endl;
//    cout << ('a' == "a") << endl;
//    cout << "oh\"" << endl;

//    ex 2.8
//    cout << "2M\n" << endl;
//    cout << "2\tM\n" << endl;
}

void text02_list_initialization() {
//    long double ld = 3.14159265358979;
//    int a{ld};
//    cout << a << endl;
//    int b = ld;
//    cout << b << endl;
//    int i;
//    cout << i << endl;

//    cin >> int input_value;
//    double salary = wage = 99.9;
}

void text03_identifiers() {
//    int __test;
//    __test = 0;  // bad form
//    int _Fuck;
//    _Fuck = 0;  //bad name
//    int Double = 10;
//    cout << Double << endl;
//    int _ = 10;
//    cout << _ << endl;
}

void text04_scope() {
//    int reused = 100;
//    for (int i=1; i<10; ++i) {
//        int reused = i;
//        cout << reused << endl;
//    }
//    cout << reused << endl;

//    ex14
//    int i = 100, sum = 0;
//    for (int i = 0; i < 10; ++i) {
//        sum += i;
//    }
//    cout << i << sum << endl;
}

void text05_pointer_and_reference() {
//    int i = 10;
//    double d = 2.9;
//    int &ri = i;
//    double &rd = d;
//    ri = d;
//    cout << ri << endl;

//    int i = 10;
//    int &ri = i;
//    int *p = &ri;
//    cout << p << endl;

//    int i = 1, *p = &i;
//    int *&rp = p;
//    *rp = 2;
//    cout << *p << endl;

//    int *p;
//    *p = 100;
//    cout << *p;

//    int i = 10;
//    void *p = &i;
//    cout << p << endl;
//    cout << *p << endl;
}

extern const double PI = 3.14;


void text06_const() {
//    int &i = 100; // error
//    const int &ci = 100;
//    cout << ci << endl;
//
//    const int c = 50;
//    int &ri = c; // error

//    double p = 30; // see what happens if you change double to int
//    const int &pi = p; // ok
//    p += 1;
//    cout << p << endl;
//    cout << pi << endl;

//    const int num = 100;
//    int *ptr = &num; // error
//    int new_num = 100;
//    const int *cptr = &new_num;
//    new_num = 99;
//    *cptr = 90; // error
//    cout << *cptr << endl;

//    double v = 3.45;
//    const double v1 = 3.22;
//    const double *ptr = &v1;
//    cout << ptr << endl;
//    ptr = &v;
//    cout << ptr << endl;

//    double test = 1.23;
//    double test1 = 2.34;
//    double *const pip = &test;
//    cout << *pip << endl;
//    *pip = 1.232;
//    cout << *pip << endl;
//    pip = &test1; // error

//    const int a = 3;
//    int *const ptr = &a; // error
//    const int *const ptr2 = &a; // ok
//    const int i = 10;
//    const int &const ri = i; // error
//    cout << ri << endl;
}

void text07_types() {
//    double test = 1.234;
//    constexpr double *ptr = &test; // error
//    constexpr double *ptr = 10.0; // error
//    const double v = 1.234;
//    constexpr double v2 = v + 1; // ok

//    typedef double my_double;
//    my_double cool = 8.90;
//    my_double *ptr = &cool;
//    auto kkk = *ptr;
//    cout << kkk << endl;
//    using my_double2 = my_double;
//    my_double *ptr2 = &kkk;
//    cout << ptr2 << " " << *ptr2 << endl;

//    const int b = 10;
//    auto a = b;
//    a = 11;
//    cout << a << endl;

//    int a = 10;
//    int e = 20;
//    cout << typeid(a).name() << endl;
//    auto *const b = &a;
//    const auto *c = &a;
//    const auto &d = a;
//    cout << typeid(b).name() << endl;
//    *b = 11;
//    *c = 12; // error
//    c = &e; // ok
//    cout << c << *c << endl;
//    d = 13; // error

//    int a = 10, &b = a;
//    decltype(b) c; // error
//    decltype(b) c = b;
//    c = 11;
//    cout << a << b << c << endl;
//    decltype(a) d = a;
//    d = 12;
//    cout << a << b << c << d << endl;
//    int *p = &a;
//    decltype(*p) ra = a;
//    ra = 8;
//    cout << ra << a << b << c << d << endl;
//    decltype((a)) ra1; // error
//    decltype((a)) ra1 = a; // ok
//    cout << ra1 << endl;

    // ex 2.37
//    int a = 3, b = 4;
//    decltype(a) c = a;
//    decltype(a = b) d = a; // d is of type int&
//    ++d;
//    cout << a << b << c << d;
}

void text08_own_data_str() {
    Sales_data data1, data2;
    double price = 0.0;
    cin >> data1.bookNO >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    cin >> data2.bookNO >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    if (data1.bookNO == data2.bookNO) {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRev = data1.revenue + data2.revenue;
        cout << "totalCnt: " << totalCnt << " totalRev: " << totalRev;
    } else {
        cerr << "ISBNs do not match!" << endl;
        exit(-1);
    }
}

void ex39() {
    struct Foo {
//        empty
    };
}

