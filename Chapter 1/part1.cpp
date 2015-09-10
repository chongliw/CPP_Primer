//
// Created by Chongli Wang on 9/5/15.
//

#include "part1.h"
#include <iostream>

void test1_totalsum() {
    // quit when entering value = -199
    int value = 0;
    int sum = 0;
    while (true) {
        std::cin >> value;
        if (value == -199)
            break;
        sum += value;
    };
    std::cout << sum << std::endl;
};

void test001_iostream() {
    std::cout << "Enter two numbers:" << std:: endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
}