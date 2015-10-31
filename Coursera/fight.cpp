//
// Created by Chongli Wang on 10/30/15.
//

#include <iostream>
#include <map>

using std::cout;
using std::endl;


int main() {
    int num;
    std::cin >> num;
    std::map<int, int> members{{1000000, 1}};
    while (num--) {
        int id, power;
        std::cin >> id >> power;
        auto it1 = members.lower_bound(power);
        if (it1 == members.begin())
            cout << id << " " << it1->second << endl;
        else {
            auto it2 = it1--;
            int diff1 = abs(it1->first - power);
            int diff2 = abs(it2->first - power);
            if (diff1 <= diff2)
                cout << id << " " << it1->second << endl;
            else
                cout << id << " " << it2->second << endl;
        }
        members.insert({power, id});
    }
    return 0;
}