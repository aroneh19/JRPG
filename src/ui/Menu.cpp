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

