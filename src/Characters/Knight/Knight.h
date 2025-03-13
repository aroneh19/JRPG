#ifndef KNIGHT_H
#define KNIGHT_H

#include "../Base/Character.h"

class Knight : public Character {
public:
    Knight(std::string name);

    void attack(Character& target) override;
    void useSkill(Character& target) override;
    void focus() override;
    void displaySkills() const override;
};

#endif // KNIGHT_H
