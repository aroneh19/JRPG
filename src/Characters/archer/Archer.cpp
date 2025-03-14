#include "Archer.h"
#include <iostream>

Archer::Archer(std::string name)
    : Character(name, 12, 18, 8, 14, 10, 12, false) {}

void Archer::attack(Character &target)
{
    std::cout << name << " shoots an arrow at " << target.getName() << "!\n";
}

void Archer::useSkill(Character &target)
{
    std::cout << name << " uses Snipe Shot to hit " << target.getName() << " for massive damage!\n";
}

void Archer::focus()
{
    mp += 4;
    std::cout << name << " takes a deep breath and regains 3 MP!\n";
}

void Archer::displaySkills() const
{
    std::cout << name << "'s Skills: 1️⃣ Snipe Shot\n";
}
