#include "Sharpshooter.h"
#include <iostream>

Sharpshooter::Sharpshooter(std::string name) 
    : Character(name, 12, 0, 18, 6, 8, 14, 10, 12, false) {}

void Sharpshooter::attack(Character& target) {
    std::cout << name << " shoots an arrow at " << target.getName() << "!\n";
}

void Sharpshooter::useSkill(Character& target) {
    std::cout << name << " uses Snipe Shot to hit " << target.getName() << " for massive damage!\n";
}

void Sharpshooter::focus() {
    mp += 3;
    std::cout << name << " takes a deep breath and regains 3 MP!\n";
}

void Sharpshooter::displaySkills() const {
    std::cout << name << "'s Skills: 1️⃣ Snipe Shot, 2️⃣ Volley\n";
}
