#include "Mage.h"
#include <iostream>

Mage::Mage(std::string name)
    : Character(name, 8, 18, 6, 12, 14, 10, false) {}

void Mage::attack(Character &target)
{
    std::cout << name << " casts a magic missile at " << target.getName() << "!\n";
    Character::attack(target);
}

void Mage::useSkill(Character &target)
{
    std::cout << name << " uses Fireball on " << target.getName() << "!\n";
}

void Mage::focus()
{
    mp += 4;
    std::cout << name << " channels mana and regains 3 MP!\n";
}

void Mage::displaySkills() const
{
    std::cout << name << "'s Skills: 1️⃣ Fireball\n";
}

void Mage::reduceCooldown()
{
    if (skillCooldown > 0)
    {
        skillCooldown--;
    }
}

bool Mage::isSkillReady() const
{
    return skillCooldown == 0;
}
