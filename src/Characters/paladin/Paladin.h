#ifndef PALADIN_H
#define PALADIN_H

#include "../base/Character.h"

class Paladin : public Character
{
public:
    Paladin(std::string name);

    // Override methods
    void useSkill(Character &target) override;
    void displaySkills() const override;
};

#endif // Paladin_H