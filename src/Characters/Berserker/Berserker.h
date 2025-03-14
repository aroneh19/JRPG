#ifndef BERSERKER_H
#define BERSERKER_H

#include "../Base/Character.h"

class Berserker : public Character
{
private:
    int skillCooldown; // Cooldown tracker for Rage

public:
    Berserker(std::string name);

    void attack(Character &target) override;
    void useSkill(Character &target) override;
    void focus() override;
    void displaySkills() const override;

    void reduceCooldown();
    bool isSkillReady() const;
};

#endif // BERSERKER_H
