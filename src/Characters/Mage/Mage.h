#ifndef MAGE_H
#define MAGE_H

#include "../Base/Character.h"

class Mage : public Character {
public:
    Mage(std::string name);

    void attack(Character& target) override;
    void useSkill(Character& target) override;
    void useSkill2(Character &target) override;
    void focus() override;
    void displaySkills() const override;
};

#endif // MAGE_H
