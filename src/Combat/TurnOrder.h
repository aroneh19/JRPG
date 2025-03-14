#ifndef TURNORDER_H
#define TURNORDER_H

#include "../Characters/Base/Character.h"
#include <vector>

class TurnOrder {
private:
    std::vector<Character*> allCharacters;
    size_t currentTurn = 0;

public:
    TurnOrder(std::vector<Character*>& playerTeam, std::vector<Character*>& enemyTeam);
    Character* getNextCharacter();
};

#endif // TURNORDER_H