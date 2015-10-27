//
// Created by Chongli Wang on 10/26/15.
//

#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

const double PI = 3.14159;

class Shape {
public:
    virtual double area() const = 0;
    virtual std::ostream &print(std::ostream&) const = 0;
    void _init() {
        ++nTotal;
        areaTotal += area();
    }
    static double areaTotal;
    static int nTotal;
};

double Shape::areaTotal = 0.0;
int Shape::nTotal = 0;

std::ostream &operator<<(std::ostream &os, const Shape &rhs) {
    return rhs.print(os);
}

class Rectangle : public Shape {
public:
    Rectangle(int _w, int _h) : w(_w), h(_h) {
        _init();
        ++nRectangle;
        areaRectangle += area();
    }
    double area() const;
    std::ostream &print(std::ostream&) const;
    static int nRectangle;
    static double areaRectangle;

private:
    int w, h;
};

int Rectangle::nRectangle = 0;
double Rectangle::areaRectangle = 0.0;

double Rectangle::area() const {
    return static_cast<double>(w * h);
}

std::ostream &Rectangle::print(std::ostream &os) const {
    os << "width = " << w << ", " << "height = " << h;
    return os;
}

class Circle : public Shape {
public:
    Circle(int _c, int _r) : c(_c), r(_r) {
        _init();
        ++nCircle;
        areaCircle += area();
    }
    static int nCircle;
    static double areaCircle;
    virtual double area() const;
    std::ostream &print(std::ostream&) const;
private:
    int c, r;
};

int Circle::nCircle = 0;
double Circle::areaCircle = 0.0;

double Circle::area () const {
    return PI * r * r;
}

std::ostream &Circle::print(std::ostream &os) const {
    os << "center = " << c << ", radius = " << r;
    return os;
}

class Triangle : public Shape {
public:
    Triangle(int _e1, int _e2, int _e3) : e1(_e1), e2(_e2), e3(_e3) {
        _init();
        ++nTriangle;
        areaTriangle += area();
    }
    static int nTriangle;
    static double areaTriangle;
    double area() const;
    std::ostream& print(std::ostream&) const;
private:
    int e1, e2, e3;
};

int Triangle::nTriangle = 0;
double Triangle::areaTriangle = 0.0;

double Triangle::area() const {
    double p = static_cast<double>(e1 + e2 + e3) / 2;
    return sqrt(p * (p - e1) * (p - e2) * (p - e3));
}

std::ostream &Triangle::print(std::ostream &os) const {
    os << "edge1 = " << e1 << ", edge2 = " << e2 << ", edge3 = " << e3;
    return os;
}

int main() {
    Rectangle r1(2, 4);
    cout << r1 << endl;
    Circle c1(0, 1);
    cout << c1 << endl;
    cout << Shape::nTotal << Shape::areaTotal << endl;
    cout << Rectangle::nRectangle << Rectangle::areaRectangle << endl;
    cout << Circle::nCircle << Circle::areaCircle << endl;
    Triangle t1(1, 1, 1);
    cout << Triangle::nTriangle << Triangle::areaTriangle << endl;
    Shape &p = t1;
    cout << p << endl;
}