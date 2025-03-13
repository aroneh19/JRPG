#ifndef MONK_H
#define MONK_H

#include "../base/Character.h"

class Monk : public Character
{
public:
    Monk(std::string name);

    // Override methods
    void useSkill(Character &target) override;
    void displaySkills() const override;
};

#endif // Monk_H