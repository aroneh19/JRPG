#ifndef BERSERKER_H
#define BERSERKER_H

#include "../base/Character.h"

class Berserker : public Character {
public:
    Berserker(std::string name);

    // Override methods
    void useSkill(Character& target) override;
    void displaySkills() const override;
};

#endif // BERSERKER_H