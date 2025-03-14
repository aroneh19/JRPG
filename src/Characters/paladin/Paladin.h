#ifndef PALADIN_H
#define PALADIN_H

#include "../Base/Character.h"

class Paladin : public Character
{
private:
    int skillCooldown; // Cooldown tracker for Divine Shield

public:
    Paladin(std::string name);

    void attack(Character &target) override;
    void useSkill(Character &target) override;
    void focus() override;
    void displaySkills() const override;

    void reduceCooldown();
    bool isSkillReady() const;
};

#endif // PALADIN_H
