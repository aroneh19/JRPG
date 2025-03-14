#ifndef GAME_H
#define GAME_H

#include "../Characters/Base/Character.h"
#include <vector>

class Game {
public:
    static void startPVP();
    static void startPVE();
    static Character* createCharacter(int choice);  
    static void selectSquads(std::vector<Character*>& player1Squad, std::vector<Character*>& player2Squad);
    static std::string getCharacterName(int choice);
    static int getValidChoice(const std::vector<int>& availableCharacters);
};

#endif
