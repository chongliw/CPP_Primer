//
// Created by Chongli Wang on 10/30/15.
//

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

template <typename _key, typename _val>
ostream & operator<<(ostream &os, const pair<_key, _val> &rhs) {
    os << "(" << rhs.first << "," << rhs.second << ")";
    return os;
};


template <typename _key, typename _val, typename _compare = greater<_key> >
class MyMultimap : public multimap<_key, _val, _compare> {
public:
//    MyMultimap() : multimap<_key, _val, _compare>() {};
//    MyMultimap(const multimap<_key, _val, _compare> &rhs) : multimap<_key, _val, _compare>(rhs) {};

    void Set(const _key &__key, _val __val) {
        auto begin = this->lower_bound(__key), end = this->upper_bound(__key);
        for (; begin != end; ++begin) {
            begin->second = __val;
        }
    }
};

struct Student {
    string name;
    int score;
};

template<class T>
void Print(T first, T last) {
    for (; first != last; ++first)
        cout << *first << ",";
    cout << endl;
}

int main() {
    Student s[] = {{"Tom",   80},
                   {"Jack",  70},
                   {"Jone",  90},
                   {"Tom",   70},
                   {"Alice", 100}};
    MyMultimap<string, int> mp;
    for (int i = 0; i < 5; ++i)
        mp.insert(make_pair(s[i].name, s[i].score));
    Print(mp.begin(), mp.end()); //按姓名从大到小输出

    mp.Set("Tom", 78); //把所有名为"Tom"的学生的成绩都设置为78
    Print(mp.begin(), mp.end());


    MyMultimap<int, string, less<int> > mp2;
    for (int i = 0; i < 5; ++i)
        mp2.insert(make_pair(s[i].score, s[i].name));

    Print(mp2.begin(), mp2.end()); //按成绩从小到大输出

    mp2.Set(70, "Error");          //把所有成绩为70的学生，名字都改为"Error"
    Print(mp2.begin(), mp2.end());
    cout << "******" << endl;

    mp.clear();

    string name;
    string cmd;
    int score;
    while (cmd != "end") {
        cin >> cmd;
        if (cmd == "A") {
            cin >> name >> score;
            if (mp.find(name) != mp.end()) {
                cout << "error" << endl;
            }
            mp.insert(make_pair(name, score));
        }
        else if (cmd == "Q") {
            cin >> name;
            MyMultimap<string, int>::iterator p = mp.find(name);
            if (p != mp.end()) {
                cout << p->second << endl;
            }
            else {
                cout << "Not Found" << endl;
            }
        }
    }
    return 0;
}

//Input:
//A Tom1 30
//A Tom2 40
//Q Tom3
//A Tom4 89
//Q Tom1
//Q Tom2
//Output:
//(Tom,80),(Tom,70),(Jone,90),(Jack,70),(Alice,100),
//(Tom,78),(Tom,78),(Jone,90),(Jack,70),(Alice,100),
//(70,Jack),(70,Tom),(80,Tom),(90,Jone),(100,Alice),
//(70,Error),(70,Error),(80,Tom),(90,Jone),(100,Alice),
//******
//Not Found
//30
//40