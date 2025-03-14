#include "CombatSystem.h"
#include "TurnOrder.h"
#include "DamageCalculator.h"
#include "../ui/Ui.h"
#include <iostream>

CombatSystem::CombatSystem(std::vector<Character*>& playerTeam, std::vector<Character*>& enemyTeam)
    : playerTeam(playerTeam), enemyTeam(enemyTeam) {}

void CombatSystem::startCombat() {
    TurnOrder turnOrder(playerTeam, enemyTeam);
    UI::displayBattleState(playerTeam, enemyTeam);  // ✅ Show initial status

    while (!isCombatOver()) {
        Character* currentCharacter = turnOrder.getNextCharacter();
        if (currentCharacter->getHp() <= 0) continue;  // ✅ Skip defeated characters

        UI::displayTurn(currentCharacter);
        performAction(currentCharacter);

        UI::displayHPMP(playerTeam, enemyTeam);  // ✅ Update UI after each action
    }

    std::string winner = isCombatOver() ? (playerTeam[0]->getHp() > 0 ? "Player Team" : "Enemy Team") : "Unknown";
    UI::displayWinner(winner);
}

bool CombatSystem::isCombatOver() {
    bool playerAlive = false, enemyAlive = false;

    for (auto* character : playerTeam)
        if (character->getHp() > 0) playerAlive = true;

    for (auto* character : enemyTeam)
        if (character->getHp() > 0) enemyAlive = true;

    return !(playerAlive && enemyAlive);  // ✅ Battle ends when one team is wiped out
}

void CombatSystem::performAction(Character* character) {
    int action;
    std::cout << "Choose an action (1: Attack, 2: Use Skill, 3: Focus): ";
    std::cin >> action;

    if (action == 1) {  // ✅ Attack
        Character* target = selectTarget(character);
        if (target) {
            int damage = DamageCalculator::calculateDamage(*character, *target);
            character->attack(*target);
            target->setHp(target->getHp() - damage);
            UI::displayActionResult(character->getName(), target->getName(), damage);
        }
    } else if (action == 2) {  // ✅ Use Skill
        Character* target = selectTarget(character);
        if (target && character->getMp() >= 4) {
            character->useSkill(*target);
            character->setMp(character->getMp() - 4);
        } else {
            std::cout << "❌ Not enough MP!\n";
        }
    } else if (action == 3) {  // ✅ Focus (Gain MP)
        character->focus();
        std::cout << character->getName() << " focused and gained MP!\n";
    }

    character->setMp(character->getMp() + 1);  // ✅ MP Regen per turn
}

Character* CombatSystem::selectTarget(Character* attacker) {
    std::vector<Character*>& opponentTeam = (playerTeam[0] == attacker) ? enemyTeam : playerTeam; // ✅ Determine correct opponent team

    if (opponentTeam.empty()) {
        std::cout << "⚠️ No valid targets! Skipping turn...\n";
        return nullptr;
    }

    std::cout << "🔍 DEBUG: Available targets:\n";
    for (size_t i = 0; i < opponentTeam.size(); ++i) {
        std::cout << i + 1 << ": " << opponentTeam[i]->getName() 
                  << " (HP: " << opponentTeam[i]->getHp() << ")\n";
    }

    int choice;
    std::cin >> choice;

    if (choice < 1 || choice > (int)opponentTeam.size()) {
        std::cout << "❌ Invalid selection! Choosing first available target.\n";
        return opponentTeam[0];  // ✅ Return a valid target
    }

    return opponentTeam[choice - 1]; // ✅ Return selected target
}
