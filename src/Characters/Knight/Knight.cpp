#include "Knight.h"
#include <iostream>

Knight::Knight(std::string name)
    : Character(name, 14, 14, 14, 12, 10, 10, true), skillCooldown(0) {}

void Knight::attack(Character &target)
{
    std::cout << name << " slashes " << target.getName() << " with a longsword!\n";
    Character::attack(target); // Use the base attack logic
}

void Knight::useSkill(Character &target)
{
    if (!isSkillReady())
    {
        std::cout << name << "'s Royal Spear is on cooldown for " << skillCooldown << " more turns!\n";
        return;
    }

    if (mp < 5)
    {
        std::cout << name << " does not have enough MP to use Royal Spear!\n";
        return;
    }

    // Deduct MP and apply cooldown
    mp -= 5;
    skillCooldown = 4;

    // Calculate damage (ignores DEF, but damage is halved)
    int damage = static_cast<int>(atk * 0.5); // Halved damage
    target.setHp(target.getHp() - damage);

    std::cout << name << " uses Royal Spear on " << target.getName() << ", dealing " << damage << " piercing damage! (Ignores DEF)\n";
}

void Knight::focus()
{
    mp += 4;
    std::cout << name << " steadies their stance and regains 4 MP!\n";
}

void Knight::displaySkills() const
{
    std::cout << name << "'s Skills:\n";
    std::cout << "1️⃣ Royal Spear (Cost: 5 MP, Cooldown: " << skillCooldown << " turns)\n";
}

void Knight::reduceCooldown()
{
    if (skillCooldown > 0)
    {
        skillCooldown--;
    }
}

bool Knight::isSkillReady() const
{
    return skillCooldown == 0;
}