#include "Berserker.h"
#include <iostream>

Berserker::Berserker(std::string name) 
    : Character(name, 14, 18, 0, 10, 8, 12, 8, 10, true) {}

void Berserker::attack(Character& target) {
    std::cout << name << " swings their axe at " << target.getName() << "!\n";
}

void Berserker::useSkill(Character& target) {
    std::cout << name << " uses Rage Strike on " << target.getName() << "!\n";
}

void Berserker::focus() {
    mp += 2;
    std::cout << name << " focuses and gains 2 MP!\n";
}

void Berserker::displaySkills() const {
    std::cout << name << "'s Skills: 1️⃣ Rage Strike, 2️⃣ Bloodlust\n";
}
