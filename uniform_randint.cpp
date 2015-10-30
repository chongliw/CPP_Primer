//
// Created by Chongli Wang on 10/30/15.
//

#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <cmath>

int main() {
    std::srand(time(NULL));
    int nExperiment = 10000;
    int nSample = 10000;
    double pr = 0.1;
    double sd = sqrt(pr * (1 - pr) * nSample);
    int total = 0;
    for (int j = 0; j < nExperiment; ++j) {
        std::vector<int> p(10);
        for (int i = 0; i < nSample; ++i) {
            ++p[rand() % 10];
        }
        if (p[0] < pr * nSample  + 2 * sd &&  p[0] > pr * nSample - 2 * sd)
            ++total;
    }
    std::cout << double(total) / nExperiment;
    return 0;
}

