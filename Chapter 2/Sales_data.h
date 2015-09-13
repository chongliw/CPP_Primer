//
// Created by Chongli Wang on 9/13/15.
//

#ifndef CPP_PRIMER_SALES_DATA_H
#define CPP_PRIMER_SALES_DATA_H

#include <string>
using namespace std;

struct Sales_data {
    string bookNO;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif //CPP_PRIMER_SALES_DATA_H
