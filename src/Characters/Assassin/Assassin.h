#ifndef ASSASSIN_H
#define ASSASSIN_H

#include "../Base/Character.h"

class Assassin : public Character
{
private:
    int skillCooldown; // Cooldown tracker for Backstab

public:
    Assassin(std::string name);

    void attack(Character &target) override;
    void useSkill(Character &target) override;
    void focus() override;
    void displaySkills() const override;

    void reduceCooldown();
    bool isSkillReady() const;
};

#endif // ASSASSIN_H
