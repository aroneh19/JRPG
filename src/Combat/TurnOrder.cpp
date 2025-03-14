#include "TurnOrder.h"
#include <algorithm>
#include <cstdlib> 
#include <ctime>   
#include <iostream>

TurnOrder::TurnOrder(std::vector<Character *> &playerTeam, std::vector<Character *> &enemyTeam)
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    allCharacters.insert(allCharacters.end(), playerTeam.begin(), playerTeam.end());
    allCharacters.insert(allCharacters.end(), enemyTeam.begin(), enemyTeam.end());

    std::sort(allCharacters.begin(), allCharacters.end(), [](Character *a, Character *b)
              {
        int randomA = std::rand() % 10 + 1; 
        int randomB = std::rand() % 10 + 1;
        return (a->getSpd() + randomA) > (b->getSpd() + randomB); });
}

Character* TurnOrder::getNextCharacter() {
    if (allCharacters.empty()) {
        std::cout << "⚠️ ERROR: No characters in turn order!\n";
        return nullptr;  
    }

    Character* nextCharacter = allCharacters[currentTurn];
    
    if (!nextCharacter) {
        std::cout << "⚠️ ERROR: Turn order has a NULL character at index " << currentTurn << "!\n";
        return nullptr;
    }

    currentTurn = (currentTurn + 1) % allCharacters.size();
    return nextCharacter;
}
