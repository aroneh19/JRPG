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

#include "../Combat/CombatSystem.h"

void Game::startPVP() {
    std::vector<Character*> player1Squad;
    std::vector<Character*> player2Squad;

    std::cout << "🎮 Player 1, select your team!\n";
    Game::selectSquad(player1Squad);

    std::cout << "🎮 Player 2, select your team!\n";
    Game::selectSquad(player2Squad);

    std::cout << "\n🚀 Both teams are ready! The battle begins!\n";

    // 🔍 DEBUG: Print the teams before battle
    std::cout << "🔍 DEBUG: Player 1 Squad:\n";
    for (auto* c : player1Squad) {
        std::cout << " - " << c->getName() << " (HP: " << c->getHp() << ")\n";
    }
    
    std::cout << "🔍 DEBUG: Player 2 Squad:\n";
    for (auto* c : player2Squad) {
        std::cout << " - " << c->getName() << " (HP: " << c->getHp() << ")\n";
    }

    // ✅ Show initial HP & MP status before the battle
    UI::displayBattleState(player1Squad, player2Squad);

    std::cout << "🔍 DEBUG: Initial battle state displayed. Creating CombatSystem...\n";

    // ✅ Initialize Combat System and start combat
    CombatSystem combat(player1Squad, player2Squad);
    
    std::cout << "🔍 DEBUG: CombatSystem initialized. Starting battle...\n";

    combat.startCombat();

    std::cout << "🔍 DEBUG: Battle finished. Freeing memory...\n";

    // ✅ Free memory AFTER the battle finishes
    for (Character* c : player1Squad) delete c;
    for (Character* c : player2Squad) delete c;

    std::cout << "🔍 DEBUG: Memory cleanup completed.\n";
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
        case 5: return new Archer("Archer");   // ✅ Ensure correct numbering
        case 6: return new Mage("Mage");       // ✅ Correctly map 6 to Mage
        case 7: return new Healer("Healer");   // ✅ Correctly map 7 to Healer
        case 8: return new Assassin("Assassin");  // ✅ Correctly map 8 to Assassin
        default: return nullptr;
    }
}



void Game::selectSquad(std::vector<Character*>& squad) {
    int choice;

    UI::displayCharacterSelectionFront();
    std::cout << "Enter 2 choices (1-4):\n";

    for (int i = 0; i < 2; i++) {
        std::cin >> choice;
        Character* newCharacter = Game::createCharacter(choice);
        if (newCharacter) {
            squad.push_back(newCharacter);
        } else {
            std::cout << "❌ Invalid choice! Try again.\n";
            i--; // Repeat selection
        }
    }

    UI::displayCharacterSelectionBack();
    std::cout << "Enter 2 choices (5-8):\n";  // ✅ Ensure correct number range

    for (int i = 0; i < 2; i++) {
        std::cin >> choice;
        Character* newCharacter = Game::createCharacter(choice);  // ❌ Remove "+4" offset
        if (newCharacter) {
            squad.push_back(newCharacter);
        } else {
            std::cout << "❌ Invalid choice! Try again.\n";
            i--; // Repeat selection
        }
    }

    std::cout << "✅ Your squad is ready!\n";
}
