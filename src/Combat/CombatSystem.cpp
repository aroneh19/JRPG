#include "CombatSystem.h"
#include "TurnOrder.h"
#include "DamageCalculator.h"
#include "../ui/Ui.h"
#include <iostream>
#include <algorithm>

CombatSystem::CombatSystem(std::vector<Character*>& playerTeam, std::vector<Character*>& enemyTeam)
    : playerTeam(playerTeam), enemyTeam(enemyTeam) {} 

void CombatSystem::startCombat() {
    std::cout << "🚀 Battle begins! Checking teams...\n";

    std::cout << " Player 1's Team:\n";
    for (Character* c : playerTeam) {
        if (!c) {
            std::cout << "⚠️ ERROR: Null character in Player 1's team!\n";
            return; // Exit early to prevent crash
        }
        std::cout << "- " << c->getName() << " (HP: " << c->getHp() << ")\n";
    }

    std::cout << "✅ Player 2's Team:\n";
    for (Character* c : enemyTeam) {
        if (!c) {
            std::cout << "⚠️ ERROR: Null character in Player 2's team!\n";
            return; // Exit early to prevent crash
        }
        std::cout << "- " << c->getName() << " (HP: " << c->getHp() << ")\n";
    }

    std::cout << "🔍 DEBUG: Creating turn order...\n";
    TurnOrder turnOrder(playerTeam, enemyTeam);

    std::cout << "🔍 DEBUG: Turn order created. Displaying battle state...\n";
    UI::displayBattleState(playerTeam, enemyTeam);  // ✅ Show initial status

    while (!isCombatOver()) {
        std::cout << "🔍 DEBUG: Getting next character...\n";
        Character* currentCharacter = turnOrder.getNextCharacter();
        
        if (!currentCharacter) {
            std::cout << "⚠️ ERROR: Null character in turn order!\n";
            return;
        }
        
        if (currentCharacter->getHp() <= 0) {
            std::cout << "⚠️ Skipping " << currentCharacter->getName() << " (Defeated)\n";
            continue;
        }

        std::cout << "🔍 DEBUG: " << currentCharacter->getName() << "'s turn!\n";
        UI::displayTurn(currentCharacter);
        performAction(currentCharacter);

        std::cout << "🔍 DEBUG: Updating battle state...\n";
        UI::displayHPMP(playerTeam, enemyTeam);
    }

    std::string winner = isCombatOver() ? (playerTeam[0]->getHp() > 0 ? "Team 1" : "Team 2") : "Unknown";
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
    std::cout << character->getName() << "'s turn!\n";

    int action;
    std::cout << "Choose an action (1: Attack, 2: Use Skill, 3: Focus): ";
    std::cin >> action;

    if (action == 1) {  // 🏹 Regular Attack (Frontline can only attack enemy frontline)
        Character* target = selectTarget(character, false);
        if (target) {
            int damage = DamageCalculator::calculateDamage(*character, *target);
            target->setHp(target->getHp() - damage);
            UI::displayActionResult(character->getName(), target->getName(), damage);
        }
    } else if (action == 2) {  // ✨ Use Skill (Backliners can attack both lines)
        Character* target = selectTarget(character, true);
        if (target) {
            character->useSkill(*target);
        }
    } else if (action == 3) {  // ⚡ Focus (Regain MP)
        character->focus();
    }
}

Character* CombatSystem::getValidTarget(std::vector<Character*>& team, bool allowBackline) {
    std::vector<Character*> availableTargets;

    // ✅ Collect valid targets
    for (Character* target : team) {
        if (target->isAlive() && (allowBackline || target->isInFrontline())) {
            availableTargets.push_back(target);
        }
    }

    if (availableTargets.empty()) return nullptr;  // No valid targets

    // ✅ Display available targets
    std::cout << "Choose a target:\n";
    for (size_t i = 0; i < availableTargets.size(); ++i) {
        std::cout << i + 1 << ": " << availableTargets[i]->getName() 
                  << " (HP: " << availableTargets[i]->getHp() << ")\n";
    }

    int choice;
    std::cin >> choice;

    if (choice < 1 || choice > static_cast<int>(availableTargets.size())) {
        std::cout << "❌ Invalid selection! Choosing first available target.\n";
        return availableTargets[0];  // ✅ Default to first valid target
    }

    return availableTargets[choice - 1];
}



Character* CombatSystem::selectTarget(Character* attacker, bool isSkill) {
    // Determine the attacker's team and opponent team
    bool isPlayer1 = (std::find(playerTeam.begin(), playerTeam.end(), attacker) != playerTeam.end());
    std::vector<Character*>& opponentTeam = isPlayer1 ? enemyTeam : playerTeam;
    std::vector<Character*>& allyTeam = isPlayer1 ? playerTeam : enemyTeam;

    // ✅ Fix: Healer's skill must target allies
    if (attacker->isHealer() && isSkill) {
        return getValidTarget(allyTeam, true);  // ✅ Always allow all allies to be healed
    }

    // ✅ Check if the opponent's frontline is still alive
    bool frontlineAlive = false;
    for (Character* target : opponentTeam) {
        if (target->isAlive() && target->isInFrontline()) {
            frontlineAlive = true;
            break;
        }
    }

    // ✅ Restrict Frontliners from using skill on backline
    bool allowBackline = isSkill && attacker->isBackline();  // ✅ Only backline characters can target backline with skills
    if (!frontlineAlive) {
        allowBackline = true;  // ✅ If frontline is gone, all characters can attack backline
    }

    return getValidTarget(opponentTeam, allowBackline);
}
