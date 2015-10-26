//
// Created by Chongli Wang on 10/25/15.
//

#include <iostream>
#include <string>

using namespace std;

class Array2 {
public:
    Array2(int _rowN = 0, int _colN = 0) : rowN(_rowN), colN(_colN) {
        ptr = new int*[rowN];
        for (int i = 0; i < rowN; ++i) {
            ptr[i] = new int[colN];
        }
    }
    ~Array2() {
        for (int i = 0; i < rowN; ++i) {
            delete []ptr[i];
        }
        delete []ptr;
    }

    int* operator[](int rowIndex) {
        return ptr[rowIndex];
    }


    Array2 &operator=(const Array2 &rhs) {
        this->~Array2();
        rowN = rhs.rowN;
        colN = rhs.colN;
        ptr = new int* [rowN];
        for (int i = 0; i < rowN; ++i) {
            ptr[i] = new int [colN];
        }
        for (int i = 0; i < rowN; ++i)
            for (int j = 0; j < colN; ++j)
                ptr[i][j] = rhs.ptr[i][j];
        return *this;
    }

    int& operator()(int i, int j) {
        return ptr[i][j];
    }



private:
    int rowN, colN;
    int** ptr;
};

int main() {
    Array2 a(3, 4);
    int i, j;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 4; j++)
            a[i][j] = i * 4 + j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; j++) {
            cout << a(i, j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;
    b = a;
    b(0, 0) = 2;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; j++) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; j++) {
            cout << a(i, j) << ",";
        }
        cout << endl;
    }
    return 0;
}

