#include "Ui.h"

void UI::displayCharacterSelectionFront()
{
    std::cout << "\n🏆 SELECT YOUR TEAM 🏆\n";
    std::cout << "Choose 2 Frontliners:\n";
    std::cout << "1. 🛡️ Paladin  2. ⚔️ Berserker  3. 🥋 Monk  4. 🏰 Knight\n";
}

void UI::displayCharacterSelectionBack()
{
    std::cout << "Choose 2 Backliners:\n";
    std::cout << "5. 🎯 Archer  6. 🔥 Mage  7. 🩺 Healer  8. ☠️ Assassin\n";
}
