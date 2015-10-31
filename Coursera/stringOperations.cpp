//
// Created by Chongli Wang on 10/28/15.
//

#include <iostream>
#include <fstream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class MyStrings {
public:
    void add(const string &s) {
        strs.push_back(s);
    }
    void print(int index) {
        cout << strs[index - 1] << endl;
    }
    void printall() {
        for (auto str: strs)
            cout << str << endl;
    }
    size_t find(const string &s, int index) {
        size_t pos = strs[index - 1].find(s);
        return pos == string::npos? strs[index - 1].length() : pos;
    }
    size_t rfind(const string &s, int index) {
        size_t pos = strs[index - 1].rfind(s);
        return pos == string::npos? strs[index - 1].length() : pos;
    }
    string copy(int index, int pos, int length) {
        return strs[index - 1].substr(pos, length);
    }
    void reset(const string &s, int index) {
        strs[index - 1] = s;
    }
    void insert(const string &s, int index, int pos) {
        strs[index - 1].insert(pos, s);
    }
    string add(const string &s1, const string &s2) {
        const int maxn = 100000;
        int num1 = std::stoi(s1);
        int num2 = std::stoi(s2);
        if ((num1 < maxn && num1 >= 0 && num2 < maxn && num2 >=0) && (
                s1 == std::to_string(num1) && s2 == std::to_string(num2)))
            return std::to_string(num1 + num2);
        else
            return s1 + s2;
    }
private:
    vector<string> strs;
};

int main() {
    std::ifstream fin("Coursera/stringOperations.in");
    int num;
    fin >> num;
    MyStrings mystrs;
    while (num--) {
        string s;
        fin >> s;
        mystrs.add(s);
    }
    string cmd;
    std::map<string, vector<bool> > isString = {{"find", vector<bool>{1, 0}}, {"rfind", vector<bool>{1, 0}},
                                                {"copy", vector<bool>{0, 0, 0}}, {"reset", vector<bool>{1, 0}},
                                                {"insert", vector<bool>{1,0,0}}, {"add", vector<bool>{}},
                                                {"adds", vector<bool>{1, 1}}, {"addi", vector<bool>{0, 0}} };
    vector<int> positions;
    int index;
    std::stack<string> cmds;
    std::stack<int> intv;
    std::stack<string> stringv;
    while (cmd != "over") {
        fin >> cmd;
        if (cmd == "print") {
            fin >> index;
            mystrs.print(index);
        }
        else if (cmd == "printall") {
            mystrs.printall();
        }
        else if (isString.count(cmd)) {
            if (cmd != "add") {
                cmds.push(cmd);
                positions.push_back(0);
            }
            else {
                cmds.push("adds");
                positions.push_back(0);
            }
        }
        else {
            if (cmd != "over") {
                int pos = positions.back();
                string cm = cmds.top();
                if (!isString[cm][pos]) {
                    int val = std::stoi(cmd);
                    intv.push(val);
                }
                else {
                    stringv.push(cmd);
                }
                ++positions.back();
            }
        }
        while (!positions.empty() && positions.back() == isString[cmds.top()].size()) {
            string cm = cmds.top();
            cmds.pop();
            positions.pop_back();
            if (cm == "find") {
                int index = intv.top();
                intv.pop();
                string s = stringv.top();
                stringv.pop();
                int result = mystrs.find(s, index);
                intv.push(result);
                ++positions.back();
            }
            else if (cm == "rfind") {
                int index = intv.top();
                intv.pop();
                string s = stringv.top();
                stringv.pop();
                int result = mystrs.rfind(s, index);
                intv.push(result);
                ++positions.back();
            }
            else if (cm == "copy") {
                int length = intv.top();
                intv.pop();
                int pos = intv.top();
                intv.pop();
                int index = intv.top();
                intv.pop();
                string result = mystrs.copy(index, pos, length);
                stringv.push(result);
                ++positions.back();
            }
            else if (cm == "reset") {
                int index = intv.top();
                intv.pop();
                string s = stringv.top();
                stringv.pop();
                mystrs.reset(s, index);
            }
            else if (cm == "insert") {
                int pos = intv.top();
                intv.pop();
                int index = intv.top();
                intv.pop();
                string s = stringv.top();
                stringv.pop();
                mystrs.insert(s, index, pos);
            }
            else if (cm == "adds") {
                string s2 = stringv.top();
                stringv.pop();
                string s1 = stringv.top();
                stringv.pop();
                string result = mystrs.add(s1, s2);
                stringv.push(result);
                ++positions.back();
            }
        }
    }
    return 0;
}

//Output:
//Op29adfk48
//358
//329strjvc
//Op29adfk48
//35a8