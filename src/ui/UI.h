#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>

namespace UI {
    void displayMainMenu();

    void displayCharacterSelection();

    void displayBattleState();

    void displayTurn(const std::string& fighter, int hp, int mp);

    void displayActionResult(const std::string& attacker, const std::string& target, int damage);

    void displayWinner(const std::string& winner);
}

#endif