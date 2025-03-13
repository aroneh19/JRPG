#include "Ui.h"

void UI::displayBattleState(const std::vector<Character*>& team1, const std::vector<Character*>& team2) {
    std::cout << "\n=== ⚔️ PLAYER VS PLAYER BATTLE START! ⚔️ ===\n";

    std::cout << "👤 Team 1:\n";
    for (const auto& fighter : team1) {
        std::cout << (fighter->getIsFrontline() ? "🛡️ " : "🎯 ") << fighter->getName()
                  << " (HP: " << fighter->getHp() << " | MP: " << fighter->getMp() << ")\n";
    }

    std::cout << "\nVS\n\n";

    std::cout << "👤 Team 2:\n";
    for (const auto& fighter : team2) {
        std::cout << (fighter->getIsFrontline() ? "🛡️ " : "🎯 ") << fighter->getName()
                  << " (HP: " << fighter->getHp() << " | MP: " << fighter->getMp() << ")\n";
    }
    std::cout << "==============================\n";
}

void UI::displayTurn(const Character& fighter) {
    std::cout << "\n🎭 " << fighter.getName() << "'s Turn! 🎭\n";
    std::cout << "HP: " << fighter.getHp() << " | MP: " << fighter.getMp() << "\n";
}

void UI::displayActionResult(Character& attacker, Character& target, int damage) {
    std::cout << "\n💥 " << attacker.getName() << " attacks " << target.getName() << " for " << damage << " damage!\n";
}

void UI::displayWinner(const std::string& winner) {
    std::cout << "\n🎉 " << winner << " Wins! 🎉\n";
}
