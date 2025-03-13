#ifndef PALADIN_H
#define PALADIN_H

#include "../Base/Character.h"

class Paladin : public Character {
public:
    Paladin(std::string name);

    void attack(Character& target) override;
    void useSkill(Character& target) override;
    void focus() override;
    void displaySkills() const override;
};

#endif // PALADIN_H
