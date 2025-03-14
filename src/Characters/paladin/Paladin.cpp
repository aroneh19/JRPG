#include "Paladin.h"
#include <iostream>

Paladin::Paladin(std::string name)
    : Character(name, 16, 10, 16, 10, 12, 10, true, "Paladin"), skillCooldown(0) {}

void Paladin::attack(Character &target)
{
    std::cout << name << " strikes " << target.getName() << " with a holy sword!\n";
    Character::attack(target); // Use the base attack logic
}

void Paladin::useSkill(Character &target)
{
    if (!isSkillReady())
    {
        std::cout << name << "'s Aura of Protection is on cooldown for " << skillCooldown << " more turns!\n";
        return;
    }

    if (mp < 10)
    {
        std::cout << name << " does not have enough MP to use Aura of Protection!\n";
        return;
    }

    // Deduct MP and apply cooldown
    mp -= 10;
    skillCooldown = 10;

    // Boost the Paladin's own ATK and DEF by +1
    atk += 1;
    def += 1;

    std::cout << name << " uses Aura of Protection, boosting their own ATK and DEF by +1!\n";
}

void Paladin::focus()
{
    mp += 4;
    std::cout << name << " prays and regains 4 MP!\n";
}

void Paladin::displaySkills() const
{
    std::cout << name << "'s Skills:\n";
    std::cout << "1️⃣ Aura of Protection (Cost: 10 MP, Cooldown: " << skillCooldown << " turns)\n";
}

void Paladin::reduceCooldown()
{
    if (skillCooldown > 0)
    {
        skillCooldown--;
    }
}

bool Paladin::isSkillReady() const
{
    return skillCooldown == 0;
}