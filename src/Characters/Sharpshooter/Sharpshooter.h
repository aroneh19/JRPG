#ifndef SHARPSHOOTER_H
#define SHARPSHOOTER_H

#include "../Base/Character.h"

class Sharpshooter : public Character {
public:
    Sharpshooter(std::string name);

    void attack(Character& target) override;
    void useSkill(Character& target) override;
    void focus() override;
    void displaySkills() const override;
};

#endif // SHARPSHOOTER_H
