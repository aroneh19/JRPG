#ifndef ARCHER_H
#define ARCHER_H

#include "../Base/Character.h"

class Archer : public Character
{
public:
    Archer(std::string name);
    void attack(Character &target) override;
    void useSkill(Character &target) override;
    void focus() override;
    void displaySkills() const override;
};

#endif // ARCHER_H
