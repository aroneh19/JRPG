#include "TurnOrder.h"
#include <algorithm>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iostream>

TurnOrder::TurnOrder(std::vector<Character *> &playerTeam, std::vector<Character *> &enemyTeam)
{
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Combine both teams into the allCharacters vector
    allCharacters.insert(allCharacters.end(), playerTeam.begin(), playerTeam.end());
    allCharacters.insert(allCharacters.end(), enemyTeam.begin(), enemyTeam.end());

    // Sort characters based on SPD + random number between 1 and 10
    std::sort(allCharacters.begin(), allCharacters.end(), [](Character *a, Character *b)
              {
        int randomA = std::rand() % 10 + 1; // Random number between 1 and 10
        int randomB = std::rand() % 10 + 1; // Random number between 1 and 10
        return (a->getSpd() + randomA) > (b->getSpd() + randomB); });
}

Character* TurnOrder::getNextCharacter() {
    if (allCharacters.empty()) {
        std::cout << "⚠️ ERROR: No characters in turn order!\n";
        return nullptr;  // Prevent crash
    }

    Character* nextCharacter = allCharacters[currentTurn];
    
    if (!nextCharacter) {
        std::cout << "⚠️ ERROR: Turn order has a NULL character at index " << currentTurn << "!\n";
        return nullptr;
    }

    currentTurn = (currentTurn + 1) % allCharacters.size();
    return nextCharacter;
}
