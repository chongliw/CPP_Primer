//
// Created by Chongli Wang on 10/27/15.
//

#include <iostream>

using std::cout;
using std::endl;

int main() {
    int m, n;
    std::cin >> m >> n;
    try {
        if (!n) throw 2;
        double quot = static_cast<double>(m) / n;
        cout << quot << endl;
    }
    catch(int) {
        std::cerr << "error!" << endl;
    }
    cout << "end" << endl;
    return 0;
}