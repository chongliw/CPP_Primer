//
// Created by Chongli Wang on 10/26/15.
//

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Student {
public:
    Student() = default;
    Student(const string &_name, const string &_id, char _gender, int _age) :
            name(_name), id(_id), gender(_gender), age(_age) {}

    virtual void printInfo() {
        cout << name << "," << id << "," << gender << "," << age;
    }
    void setInfo() {}
private:
    string id;
    char gender;
    int age;
protected:
    string name;
};

class UndergradStudent: public Student {
public:
    UndergradStudent(const string &_name, const string &_id, char _gender, int _age, const string &_department) :
            Student(_name, _id, _gender, _age), department(_department) {}
    UndergradStudent(const Student &stu, const string &_department) :
            Student(stu), department(_department) {}
    virtual void printInfo() {
        cout << name <<  "," << department;
    }
private:
    string department;
};


int main() {
    Student Tom("Tom", "19870404", 'M', 18);
    UndergradStudent Tom1(Tom, "Mathematics");
    Student *pTom = &Tom1;
    pTom->Student::printInfo();
    cout << endl;
    return 0;
}