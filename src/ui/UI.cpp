#include <iostream>
#include <vector>
#include <iomanip>

struct Character {
    std::string name;
    int hp, mp;
    bool isFrontline;

    Character(std::string name, int hp, int mp, bool isFrontline)
        : name(name), hp(hp), mp(mp), isFrontline(isFrontline) {}
};

namespace UI {
    void displayMainMenu();
    void displayCharacterSelection();
    void displayBattleState(const std::vector<Character>& playerTeam, const std::vector<Character>& enemyTeam);
    void displayTurn(const Character& fighter);
    void displayActionResult(const std::string& attacker, const std::string& target, int damage);
    void displayWinner(const std::string& winner);
}

void UI::displayMainMenu() {
    std::cout << "╔════════════════════════╗\n";
    std::cout << "║   🏆 Zavant JRPG 🏆    ║\n";
    std::cout << "╠════════════════════════╣\n";
    std::cout << "║ 1. Start Game          ║\n";
    std::cout << "║ 2. Exit                ║\n";
    std::cout << "╚════════════════════════╝\n";
}

void UI::displayCharacterSelection() {
    std::cout << "\n🏆 SELECT YOUR TEAM 🏆\n";
    std::cout << "Choose 2 Frontliners:\n";
    std::cout << "1. 🛡️ Paladin  2. ⚔️ Berserker  3. 🥋 Monk  4. 🏰 Knight\n";
    std::cout << "Choose 2 Backliners:\n";
    std::cout << "1. 🎯 Sharpshooter  2. 🔥 Mage  3. 🩺 Healer  4. ☠️ Assassin\n";
}

void UI::displayBattleState(const std::vector<Character>& playerTeam, const std::vector<Character>& enemyTeam) {
    std::cout << "\n=== ⚔️ BATTLE START! ⚔️ ===\n";
    
    std::cout << "👤 Your Team:\n";
    for (const auto& fighter : playerTeam) {
        std::cout << (fighter.isFrontline ? "🛡️ " : "🎯 ") << fighter.name 
                  << " (HP: " << fighter.hp << " | MP: " << fighter.mp << ")\n";
    }

    std::cout << "\nVS\n\n";

    std::cout << "👹 Enemy Team:\n";
    for (const auto& fighter : enemyTeam) {
        std::cout << (fighter.isFrontline ? "🛡️ " : "🎯 ") << fighter.name 
                  << " (HP: " << fighter.hp << " | MP: " << fighter.mp << ")\n";
    }
    std::cout << "==============================\n";
}

void UI::displayTurn(const Character& fighter) {
    std::cout << "\n🎭 " << fighter.name << "'s Turn! 🎭\n";
    std::cout << "HP: " << fighter.hp << " | MP: " << fighter.mp << "\n";
    std::cout << "1️⃣ Attack  2️⃣ Fire  3️⃣ Leer  4️⃣ Sword Dance\n";
}

void UI::displayActionResult(const std::string& attacker, const std::string& target, int damage) {
    std::cout << "\n💥 " << attacker << " attacks " << target << " for " << damage << " damage!\n";
}

void UI::displayWinner(const std::string& winner) {
    std::cout << "\n🎉 " << winner << " Wins! 🎉\n";
}
