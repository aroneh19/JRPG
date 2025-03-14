#include "DamageCalculator.h"

int DamageCalculator::calculateDamage(Character& attacker, Character& target) {
    int damage = attacker.getAtk() - target.getDef();
    if (damage < attacker.getAtk() / 3) {
        damage = attacker.getAtk() / 3;
    }
    return damage;
}