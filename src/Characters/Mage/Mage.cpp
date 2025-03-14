#include "Mage.h"
#include <iostream>

Mage::Mage(std::string name)
    : Character(name, 8, 18, 6, 12, 14, 10, false), skillCooldown(0) {}

void Mage::attack(Character &target)
{
    std::cout << name << " casts a magic missile at " << target.getName() << "!\n";
    Character::attack(target); // Use the base attack logic
}

void Mage::useSkill(Character &target)
{
    if (!isSkillReady())
    {
        std::cout << name << "'s Fireball is on cooldown for " << skillCooldown << " more turns!\n";
        return;
    }

    if (mp < 5)
    {
        std::cout << name << " does not have enough MP to use Fireball!\n";
        return;
    }

    // Deduct MP and apply cooldown
    mp -= 5;
    skillCooldown = 3;

    // Calculate damage (2x ATK)
    int damage = static_cast<int>(atk * 2.0);
    target.setHp(target.getHp() - damage);

    std::cout << name << " uses Fireball on " << target.getName() << ", dealing " << damage << " damage!\n";
}

void Mage::focus()
{
    mp += 4;
    std::cout << name << " channels mana and regains 4 MP!\n";
}

void Mage::displaySkills() const
{
    std::cout << name << "'s Skills:\n";
    std::cout << "1️⃣ Fireball (Cost: 5 MP, Cooldown: " << skillCooldown << " turns)\n";
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