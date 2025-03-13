#include "Knight.h"
#include <iostream>

Knight::Knight(std::string name) 
    : Character(name, 14, 14, 0, 14, 10, 12, 10, 10, true) {}

void Knight::attack(Character& target) {
    std::cout << name << " slashes " << target.getName() << " with a longsword!\n";
}

void Knight::useSkill(Character& target) {
    std::cout << name << " uses Counter Stance to reflect incoming attacks!\n";
}

void Knight::useSkill2(Character& target) {
    std::cout << name << " uses Volley to hit " << target.getName() << " multiple times!\n";
}

void Knight::focus() {
    mp += 2;
    std::cout << name << " steadies their stance and regains 2 MP!\n";
}

void Knight::displaySkills() const {
    std::cout << name << "'s Skills: 1️⃣ Counter Stance, 2️⃣ Rallying Cry\n";
}
