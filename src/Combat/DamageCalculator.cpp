#include "DamageCalculator.h"
#include <random>
#include <iostream>

int DamageCalculator::calculateDamage(Character& attacker, Character& target) {
    int baseDamage = std::max(1, attacker.getAtk() - target.getDef());

    float critChance = static_cast<float>(attacker.getLck()) / 200.0;
    float dodgeChance = static_cast<float>(target.getLck() + target.getSpd()) / 200.0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> rng(0, 1);

    if (rng(gen) < dodgeChance) {
        std::cout << "💨 " << target.getName() << " dodged the attack!\n";
        return 0;
    }

    if (rng(gen) < critChance) {
        std::cout << "💥 Critical Hit! 💥\n";
        baseDamage *= 1.5;
    }

    return baseDamage;
}
