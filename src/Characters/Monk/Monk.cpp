#include "Monk.h"
#include <iostream>

Monk::Monk(std::string name) 
    : Character(name, 14, 12, 0, 10, 10, 14, 10, 12, true) {}

void Monk::attack(Character& target) {
    std::cout << name << " delivers a rapid punch to " << target.getName() << "!\n";
}

void Monk::useSkill(Character& target) {
    std::cout << name << " unleashes Flurry of Blows on " << target.getName() << "!\n";
}

void Monk::useSkill2(Character& target) {
    std::cout << name << " uses Volley to hit " << target.getName() << " multiple times!\n";
}

void Monk::focus() {
    mp += 3;
    std::cout << name << " enters a meditative state and regains 3 MP!\n";
}

void Monk::displaySkills() const {
    std::cout << name << "'s Skills: 1️⃣ Flurry of Blows, 2️⃣ Inner Peace\n";
}
