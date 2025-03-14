#ifndef MONK_H
#define MONK_H

#include "../Base/Character.h"

class Monk : public Character
{
private:
    int skillCooldown;

public:
    Monk(std::string name);

    void attack(Character &target) override;
    void useSkill(Character &target) override;
    void focus() override;
    void displaySkills() const override;

    void reduceCooldown();
    bool isSkillReady() const;
};

#endif 
