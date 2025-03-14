#ifndef COMBATSYSTEM_H
#define COMBATSYSTEM_H

#include "../characters/base/Character.h"
#include <vector>

class CombatSystem
{
private:
    std::vector<Character *> playerTeam;
    std::vector<Character *> enemyTeam;

    bool isCombatOver();
    void performAction(Character *character);
    Character *selectTarget();

public:
    CombatSystem(std::vector<Character *> &playerTeam, std::vector<Character *> &enemyTeam);
    void startCombat();
};

#endif // COMBATSYSTEM_H