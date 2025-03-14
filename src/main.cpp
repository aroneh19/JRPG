#include <iostream>
#include "ui/Menu.h"
#include "ui/Ui.h"
#include "Characters/Characters.h"
#include "Game/Game.h"
#include <vector>

int main() {
    Menu::displayMainMenu();
    int game_mode;
    std::cin >> game_mode;

    if (game_mode == 1) {
        std::cout << "You selected PVP mode\n";
        Game::startPVP();
    }

    else if (game_mode == 2) {
        std::cout << "You selected PVE mode\n";
        // startPVE();
    }

    else if (game_mode == 3) {
        std::cout << "Exiting the game...";
    }

    else {
        std::cout << "Please put in valid input (1) (2) (3)";
    }

    Menu::displayCharacterSelection();

    std::vector<Character*> team1;
    std::vector<Character*> team2;

    // TODO: Implement character selection (allow players to pick characters)

    // Display battle screen
    UI::displayBattleState(team1, team2);

    // TODO: Implement turn-based combat system
    while (!team1.empty() && !team2.empty()) {
        // Team 1's turn
        // TODO: Allow Team 1 to pick an action

        // Team 2's turn
        // TODO: Allow Team 2 to pick an action

        // TODO: Check for defeated characters and remove them
    }

    if (team1.empty()) {
        UI::displayWinner("Team 2");
    } else {
        UI::displayWinner("Team 1");
    }

    for (auto character : team1) delete character;
    for (auto character : team2) delete character;

    return 0;
}
