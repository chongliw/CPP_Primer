//
// Created by Chongli Wang on 9/5/15.
//

#include "part1.h"
#include <iostream>
#include "Sales_item.h"

void text03_SumAllInput() {
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

void text01_iostream() {
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
}

void ex03() {
    std::cout << "Hello, World" << std::endl;
}

void ex04() {
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product is " << v1 * v2 << std::endl;
};

void ex05() {
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product is ";
    std::cout << v1 * v2;
    std::cout << std::endl;
}

void text02_comment() {
    /*Simple Main function
    Read two numbers and write their sum*/
    // this is a single line comment

    /*
     *
     * /* nesting is not allowed */
    // */ compilation error
};

void ex08() {
    std::cout << "/*" << std::endl;
    std::cout << "*/" << std::endl;
    // std::cout << /* "*/" */;
    std::cout << /* "*/" /*   "/*"  */ << std::endl;
    std::cout << "/* fdsf */" << std::endl;
};

void ex09() {
    int num = 50;
    int sum = 0;
    while (num <= 100) {
        sum += num;
        ++num;
    };
    std::cout << sum << std::endl;
};

void ex10() {
    int num = 10;
    while (num >= 0) {
        std::cout << num << std::endl;
        --num;
    };
}

void ex11() {
    int start = 0, end = 0;
    std::cin >> start >> end;
    while (start <= end) {
        std::cout << start << std::endl;
        ++start;
    };
}

void text04_count_same_number() {
    int value, curr;
    int cnt = 0;
    while (true) {
        std::cin >> value;
        if (cnt == 0) {
            ++cnt;
            curr = value;
        }
        else {
            if (curr == value)
                ++cnt;
            else {
                std::cout << curr << " appears " << cnt << " times." << std::endl;
                cnt = 1;
                curr = value;
            }
        }
        if (value == -199)
            break;
    }
}

void text05_Sales_item() {
//    Sales_item book;
//    std::cin >> book;
//    std::cout << book << std::endl;
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    std::cout << item1 + item2 << std::endl;
    std::cout << item1.isbn() << std::endl;
}

void text06_Sales_memberfunction() {
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    if (item1.isbn() == item2.isbn()) {
        std::cout << item1 + item2 << std::endl;
    } else {
        std::cerr << "Error: Not the same ISBN!" << std::endl;
    }
}