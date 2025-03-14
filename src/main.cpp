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
        std::cout << "Exiting the game...\n";
        return 0;
    }

    else {
        std::cout << "Please put in valid input (1) (2) (3)";
    }

}
