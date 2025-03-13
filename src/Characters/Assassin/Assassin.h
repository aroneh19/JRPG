#ifndef ASSASSIN_H
#define ASSASSIN_H

#include "../Base/Character.h"

class Assassin : public Character {
public:
    Assassin(std::string name);

    void attack(Character& target) override;
    void useSkill(Character& target) override;
    void focus() override;
    void displaySkills() const override;
};

#endif // ASSASSIN_H
