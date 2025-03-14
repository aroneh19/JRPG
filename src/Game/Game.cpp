#include <iostream>
#include <vector>
#include "../ui/Ui.h"
#include "Game.h"
#include "../Characters/Paladin/Paladin.h"
#include "../Characters/Berserker/Berserker.h"
#include "../Characters/Monk/Monk.h"
#include "../Characters/Knight/Knight.h"
#include "../Characters/Archer/Archer.h"
#include "../Characters/Mage/Mage.h"
#include "../Characters/Healer/Healer.h"
#include "../Characters/Assassin/Assassin.h"

void Game::startPVP() {
    std::vector<Character*> player1Squad;
    std::vector<Character*> player2Squad;

    std::cout << "🎮 Player 1, select your team!\n";
    Game::selectSquad(player1Squad);

    std::cout << "🎮 Player 2, select your team!\n";
    Game::selectSquad(player2Squad);

    std::cout << "\n🚀 Both teams are ready! The battle begins!\n";

    // ❗ Free memory after battle
    for (Character* c : player1Squad) delete c;
    for (Character* c : player2Squad) delete c;
}

void Game::startPVE() {
    std::cout << "🎮 Starting PVE Mode...\n";
}

Character* Game::createCharacter(int choice) {
    switch (choice) {
        case 1: return new Paladin("Paladin");
        case 2: return new Berserker("Berserker");
        case 3: return new Monk("Monk");
        case 4: return new Knight("Knight");
        case 5: return new Archer("Archer");
        case 6: return new Mage("Mage");
        case 7: return new Healer("Healer");
        case 8: return new Assassin("Assassin");
        default: return nullptr;
    }
}

void Game::selectSquad(std::vector<Character*>& squad) {
    int choice;

    UI::displayCharacterSelectionFront();  // ✅ Show Frontliner Menu
    std::cout << "Enter 2 choices (1-4):\n";

    for (int i = 0; i < 2; i++) {
        std::cin >> choice;
        if (choice >= 1 && choice <= 4) {
            Character* newCharacter = Game::createCharacter(choice);
            squad.push_back(newCharacter);
        } else {
            std::cout << "❌ Invalid choice! Try again.\n";
            i--; // Repeat selection
        }
    }

    UI::displayCharacterSelectionBack();  // ✅ Show Backliner Menu
    std::cout << "Enter 2 choices (5-8):\n";  // ✅ FIXED prompt

    for (int i = 0; i < 2; i++) {
        std::cin >> choice;
        if (choice >= 5 && choice <= 8) {
            Character* newCharacter = Game::createCharacter(choice);
            squad.push_back(newCharacter);
        } else {
            std::cout << "❌ Invalid choice! Try again.\n";
            i--; // Repeat selection
        }
    }

    std::cout << "✅ Your squad is ready!\n";
}