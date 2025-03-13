#include <iostream>
#include <vector>
#include <iomanip>

namespace Menu
{
    void displayMainMenu();
    void displayCharacterSelection();
}

void Menu::displayMainMenu()
{
    std::cout << "╔════════════════════════╗\n";
    std::cout << "║   🏆 Zavant JRPG 🏆    ║\n";
    std::cout << "╠════════════════════════╣\n";
    std::cout << "║ 1. PVP                 ║\n";
    std::cout << "║ 2. PVE                 ║\n";
    std::cout << "║ 3. Exit                ║\n";
    std::cout << "╚════════════════════════╝\n";
}

void Menu::displayCharacterSelection()
{
    std::cout << "\n🏆 SELECT YOUR TEAM 🏆\n";
    std::cout << "Choose 2 Frontliners:\n";
    std::cout << "1. 🛡️ Paladin  2. ⚔️ Berserker  3. 🥋 Monk  4. 🏰 Knight\n";
    std::cout << "Choose 2 Backliners:\n";
    std::cout << "1. 🎯 Archer  2. 🔥 Mage  3. 🩺 Healer  4. ☠️ Assassin\n";
}