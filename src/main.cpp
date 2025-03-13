#include "ui/Menu.h"
#include "ui/Ui.h"
#include "Characters/Characters.h"
#include <vector>

int main() {
    Menu::displayMainMenu();

    Menu::displayCharacterSelection();

    std::vector<Character*> team1;
    std::vector<Character*> team2;

    // TODO: Implement character selection (allow players to pick characters)

    // Display battle screen
    UI::displayBattleState(team1, team2);

    // TODO: Implement turn-based combat system
    while (!team1.empty() && !team2.empty()) {
        // Team 1's turn
        // TODO: Allow Team 1 to pick an action

        // Team 2's turn
        // TODO: Allow Team 2 to pick an action

        // TODO: Check for defeated characters and remove them
    }

    if (team1.empty()) {
        UI::displayWinner("Team 2");
    } else {
        UI::displayWinner("Team 1");
    }

    for (auto character : team1) delete character;
    for (auto character : team2) delete character;

    return 0;
}
