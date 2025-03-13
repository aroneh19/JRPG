#ifndef ASSASSIN_H
#define ASSASSIN_H


#include "../base/Character.h"

class Assassin : public Character
{
public:
    Assassin(std::string name);

    // Override methods
    void useSkill(Character &target) override;
    void displaySkills() const override;
};

#endif // ASSASSIN_H