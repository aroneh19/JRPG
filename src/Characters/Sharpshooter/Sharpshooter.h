#ifndef SHARPSHOOTER_H
#define SHARPSHOOTER_H

#include "../base/Character.h"

class Sharpshooter : public Character
{
public:
    Sharpshooter(std::string name);

    // Override methods
    void useSkill(Character &target) override;
    void displaySkills() const override;
};

#endif // Sharpshooter_H