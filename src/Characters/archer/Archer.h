#ifndef ARCHER_H
#define ARCHER_H

#include "../base/Character.h"

class Archer : public Character
{
private:
    int skillCooldown; // Cooldown tracker for Snipe Shot

public:
    Archer(std::string name);
    void attack(Character &target) override;
    void useSkill(Character &target) override;
    void focus() override;
    void displaySkills() const override;

    void reduceCooldown();
    bool isSkillReady() const;
};

#endif // ARCHER_H