#ifndef UI_H
#define UI_H

#include <iostream>
#include <vector>
#include <string>
#include "../Characters/Base/Character.h"

namespace UI {
    void displayCharacterSelection(const std::string& role, const std::vector<int>& availableCharacters);
    void displayBattleState(const std::vector<Character*>& team1, const std::vector<Character*>& team2);
    void displayTurn(const Character* fighter);
    void displayActionResult(const std::string& attacker, const std::string& target, int damage);
    void displayWinner(const std::string& winner);
    void displayHPMP(const std::vector<Character*>& team1, const std::vector<Character*>& team2);
}

#endif // UI_H
