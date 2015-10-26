//
// Created by Chongli Wang on 10/23/15.
//

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class StudentInfo {
public:
    StudentInfo(string nm, int ag, string id, int g1, int g2, int g3, int g4) :
            name(nm), age(ag), studentID(id), grade1(g1), grade2(g2), grade3(g3), grade4(g4) {};
    string get_name() const {return name;};
    int get_age() const {return age;};
    string get_studentID() const {return studentID;};
    int get_avg_grade() const {return (grade1 + grade2 + grade3 + grade4) / 4;}
private:
    string name;
    int age;
    string studentID;
    int grade1, grade2, grade3, grade4;
};

std::ostream& operator<<(std::ostream& os, const StudentInfo& stu) {
    os << stu.get_name() << ',' << stu.get_age() << ',' << stu.get_studentID() << ',' << stu.get_avg_grade();
    return os;
}

int main() {
    string info;
    std::cin >> info;
    string name, studentID;
    int age, grade1, grade2, grade3, grade4;

    char ch = ',';
    size_t pos1 = info.find(ch, 0);
    name = info.substr(0, pos1);

    size_t pos2 = info.find(ch, pos1 + 1);
    age = stoi(info.substr(pos1 + 1, pos2));

    size_t pos3 = info.find(ch, pos2 + 1);
    studentID = info.substr(pos2 + 1, pos3 - pos2 - 1);

    size_t pos4 = info.find(ch, pos3 + 1);
    grade1 = stoi(info.substr(pos3 + 1, pos4 - pos3 - 1));

    size_t pos5 = info.find(ch, pos4 + 1);
    grade2 = stoi(info.substr(pos4 + 1, pos5 - pos4 - 1));

    size_t pos6 = info.find(ch, pos5 + 1);
    grade3 = stoi(info.substr(pos5 + 1, pos6 - pos5 - 1));

    size_t pos7 = info.find(ch, pos6 + 1);
    grade4 = stoi(info.substr(pos6 + 1, pos7 - pos6 - 1));

    StudentInfo s1(name, age, studentID, grade1, grade2, grade3, grade4);
    cout << s1;
    return 0;
}