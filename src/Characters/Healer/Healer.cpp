#include "Healer.h"
#include <iostream>

Healer::Healer(std::string name) 
    : Character(name, 16, 8, 12, 8, 16, 10, 18, 12, false) {}

void Healer::attack(Character& target) {
    std::cout << name << " gently taps " << target.getName() << " for minor damage!\n";
}

void Healer::useSkill(Character& target) {
    std::cout << name << " uses Healing Light on " << target.getName() << "!\n";
}

void Healer::useSkill2(Character& target) {
    std::cout << name << " uses Volley to hit " << target.getName() << " multiple times!\n";
}

void Healer::focus() {
    mp += 3;
    std::cout << name << " focuses and regains 3 MP!\n";
}

void Healer::displaySkills() const {
    std::cout << name << "'s Skills: 1️⃣ Healing Light, 2️⃣ Purify\n";
}
