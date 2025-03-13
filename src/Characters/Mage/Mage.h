#ifndef MAGE_H
#define MAGE_H

#include "../base/Character.h"

class Mage : public Character
{
public:
    Mage(std::string name);

    // Override methods
    void useSkill(Character &target) override;
    void displaySkills() const override;
};

#endif // Mage_H