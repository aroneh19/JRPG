#include "Healer.h"
#include <iostream>

Healer::Healer(std::string name)
    : Character(name, 16, 8, 14, 10, 18, 12, false) {}

void Healer::attack(Character &target)
{
    std::cout << name << " gently taps " << target.getName() << " for minor damage!\n";
}

void Healer::useSkill(Character &target)
{
    std::cout << name << " uses Healing Light on " << target.getName() << "!\n";
}

void Healer::focus()
{
    mp += 4;
    std::cout << name << " focuses and regains 3 MP!\n";
}

void Healer::displaySkills() const
{
    std::cout << name << "'s Skills: 1️⃣ Healing Light\n";
}

void Healer::reduceCooldown()
{
    if (skillCooldown > 0)
    {
        skillCooldown--;
    }
}

bool Healer::isSkillReady() const
{
    return skillCooldown == 0;
}
