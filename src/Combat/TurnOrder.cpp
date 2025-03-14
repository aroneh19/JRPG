#include "TurnOrder.h"
#include <algorithm>

TurnOrder::TurnOrder(std::vector<Character*>& playerTeam, std::vector<Character*>& enemyTeam) {
    allCharacters.insert(allCharacters.end(), playerTeam.begin(), playerTeam.end());
    allCharacters.insert(allCharacters.end(), enemyTeam.begin(), enemyTeam.end());

    std::sort(allCharacters.begin(), allCharacters.end(), [](Character* a, Character* b) {
        return a->getSpd() > b->getSpd();
    });
}

Character* TurnOrder::getNextCharacter() {
    Character* nextCharacter = allCharacters[currentTurn];
    currentTurn = (currentTurn + 1) % allCharacters.size();
    return nextCharacter;
}