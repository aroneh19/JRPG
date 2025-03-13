#include "Mage.h"
#include <iostream>

Mage::Mage(std::string name) 
    : Character(name, 8, 0, 18, 4, 10, 12, 14, 10, false) {}

void Mage::attack(Character& target) {
    std::cout << name << " casts a magic missile at " << target.getName() << "!\n";
}

void Mage::useSkill(Character& target) {
    std::cout << name << " uses Fireball on " << target.getName() << "!\n";
}

void Mage::useSkill2(Character& target) {
    std::cout << name << " uses Volley to hit " << target.getName() << " multiple times!\n";
}

void Mage::focus() {
    mp += 3;
    std::cout << name << " channels mana and regains 3 MP!\n";
}

void Mage::displaySkills() const {
    std::cout << name << "'s Skills: 1️⃣ Fireball, 2️⃣ Arcane Shield\n";
}
