#include "Monk.h"
#include <iostream>

Monk::Monk(std::string name) 
    : Character(name, 14, 12, 10, 14, 10, 12, true) {}

void Monk::attack(Character& target) {
    std::cout << name << " delivers a rapid punch to " << target.getName() << "!\n";
}

void Monk::useSkill(Character& target) {
    std::cout << name << " unleashes Flurry of Blows on " << target.getName() << "!\n";
}

void Monk::focus() {
    mp += 4;
    std::cout << name << " enters a meditative state and regains 3 MP!\n";
}

void Monk::displaySkills() const {
    std::cout << name << "'s Skills: 1️⃣ Flurry of Blows\n";
}
