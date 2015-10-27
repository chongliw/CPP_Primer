//
// Created by Chongli Wang on 10/27/15.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::set;

class Student {
public:
    Student(string __name, int __id, int __score) : name(__name), id(__id), score(__score) {}
    string name;
    int id;
    int score;
};

bool operator<(const Student &lhs, const Student &rhs) {
    return lhs.score < rhs.score || (lhs.score == rhs.score && lhs.id < rhs.id);
}

std::ostream &operator<<(std::ostream &os, const Student &rhs) {
    os << rhs.name << " " << rhs.id << " " <<  rhs.score;
    return os;
}


int main() {
    std::ifstream fin;
    fin.open("Coursera/student_score.in");
    string cmd;
    map<int, set<Student>> score_to_student;
    while (fin >> cmd) {
        if (cmd == "Add") {
            string name;
            int id, score;
            fin >> name >> id >> score;
            Student stu(name, id, score);
            score_to_student[score].insert(stu);
        }
        else if (cmd == "Query") {
            int score;
            fin >> score;
            auto it = score_to_student.lower_bound(score);
            if (it->first == score)
                cout << *(it->second.rbegin()) << endl;
            else {
                if (it == score_to_student.begin())
                    cout << "Nobody" << endl;
                else {
                    it--;
                    cout << *(it->second.rbegin()) << endl;
                }
            }
        }
    }
    fin.close();
    return 0;
}