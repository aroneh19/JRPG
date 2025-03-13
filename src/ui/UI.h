#ifndef UI_H
#define UI_H

#include <iostream>
#include <vector>
#include "../Characters/Characters.h"

namespace UI {
    void displayBattleState(const std::vector<Character*>& team1, const std::vector<Character*>& team2);
    void displayTurn(const Character& fighter);
    void displayActionResult(Character& attacker, Character& target, int damage);
    void displayWinner(const std::string& winner);
}

#endif
