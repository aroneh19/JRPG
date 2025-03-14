#include "Archer.h"
#include <iostream>

Archer::Archer(std::string name) 
    : Character(name, 12, 18, 8, 14, 10, 12, false, "Archer"), skillCooldown(0) {}

void Archer::attack(Character& target) {
    std::cout << name << " shoots an arrow at " << target.getName() << "!\n";
    Character::attack(target); 
}

void Archer::useSkill(Character& target) {
    if (!isSkillReady()) {
        std::cout << name << "'s Snipe Shot is on cooldown for " << skillCooldown << " more turns!\n";
        return;
    }

    if (mp < 5) {
        std::cout << name << " does not have enough MP to use Snipe Shot!\n";
        return;
    }

    mp -= 5;
    skillCooldown = 3;

    int damage = static_cast<int>(atk * 2.5);
    target.setHp(target.getHp() - damage);

    std::cout << name << " uses Snipe Shot on " << target.getName() << " for " << damage << " damage! (Ignores targeting rules)\n";
}

void Archer::focus() {
    mp += 4;
    std::cout << name << " takes a deep breath and regains 3 MP!\n";
}

void Archer::displaySkills() const {
    std::cout << name << "'s Skills:\n";
    std::cout << "1️⃣ Snipe Shot (Cost: 5 MP, Cooldown: " << skillCooldown << " turns)\n";
}

void Archer::reduceCooldown() {
    if (skillCooldown > 0) {
        skillCooldown--;
    }
}

bool Archer::isSkillReady() const {
    return skillCooldown == 0;
}