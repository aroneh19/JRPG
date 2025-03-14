#include "Healer.h"
#include <iostream>

Healer::Healer(std::string name)
    : Character(name, 16, 8, 14, 10, 18, 12, false, "Healer"), skillCooldown(0) {}

void Healer::attack(Character &target)
{
    std::cout << name << " gently taps " << target.getName() << " for minor damage!\n";
    Character::attack(target);
}

void Healer::useSkill(Character &target)
{
    if (mp < 4)
    {
        std::cout << name << " does not have enough MP to use Healing Light!\n";
        return;
    }

    mp -= 4;

    int healingAmount = static_cast<int>(target.getMaxHp() * 0.3);
    target.setHp(target.getHp() + healingAmount);

    std::cout << name << " uses Healing Light on " << target.getName() << ", restoring " << healingAmount << " HP!\n";
}

void Healer::focus()
{
    mp += 4;
    std::cout << name << " focuses and regains 4 MP!\n";
}

void Healer::displaySkills() const
{
    std::cout << name << "'s Skills:\n";
    std::cout << "1️⃣ Healing Light (Cost: 4 MP, Cooldown: " << skillCooldown << " turns)\n";
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