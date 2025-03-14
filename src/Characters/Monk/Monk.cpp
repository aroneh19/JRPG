#include "Monk.h"
#include <iostream>

Monk::Monk(std::string name)
    : Character(name, 14, 12, 10, 14, 10, 12, true, "Monk"), skillCooldown(0) {}

void Monk::attack(Character &target)
{
    std::cout << name << " delivers a rapid punch to " << target.getName() << "!\n";
    Character::attack(target); // Use the base attack logic
}

void Monk::useSkill(Character &target)
{
    if (!isSkillReady())
    {
        std::cout << name << "'s Inner Peace is on cooldown for " << skillCooldown << " more turns!\n";
        return;
    }

    if (mp < 6)
    {
        std::cout << name << " does not have enough MP to use Inner Peace!\n";
        return;
    }

    // Deduct MP and apply cooldown
    mp -= 6;
    skillCooldown = 4;

    // Calculate healing (30% of Monk's max HP)
    int healingAmount = static_cast<int>(maxHp * 0.3);
    hp += healingAmount;
    if (hp > maxHp)
        hp = maxHp;

    std::cout << name << " uses Inner Peace, restoring " << healingAmount << " HP and removing all debuffs!\n";
}

void Monk::focus()
{
    mp += 4;
    std::cout << name << " enters a meditative state and regains 4 MP!\n";
}

void Monk::displaySkills() const
{
    std::cout << name << "'s Skills:\n";
    std::cout << "1️⃣ Inner Peace (Cost: 6 MP, Cooldown: " << skillCooldown << " turns)\n";
}

void Monk::reduceCooldown()
{
    if (skillCooldown > 0)
    {
        skillCooldown--;
    }
}

bool Monk::isSkillReady() const
{
    return skillCooldown == 0;
}