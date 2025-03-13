#include "Archer.h"
#include <iostream>

Archer::Archer(std::string name) 
    : Character(name, 12, 0, 18, 6, 8, 14, 10, 12, false) {}

void Archer::attack(Character& target) {
    std::cout << name << " shoots an arrow at " << target.getName() << "!\n";
}

void Archer::useSkill(Character& target) {
    std::cout << name << " uses Snipe Shot to hit " << target.getName() << " for massive damage!\n";
}

void Archer::useSkill2(Character& target) {
    std::cout << name << " uses Volley to hit " << target.getName() << " multiple times!\n";
}

void Archer::focus() {
    mp += 3;
    std::cout << name << " takes a deep breath and regains 3 MP!\n";
}

void Archer::displaySkills() const {
    std::cout << name << "'s Skills: 1️⃣ Snipe Shot, 2️⃣ Volley\n";
}
