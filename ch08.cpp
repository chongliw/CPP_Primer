//
// Created by Chongli Wang on 9/18/15.
//

#include "ch08.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

istream& test(istream& is) {
    int i;
    int sum = 0;
    while(is >> i)
        sum += i;
    return is;
}

void ex08_01() {
    int i, sum = 0;
    while (cin >> i)
        sum += i;
    cout << sum << endl;

    istream& is = test(cin);
    cout << is.rdstate() << endl; // try input: 1 output: 0, input: s output: 4
}

void text08_tie() {
    ostream *oldtie = cin.tie(nullptr);
    cin.tie(&cerr);
    cout << "cool";
    int i;
    cin >> i;
    cin.tie(oldtie);
}

void text08_fstream(char *argv1, char *argv2) {
//    ex04
    ifstream input(argv1);
    ofstream output(argv2);
    string str;
    vector<string> lines;
    while (getline(input, str))
        lines.push_back(str);
    for (string line: lines)
        output << line << endl;
    input.close();
    output.close();

//    ex05
    vector<string> lines1;
    input.open(argv1);
    output.open(argv2, ofstream::app);
    while(input >> str)
        lines1.push_back(str);
    for(string str: lines1)
        output << str << endl;
}

struct PhoneNum {
    string name;
    vector<string> nums;
};
void text08_stringstream(char *argv1, char *argv2) {
    ifstream input(argv1);
    ofstream output(argv2);
    string line;
    vector<PhoneNum> phone_nums;
    while(getline(input, line)) {
        istringstream input_person(line);
        PhoneNum phones;
        input_person >> phones.name;
        string num;
        while(input_person >> num)
            phones.nums.push_back(num);
        phone_nums.push_back(phones);
    }
    input.close();
    for(const auto &phones: phone_nums) {
        ostringstream person;
        person << phones.name << ": ";
        for(const auto &phone: phones.nums)
            person << phone << ", ";
        output << person.str() << endl;
    }
    output.close();
}
