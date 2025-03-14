#include "Paladin.h"
#include <iostream>

Paladin::Paladin(std::string name) 
    : Character(name, 16, 10, 0, 18, 14, 10, 12, 10, true) {}

void Paladin::attack(Character& target) {
    std::cout << name << " strikes " << target.getName() << " with a holy sword!\n";
}

void Paladin::useSkill(Character& target) {
    std::cout << name << " uses Divine Protection on the team!\n";
}

void Paladin::focus() {
    mp += 2;
    std::cout << name << " prays and regains 2 MP!\n";
}

void Paladin::displaySkills() const {
    std::cout << name << "'s Skills: 1️⃣ Shield Bash, 2️⃣ Divine Protection\n";
}
