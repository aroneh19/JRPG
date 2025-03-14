#ifndef DAMAGECALCULATOR_H
#define DAMAGECALCULATOR_H

#include "../Characters/Base/Character.h"

class DamageCalculator
{
public:
    static int calculateDamage(Character &attacker, Character &target);
};

#endif // DAMAGECALCULATOR_H