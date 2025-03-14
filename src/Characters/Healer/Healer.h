#ifndef HEALER_H
#define HEALER_H

#include "../Base/Character.h"

class Healer : public Character
{
private:
    int skillCooldown;

public:
    Healer(std::string name);

    void attack(Character &target) override;
    void useSkill(Character &target) override;
    void focus() override;
    void displaySkills() const override;

    void reduceCooldown();
    bool isSkillReady() const;
};

#endif // HEALER_H
