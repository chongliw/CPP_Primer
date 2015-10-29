//
// Created by Chongli Wang on 10/28/15.
//

#include <iostream>
#include <string>
#include <set>
#include <map>

class MyMultiSet {
public:
    void add(int x) {
        my_set.insert(x);
        added.insert(x);
        std::cout << my_set.count(x) << std::endl;
    }

    void del(int x) {
        std::cout << my_set.count(x) << std::endl;
        my_set.erase(x);
    }

    void ask(int x) {
        std::cout << (added.find(x) != added.end()) << " " << my_set.count(x) << std::endl;
    }

private:
    std::multiset<int> my_set;
    std::set<int> added;
};

int main() {
    int n;
    std::cin >> n;
    MyMultiSet data;
    for (int i = 0; i < n; ++i) {
        std::string cmd;
        int val;
        std::cin >> cmd >> val;
        if (cmd == "add") data.add(val);
        else {
            if (cmd == "del") data.del(val);
            else if (cmd == "ask") data.ask(val);
        }
    }
    return 0;
}

//Input:
//7
//add 1
//add 1
//ask 1
//ask 2
//del 2
//del 1
//ask 1
//Output:
//1
//2
//1 2
//0 0
//0
//2
//1 0