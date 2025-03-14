#include "CombatSystem.h"
#include "TurnOrder.h"
#include "DamageCalculator.h"
#include "../ui/Ui.h"
#include <iostream>
#include <algorithm>

CombatSystem::CombatSystem(std::vector<Character*>& playerTeam, std::vector<Character*>& enemyTeam)
    : playerTeam(playerTeam), enemyTeam(enemyTeam) {}

void CombatSystem::startCombat() {
    TurnOrder turnOrder(playerTeam, enemyTeam);
    UI::displayBattleState(playerTeam, enemyTeam);

    while (!isCombatOver()) {
        Character* currentCharacter = turnOrder.getNextCharacter();
        if (!currentCharacter || currentCharacter->getHp() <= 0) continue;

        UI::displayTurn(currentCharacter);
        performAction(currentCharacter);
        UI::displayHPMP(playerTeam, enemyTeam);
    }

    std::string winner;
    if (std::all_of(playerTeam.begin(), playerTeam.end(), [](Character* c) { return c->getHp() <= 0; })) {
        winner = "Team 2 Wins!";
    } else {
        winner = "Team 1 Wins!";
    }
    UI::displayWinner(winner);
}

bool CombatSystem::isCombatOver() {
    return std::all_of(playerTeam.begin(), playerTeam.end(), [](Character* c) { return c->getHp() <= 0; }) ||
           std::all_of(enemyTeam.begin(), enemyTeam.end(), [](Character* c) { return c->getHp() <= 0; });
}

void CombatSystem::performAction(Character* character) {
    int action;
    std::cout << "Choose an action (1: Attack, 2: Use Skill, 3: Focus): ";
    std::cin >> action;

    if (action == 1) {
        Character* target = selectTarget(character, false);
        if (target) {
            int damage = DamageCalculator::calculateDamage(*character, *target);
            target->setHp(target->getHp() - damage);
            UI::displayActionResult(character->getName(), target->getName(), damage);
        }
    } else if (action == 2) {
        Character* target = selectTarget(character, true);
        if (target) {
            character->useSkill(*target);
        }
    } else if (action == 3) {
        character->focus();
    }
}

Character* CombatSystem::getValidTarget(std::vector<Character*>& team, bool allowBackline) {
    std::vector<Character*> availableTargets;
    for (Character* target : team) {
        if (target->isAlive() && (allowBackline || target->isInFrontline())) {
            availableTargets.push_back(target);
        }
    }
    if (availableTargets.empty()) return nullptr;

    std::cout << "Choose a target:\n";
    for (size_t i = 0; i < availableTargets.size(); ++i) {
        std::cout << i + 1 << ": " << availableTargets[i]->getName() << " (HP: " << availableTargets[i]->getHp() << ")\n";
    }

    int choice;
    std::cin >> choice;
    if (choice < 1 || choice > static_cast<int>(availableTargets.size())) {
        return availableTargets[0];
    }
    return availableTargets[choice - 1];
}

Character* CombatSystem::selectTarget(Character* attacker, bool isSkill) {
    bool isPlayer1 = (std::find(playerTeam.begin(), playerTeam.end(), attacker) != playerTeam.end());
    std::vector<Character*>& opponentTeam = isPlayer1 ? enemyTeam : playerTeam;
    std::vector<Character*>& allyTeam = isPlayer1 ? playerTeam : enemyTeam;

    if (attacker->isHealer() && isSkill) {
        return getValidTarget(allyTeam, true);
    }

    bool frontlineAlive = std::any_of(opponentTeam.begin(), opponentTeam.end(), [](Character* c) { return c->isAlive() && c->isInFrontline(); });
    bool allowBackline = isSkill && attacker->isBackline();
    if (!frontlineAlive) allowBackline = true;

    return getValidTarget(opponentTeam, allowBackline);
}
