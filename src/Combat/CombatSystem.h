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
    Character* selectTarget(Character* attacker, bool isSkill);
    Character* getValidTarget(std::vector<Character*>& team, bool allowBackline);



public:
    CombatSystem(std::vector<Character*>& playerTeam, std::vector<Character*>& enemyTeam);  // ✅ Ensure this is declared
    void startCombat();
};

#endif // COMBATSYSTEM_H
