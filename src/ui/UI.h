#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>

namespace UI {
    // Displays the main menu (Start / Exit)
    void displayMainMenu();

    // Displays a hardcoded character selection screen
    void displayCharacterSelection();

    // Displays a hardcoded battle screen with pre-set teams
    void displayBattleState();

    // Displays a simulated turn for a hardcoded character
    void displayTurn(const std::string& fighter, int hp, int mp);

    // Displays a simulated attack result
    void displayActionResult(const std::string& attacker, const std::string& target, int damage);

    // Displays a winner (hardcoded)
    void displayWinner(const std::string& winner);
}

#endif