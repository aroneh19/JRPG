#ifndef GAME_H
#define GAME_H

#include "../Characters/Base/Character.h"
#include <vector>

class Game {
public:
    static void startPVP();
    static void startPVE();
    static Character* createCharacter(int choice);  
    static void selectSquad(std::vector<Character*>& squad);
};

#endif
