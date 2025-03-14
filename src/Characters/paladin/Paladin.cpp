#include "Paladin.h"
#include <iostream>

Paladin::Paladin(std::string name)
    : Character(name, 16, 10, 16, 10, 12, 10, true) {}

void Paladin::attack(Character &target)
{
    std::cout << name << " strikes " << target.getName() << " with a holy sword!\n";
    Character::attack(target);
}

void Paladin::useSkill(Character &target)
{
    std::cout << name << " uses Divine Protection on the team!\n";
}

void Paladin::focus()
{
    mp += 4;
    std::cout << name << " prays and regains 2 MP!\n";
}

void Paladin::displaySkills() const
{
    std::cout << name << "'s Skills: 1️⃣ Shield Bash\n";
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
