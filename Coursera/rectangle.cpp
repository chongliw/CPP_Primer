//
// Created by Chongli Wang on 10/25/15.
//

#include <iostream>
using std::cout;
using std::endl;

class Rectangle {
public:
    Rectangle() : Rectangle(0, 0) {};
    Rectangle(int _w, int _h) : w(_w), h(_h){
        cout << "Constructor called" << endl;
        totalArea += _w * _h;
        ++totalNumber;
    }
    ~Rectangle() {
        cout << "Destructor called" << endl;
        --totalNumber;
    }
    static void printSummary() {
        cout << "total area " << totalArea << endl;
        cout << "total number " << totalNumber << endl;
    }


private:
    int w  = 0, h = 0;
    static int totalArea, totalNumber;
};

int Rectangle::totalArea = 0, Rectangle::totalNumber = 0;


int main() {
    Rectangle r1(1, 3);
    Rectangle r2;
    r2.printSummary();
    return 0;
}