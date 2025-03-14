#include "CombatSystem.h"
#include "TurnOrder.h"
#include "DamageCalculator.h"
#include <iostream>

CombatSystem::CombatSystem(std::vector<Character*>& playerTeam, std::vector<Character*>& enemyTeam)
    : playerTeam(playerTeam), enemyTeam(enemyTeam) {}

void CombatSystem::startCombat() {
    TurnOrder turnOrder(playerTeam, enemyTeam);

    while (!isCombatOver()) {
        Character* currentCharacter = turnOrder.getNextCharacter();
        if (currentCharacter->getHp() <= 0) continue;

        std::cout << currentCharacter->getName() << "'s turn!\n";
        performAction(currentCharacter);
    }

    std::cout << "Combat is over!\n";
}

bool CombatSystem::isCombatOver() {
    bool playerTeamAlive = false;
    bool enemyTeamAlive = false;

    for (auto* character : playerTeam) {
        if (character->getHp() > 0) {
            playerTeamAlive = true;
            break;
        }
    }

    for (auto* character : enemyTeam) {
        if (character->getHp() > 0) {
            enemyTeamAlive = true;
            break;
        }
    }

    return !playerTeamAlive || !enemyTeamAlive;
}

void CombatSystem::performAction(Character* character) {
    character->displaySkills();
    int action;
    std::cout << "Choose an action (1: Attack, 2: Use Skill, 3: Focus): ";
    std::cin >> action;

    if (action == 1) {
        Character* target = selectTarget();
        character->attack(*target);
    } else if (action == 2) {
        Character* target = selectTarget();
        character->useSkill(*target);
    } else if (action == 3) {
        character->focus();
    }
}

Character* CombatSystem::selectTarget() {
    std::cout << "Select a target:\n";
    for (size_t i = 0; i < enemyTeam.size(); ++i) {
        std::cout << i + 1 << ": " << enemyTeam[i]->getName() << " (HP: " << enemyTeam[i]->getHp() << ")\n";
    }

    int choice;
    std::cin >> choice;
    return enemyTeam[choice - 1];
}