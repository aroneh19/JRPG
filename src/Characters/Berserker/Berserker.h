#ifndef BERSERKER_H
#define BERSERKER_H

#include "../Base/Character.h"

class Berserker : public Character {
public:
    Berserker(std::string name);

    void attack(Character& target) override;
    void useSkill(Character& target) override;
    void focus() override;
    void displaySkills() const override;
};

#endif // BERSERKER_H
