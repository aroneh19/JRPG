#include "Assassin.h"
#include <iostream>

Assassin::Assassin(std::string name)
    : Character(name, 8, 18, 8, 16, 8, 16, false) {}

void Assassin::attack(Character &target)
{
    std::cout << name << " swiftly slashes " << target.getName() << "!\n";
}

void Assassin::useSkill(Character &target)
{
    std::cout << name << " uses Shadow Strike on " << target.getName() << "!\n";
}

void Assassin::focus()
{
    mp += 4;
    std::cout << name << " focuses in the shadows and gains 2 MP!\n";
}

void Assassin::displaySkills() const
{
    std::cout << name << "'s Skills: 1️⃣ Shadow Strike\n";
}
