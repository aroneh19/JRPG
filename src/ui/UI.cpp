#include "Ui.h"
#include <iostream>
#include <iomanip>  // ✅ Needed for formatting output
#include <vector>
#include <string>   // ✅ Ensure string is included
#include "../Characters/Base/Character.h" 
#include "../Game/Game.h" 

namespace UI {  // ✅ Make sure namespace is present

    void displayCharacterSelection(const std::string& role, const std::vector<int>& availableCharacters) {
        std::cout << "🏆 SELECT YOUR CHARACTER: " << role << " 🏆\n";
        std::cout << "Available characters:\n";
        for (int choice : availableCharacters) {
            std::cout << choice << ". " << Game::getCharacterName(choice) << "\n";
        }
    }

void displayBattleState(const std::vector<Character*>& team1, const std::vector<Character*>& team2) {
    std::cout << "\n=== ⚔️ Battle Begins! ⚔️ ===\n";
    displayHPMP(team1, team2);  // ✅ Show HP/MP before starting battle
}

void displayHPMP(const std::vector<Character*>& team1, const std::vector<Character*>& team2) {
    std::cout << "\n💖 Current HP & MP Status 💖\n";
    
    std::cout << "🎮 Team 1:\n";
    for (const auto& fighter : team1) {
        std::cout << (fighter->getIsFrontline() ? "🛡️ " : "🎯 ") 
                  << std::left << std::setw(12) << fighter->getName()
                  << " | HP: " << std::setw(3) << fighter->getHp() << "/" << std::setw(3) << fighter->getMaxHp()
                  << " | MP: " << std::setw(2) << fighter->getMp() << "\n";
    }

    std::cout << "\n🎮 Team 2:\n";
    for (const auto& fighter : team2) {
        std::cout << (fighter->getIsFrontline() ? "🛡️ " : "🎯 ") 
                  << std::left << std::setw(12) << fighter->getName()
                  << " | HP: " << std::setw(3) << fighter->getHp() << "/" << std::setw(3) << fighter->getMaxHp()
                  << " | MP: " << std::setw(2) << fighter->getMp() << "\n";
    }

    std::cout << "==============================\n";
}

void displayTurn(const Character* fighter) {
    std::cout << "\n🎭 " << fighter->getName() << "'s Turn! 🎭\n";
    std::cout << "💖 HP: " << fighter->getHp() << " / " << fighter->getMaxHp();
    std::cout << " | ⚡ MP: " << fighter->getMp() << "\n";
    std::cout << "1️⃣ Attack  2️⃣ Use Skill  3️⃣ Focus (Gain MP)\n";
}

void displayActionResult(const std::string& attacker, const std::string& target, int damage) {
    std::cout << "\n💥 " << attacker << " attacks " << target << " for " << damage << " damage!\n";
}

void displayWinner(const std::string& winner) {
    std::cout << "\n🎉 " << winner << " Wins! 🎉\n";
}

} // namespace UI
