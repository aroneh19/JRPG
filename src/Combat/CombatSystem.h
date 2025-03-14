#ifndef COMBATSYSTEM_H
#define COMBATSYSTEM_H

#include "../Characters/Base/Character.h"
#include <vector>

class CombatSystem {
private:
    std::vector<Character*> playerTeam;
    std::vector<Character*> enemyTeam;

    bool isCombatOver();
    void performAction(Character* character);
    Character* selectTarget(Character* attacker);



public:
    CombatSystem(std::vector<Character*>& playerTeam, std::vector<Character*>& enemyTeam);
    void startCombat();
    void displayBattleState();
};

#endif // COMBATSYSTEM_H
