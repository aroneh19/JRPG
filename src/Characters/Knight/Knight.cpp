#include "Knight.h"
#include <iostream>

Knight::Knight(std::string name) 
    : Character(name, 14, 14, 14, 12, 10, 10, true) {}

void Knight::attack(Character& target) {
    std::cout << name << " slashes " << target.getName() << " with a longsword!\n";
}

void Knight::useSkill(Character& target) {
    std::cout << name << " uses Counter Stance to reflect incoming attacks!\n";
}

void Knight::focus() {
    mp += 4;
    std::cout << name << " steadies their stance and regains 2 MP!\n";
}

void Knight::displaySkills() const {
    std::cout << name << "'s Skills: 1️⃣ Counter Stance\n";
}
