#ifndef KNIGHT_H
#define KNIGHT_H

#include "../base/Character.h"

class Knight : public Character
{
public:
    Knight(std::string name);

    // Override methods
    void useSkill(Character &target) override;
    void displaySkills() const override;
};

#endif // Knight_H