#ifndef DAMAGECALCULATOR_H
#define DAMAGECALCULATOR_H

#include "../characters/base/Character.h"

class DamageCalculator
{
public:
    static int calculateDamage(Character &attacker, Character &target);
};

#endif // DAMAGECALCULATOR_H