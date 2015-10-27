//
// Created by Chongli Wang on 10/26/15.
//

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Creature {
protected:
    int nPower;
    int nLifeValue;
public:
    virtual void attack(Creature *p) = 0;
    virtual void hurted(int _nPower) = 0;
    virtual void fight_back(Creature *p) = 0;
};

class Dragon : public Creature {
public:
    void attack(Creature *p);
    void hurted(int _nPower);
    void fight_back(Creature *p);
};

void Dragon::attack(Creature *p) {
    p->hurted(nPower);
    p->fight_back(this);
}

void Dragon::hurted(int _nPower) {
    nLifeValue -= _nPower;
}

void Dragon::fight_back(Creature *p) {
    p->hurted(nPower / 2);
}

int main() {
    return 0;
}
