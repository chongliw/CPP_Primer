//
// Created by Chongli Wang on 10/30/15.
//

#include <iostream>
#include <string>
#include <list>
#include <map>

using std::cout;
using std::string;
using std::endl;

class My_lists {
public:
    void newl(int key) {
        lists[key] = std::list<int>(0);
    }
    void add(int key, int value) {
        lists[key].push_back(value);
    }
    void out(int key) {
        for (auto begin = lists[key].begin(); begin != lists[key].end(); ++begin) {
            cout << *begin << " ";
        }
        cout << endl;
    }
    void merge(int key1, int key2) {
        lists[key1].insert(lists[key1].end(), lists[key2].begin(), lists[key2].end());
        lists[key1].sort();
        lists[key2] = std::list<int>(0);
    }

    void unique(int key) {
        lists[key].unique();
    }
private:
    std::map<int, std::list<int>> lists;
};
int main() {
    int num;
    std::cin >> num;
    My_lists data;
    for (int i = 0; i < num; ++i) {
        string cmd;
        std::cin >> cmd;
        if (cmd == "new") {
            int key;
            std::cin >> key;
            data.newl(key);
        }
        else if (cmd == "add") {
            int key, value;
            std::cin >> key >> value;
            data.add(key, value);
        }
        else if (cmd == "out") {
            int key;
            std::cin >> key;
            data.out(key);
        }
        else if (cmd == "merge") {
            int key1, key2;
            std::cin >> key1 >> key2;
            data.merge(key1, key2);
        }
        else if (cmd == "unique") {
            int key;
            std::cin >> key;
            data.unique(key);
        }
    }
    return 0;
}
//Input:
//16
//new 1
//new 2
//add 1 1
//add 1 2
//add 1 3
//add 2 1
//add 2 2
//add 2 3
//add 2 4
//out 1
//out 2
//merge 1 2
//out 1
//out 2
//unique 1
//out 1
//Output:
//1 2 3
//1 2 3 4
//1 1 2 2 3 3 4
//
//1 2 3 4