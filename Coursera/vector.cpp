//
// Created by Chongli Wang on 10/25/15.
//

#include <iostream>

using std::cout;
using std::endl;

class Vector {
    friend std::ostream &operator<<(std::ostream&, const Vector&);
public:
    Vector(int _size = 0) : ptr(nullptr), size(_size), capacity(_size * 2) {
        if (capacity)
            ptr = new int[capacity];
    }

    Vector(const Vector &);
    ~Vector() {
        if (ptr) delete []ptr;
        cout << "destrctor called" << endl;
    }

    Vector &operator=(const Vector &);
    int &operator[](int);

    void push_back(int);
    int length() const;

private:
    int *ptr;
    int size = 0;
    int capacity = 0;
    void resize(int);
};

int& Vector::operator[](int index) {
    if (index < size && index >= 0)
        return ptr[index];
    else
        return ptr[size - 1]; // out of range return the last element;
}

Vector::Vector(const Vector &rhs) : size(rhs.size), capacity(rhs.capacity) {
    ptr = new int[capacity];
    memcpy(ptr, rhs.ptr, sizeof(int) * rhs.size);
}

int Vector::length() const {
    return size;
}

void Vector::push_back(int val) {
    if (size >= capacity) {
        Vector tmp(*this);
        resize(2 * (capacity + 1));
        memcpy(ptr, tmp.ptr, sizeof(int) * tmp.size);
    }
    ptr[size++] = val;
}

Vector &Vector::operator=(const Vector &rhs) {
    if (!rhs.ptr) {
        delete []ptr;
        size = 0;
        capacity = 0;
        ptr = nullptr;
    }
    else {
        size = rhs.length();
        if (capacity < size)
            resize(size * 2);
        memcpy(ptr, rhs.ptr, sizeof(int) * rhs.size);
    }
    return *this;
}

void Vector::resize(int _capacity) {
    capacity = _capacity;
    delete []ptr;
    ptr = new int[capacity];
}

std::ostream &operator<<(std::ostream &os, const Vector &rhs) {
    int sz = rhs.size, *ptr = rhs.ptr;
    for (int i = 0; i != sz; ++i)
        os << ptr[i] << " ";
    return os;
}

int main() {
    Vector a;
    cout << a.length() << endl;
    for (int i = 0; i < 5; ++i)
        a.push_back(i);
    Vector a2, a3;
    a2 = a;
    a[1] = 2;
    cout << a2.length() << a[6] << endl;
    cout << a << endl;
    cout << a2 << endl;
    return 0;
}