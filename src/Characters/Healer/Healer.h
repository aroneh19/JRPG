#ifndef HEALER_H
#define HEALER_H

#include "../Base/Character.h"

class Healer : public Character {
public:
    Healer(std::string name);

    void attack(Character& target) override;
    void useSkill(Character& target) override;
    void focus() override;
    void displaySkills() const override;
};

#endif // HEALER_H
