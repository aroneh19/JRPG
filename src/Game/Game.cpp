#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include "../ui/Ui.h"
#include "Game.h"
#include "../Characters/Characters.h"  // ✅ Single include for all characters
#include "../Combat/CombatSystem.h"

void Game::startPVP() {
    std::vector<Character*> player1Squad;
    std::vector<Character*> player2Squad;

    std::cout << "🏆 Player 1 & Player 2: Pick your teams one at a time! 🏆\n";
    selectSquads(player1Squad, player2Squad);

    std::cout << "\n🚀 Both teams are ready! The battle begins!\n";
    
    CombatSystem battle(player1Squad, player2Squad);
    battle.startCombat();
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

int Game::getValidChoice(const std::vector<int>& availableCharacters) {
    int choice;

    while (true) {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "❌ Invalid input! Please enter a number.\n";
            continue;
        }

        if (std::find(availableCharacters.begin(), availableCharacters.end(), choice) != availableCharacters.end()) {
            return choice;
        } else {
            std::cout << "❌ Invalid choice! Pick an available character.\n";
        }
    }
}


std::string Game::getCharacterName(int choice) {
    switch (choice) {
        case 1: return "🛡️ Paladin";
        case 2: return "⚔️ Berserker";
        case 3: return "🥋 Monk";
        case 4: return "🏰 Knight";
        case 5: return "🎯 Archer";
        case 6: return "🔥 Mage";
        case 7: return "🩺 Healer";
        case 8: return "☠️ Assassin";
        default: return "❌ Unknown";
    }
}

void Game::selectSquads(std::vector<Character*>& player1Squad, std::vector<Character*>& player2Squad) {
    std::vector<int> availableFrontliners = {1, 2, 3, 4};
    std::vector<int> availableBackliners = {5, 6, 7, 8};

    for (int i = 0; i < 2; ++i) {  
        std::cout << "🎮 Player 1, pick Frontliner " << (i + 1) << ":\n";
        UI::displayCharacterSelection("Frontliners", availableFrontliners);
        int choice1 = getValidChoice(availableFrontliners);
        player1Squad.push_back(createCharacter(choice1));
        availableFrontliners.erase(std::remove(availableFrontliners.begin(), availableFrontliners.end(), choice1), availableFrontliners.end());

        std::cout << "🎮 Player 2, pick Frontliner " << (i + 1) << ":\n";
        UI::displayCharacterSelection("Frontliners", availableFrontliners);
        int choice2 = getValidChoice(availableFrontliners);
        player2Squad.push_back(createCharacter(choice2));
        availableFrontliners.erase(std::remove(availableFrontliners.begin(), availableFrontliners.end(), choice2), availableFrontliners.end());
    }

    for (int i = 0; i < 2; ++i) {  
        std::cout << "🎮 Player 1, pick Backliner " << (i + 1) << ":\n";
        UI::displayCharacterSelection("Backliners", availableBackliners);
        int choice1 = getValidChoice(availableBackliners);
        player1Squad.push_back(createCharacter(choice1));
        availableBackliners.erase(std::remove(availableBackliners.begin(), availableBackliners.end(), choice1), availableBackliners.end());

        std::cout << "🎮 Player 2, pick Backliner " << (i + 1) << ":\n";
        UI::displayCharacterSelection("Backliners", availableBackliners);
        int choice2 = getValidChoice(availableBackliners);
        player2Squad.push_back(createCharacter(choice2));
        availableBackliners.erase(std::remove(availableBackliners.begin(), availableBackliners.end(), choice2), availableBackliners.end());
    }
}
