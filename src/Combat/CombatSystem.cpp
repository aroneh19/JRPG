#include "CombatSystem.h"
#include "TurnOrder.h"
#include "DamageCalculator.h"
#include "../ui/Ui.h"
#include <iostream>
#include <algorithm>

CombatSystem::CombatSystem(std::vector<Character*>& playerTeam, std::vector<Character*>& enemyTeam)
    : playerTeam(playerTeam), enemyTeam(enemyTeam) {}  // ✅ Constructor Definition


void CombatSystem::startCombat() {
    std::cout << "🚀 Battle begins! Checking teams...\n";

    std::cout << "✅ Player 1's Team:\n";
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
    std::cout << character->getName() << "'s turn!\n";

    int action;
    std::cout << "Choose an action (1: Attack, 2: Use Skill, 3: Focus): ";
    std::cin >> action;

    if (action == 1) {  // 🏹 Attack
        Character* target = selectTarget(character, false);  // Target enemy team
        if (target) {
            int damage = DamageCalculator::calculateDamage(*character, *target);
            target->setHp(target->getHp() - damage);
            UI::displayActionResult(character->getName(), target->getName(), damage);
        }
    } else if (action == 2) {  // ✨ Use Skill (Healing or other effects)
        // ✅ Check if the character is a Healer
        if (character->getName() == "Healer") {
            Character* target = selectTarget(character, true);  // Target **own** team for healing
            if (target) {
                character->useSkill(*target);
            }
        } else {  // Normal skill usage targets enemies
            Character* target = selectTarget(character, false);
            if (target) {
                character->useSkill(*target);
            }
        }
    } else if (action == 3) {  // ⚡ Focus (Regain MP)
        character->focus();
    }
}


Character* CombatSystem::selectTarget(Character* attacker, bool selectAlly) {
    // ✅ Determine which team the attacker is on
    bool isPlayer1 = (std::find(playerTeam.begin(), playerTeam.end(), attacker) != playerTeam.end());
    
    // ✅ Select the correct target team
    std::vector<Character*>& targetTeam = selectAlly ? (isPlayer1 ? playerTeam : enemyTeam)
                                                     : (isPlayer1 ? enemyTeam : playerTeam);

    std::vector<Character*> frontliners;
    std::vector<Character*> backliners;

    // ✅ Separate frontliners and backliners
    for (Character* c : targetTeam) {
        if (c->getIsFrontline() && c->getHp() > 0) {
            frontliners.push_back(c);
        } else if (!c->getIsFrontline() && c->getHp() > 0) {
            backliners.push_back(c);
        }
    }

    // ✅ Choose available targets (Frontliners first, unless healing)
    std::vector<Character*>& availableTargets = (selectAlly || frontliners.empty()) ? targetTeam : frontliners;

    if (availableTargets.empty()) {
        std::cout << "⚠️ No valid targets! Skipping turn...\n";
        return nullptr;
    }

    // ✅ Display available targets
    std::cout << "🔍 Choose a target:\n";
    for (size_t i = 0; i < availableTargets.size(); ++i) {
        std::cout << i + 1 << ": " << availableTargets[i]->getName() 
                  << " (HP: " << availableTargets[i]->getHp() << ")\n";
    }

    int choice;
    std::cin >> choice;

    // ✅ Validate input
    if (choice < 1 || choice > static_cast<int>(availableTargets.size())) {
        std::cout << "❌ Invalid selection! Choosing first available target.\n";
        return availableTargets[0];  // ✅ Return first valid target
    }

    return availableTargets[choice - 1]; // ✅ Return selected target
}
