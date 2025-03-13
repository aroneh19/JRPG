#ifndef HEALER_H
#define HEALER_H

#include "../base/Character.h"

class Healer : public Character
{
public:
    Healer(std::string name);

    // Override methods
    void useSkill(Character &target) override;
    void displaySkills() const override;
};

#endif // Healer_H