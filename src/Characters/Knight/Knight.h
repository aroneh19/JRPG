#ifndef KNIGHT_H
#define KNIGHT_H

#include "../Base/Character.h"

class Knight : public Character
{
private:
    int skillCooldown; 

public:
    Knight(std::string name);

    void attack(Character &target) override;
    void useSkill(Character &target) override;
    void focus() override;
    void displaySkills() const override;

    void reduceCooldown();
    bool isSkillReady() const;
};

#endif 
