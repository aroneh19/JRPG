#include "Assassin.h"
#include <iostream>

Assassin::Assassin(std::string name)
    : Character(name, 8, 18, 8, 16, 8, 16, false, "Assassin"), skillCooldown(0) {}

void Assassin::attack(Character &target)
{
    std::cout << name << " swiftly slashes " << target.getName() << "!\n";
    Character::attack(target); 
}

void Assassin::useSkill(Character &target)
{
    if (!isSkillReady())
    {
        std::cout << name << "'s Shadow Strike is on cooldown for " << skillCooldown << " more turns!\n";
        return;
    }

    if (mp < 5)
    {
        std::cout << name << " does not have enough MP to use Shadow Strike!\n";
        return;
    }

    mp -= 5;
    skillCooldown = 3;

    int damage = static_cast<int>(atk * 2.0);
    target.setHp(target.getHp() - damage);

    std::cout << name << " uses Shadow Strike on " << target.getName() << " for " << damage << " damage!\n";
}

void Assassin::focus()
{
    mp += 4;
    std::cout << name << " focuses in the shadows and gains 4 MP!\n";
}

void Assassin::displaySkills() const
{
    std::cout << name << "'s Skills:\n";
    std::cout << "1️⃣ Shadow Strike (Cost: 5 MP, Cooldown: " << skillCooldown << " turns)\n";
}

void Assassin::reduceCooldown()
{
    if (skillCooldown > 0)
    {
        skillCooldown--;
    }
}

bool Assassin::isSkillReady() const
{
    return skillCooldown == 0;
}