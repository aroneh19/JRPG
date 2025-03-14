#ifndef MAGE_H
#define MAGE_H

#include "../Base/Character.h"

class Mage : public Character
{
private:
    int skillCooldown; 

public:
    Mage(std::string name);

    void attack(Character &target) override;
    void useSkill(Character &target) override;
    void focus() override;
    void displaySkills() const override;

    void reduceCooldown();
    bool isSkillReady() const;
};

#endif
