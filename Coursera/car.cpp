//
// Created by Chongli Wang on 10/25/15.
//

#include <iostream>

using std::cout;
using std::endl;

class Tyre {
public:
    Tyre(int tr, int w) : radius(tr), width(w) {
        cout << "Constructor of Tyre class called" << endl;
    }

    ~Tyre() {
        cout << "Destructor of Tyre class called" << endl;
    }

private:
    int radius;
    int width;
};

class Engine {
};

class Car;
class Driver {
public:
    void modifyCar(Car *pCar);
};

class Car {
    friend int mostExpensiveCar(Car[], int);
    friend void Driver::modifyCar(Car *);

public:
    Car(int p, int tr, int w) : price(p), tyre(tr, w) { }

private:
    int price;
    Tyre tyre;
    Engine engine;
};


void Driver::modifyCar(Car *pCar) {
    pCar->price += 1000;
}

int mostExpensiveCar(Car cars[], int total) {
    int tmp = -1;
    for (int i = 0; i < total; ++i)
        if (cars[i].price > tmp)
            tmp = cars[i].price;
    return tmp;
}

int main() {
    Car my_car(20000, 17, 225);
    return 0;
}