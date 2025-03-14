#include "Berserker.h"
#include <iostream>

Berserker::Berserker(std::string name)
    : Character(name, 14, 18, 10, 12, 8, 10, true), skillCooldown(0) {}

void Berserker::attack(Character &target)
{
    std::cout << name << " swings their axe at " << target.getName() << "!\n";
    Character::attack(target); // Use the base attack logic
}

void Berserker::useSkill(Character &target)
{
    if (!isSkillReady())
    {
        std::cout << name << "'s Rage Strike is on cooldown for " << skillCooldown << " more turns!\n";
        return;
    }

    if (mp < 4)
    {
        std::cout << name << " does not have enough MP to use Rage Strike!\n";
        return;
    }

    // Deduct MP and apply cooldown
    mp -= 4;
    skillCooldown = 3;

    // Calculate damage (2x ATK)
    int damage = static_cast<int>(atk * 2.0);
    target.setHp(target.getHp() - damage);

    // Calculate recoil damage (10% of damage dealt)
    int recoilDamage = static_cast<int>(damage * 0.1);
    hp -= recoilDamage;
    if (hp < 0)
        hp = 0; // Ensure HP doesn't go below 0

    std::cout << name << " uses Rage Strike on " << target.getName() << " for " << damage << " damage!\n";
    std::cout << name << " takes " << recoilDamage << " recoil damage!\n";
}

void Berserker::focus()
{
    mp += 4;
    std::cout << name << " focuses and gains 4 MP!\n";
}

void Berserker::displaySkills() const
{
    std::cout << name << "'s Skills:\n";
    std::cout << "1️⃣ Rage Strike (Cost: 4 MP, Cooldown: " << skillCooldown << " turns)\n";
}

void Berserker::reduceCooldown()
{
    if (skillCooldown > 0)
    {
        skillCooldown--;
    }
}

bool Berserker::isSkillReady() const
{
    return skillCooldown == 0;
}