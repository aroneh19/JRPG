# Turn-Based JRPG Battle System

## Table of Contents

1. [Introduction](#introduction)
2. [For Users](#for-users)
   - [Gameplay Overview](#gameplay-overview)
   - [Character Classes](#character-classes)
   - [Combat Mechanics](#combat-mechanics)
   - [How to Play](#how-to-play)
3. [For Programmers](#for-programmers)
   - [Design Overview](#design-overview)
   - [Class Hierarchy](#class-hierarchy)
   - [Key Features](#key-features)
   - [Extending the Game](#extending-the-game)
4. [Requirements](#requirements)
5. [How to Compile and Run](#how-to-compile-and-run)

---

## Introduction

This project is a turn-based battle system inspired by Japanese Role-Playing Games (JRPGs). Players can assemble a team of characters, each with unique abilities and stats, and engage in strategic battles against an AI-controlled team. The game features a variety of character classes, each with distinct skills and roles in combat.

---

## For Users

### Gameplay Overview

- **Objective**: Defeat the enemy team by reducing their HP to zero.
- **Teams**: Each team consists of up to 4 characters, with a mix of **Support** and **Champion** roles.
- **Turns**: Combat is turn-based, with the order determined by each character's SPD stat and a random modifier.
- **Actions**: On their turn, a character can:
  - **Attack**: Deal damage to an enemy.
  - **Use Skill**: Perform a unique ability (costs MP).
  - **Focus**: Restore MP but skip the turn.

### Character Classes

Each character class has unique stats and abilities:

| Class     | Role     | HP  | ATK | DEF | SPD | MP  | LCK | Skill         | Cost | Cooldown | Effect                                                           |
| --------- | -------- | --- | --- | --- | --- | --- | --- | ------------- | ---- | -------- | ---------------------------------------------------------------- |
| Berserker | Champion | 14  | 18  | 10  | 12  | 8   | 10  | Rage Strike   | 4 MP | 3 turns  | Deals 2x ATK damage. Berserker takes 10% recoil.                 |
| Paladin   | Champion | 16  | 10  | 18  | 10  | 12  | 10  | Shield Bash   | 3 MP | 2 turns  | Deals 1x ATK damage and reduces target's SPD by 20% for 2 turns. |
| Knight    | Champion | 14  | 14  | 14  | 12  | 10  | 10  | Royal Spear   | 5 MP | 4 turns  | Deals piercing damage (ignores DEF, but damage is halved).       |
| Monk      | Champion | 14  | 12  | 10  | 14  | 10  | 12  | Inner Peace   | 6 MP | 4 turns  | Restores 30% HP and removes all debuffs.                         |
| Archer    | Support  | 12  | 18  | 8   | 14  | 10  | 12  | Snipe Shot    | 5 MP | 3 turns  | Deals 2.5x ATK damage. Ignores targeting rules.                  |
| Assassin  | Support  | 8   | 18  | 4   | 16  | 8   | 16  | Shadow Strike | 5 MP | 3 turns  | Deals 2x ATK damage.                                             |
| Healer    | Support  | 16  | 8   | 8   | 10  | 18  | 12  | Healing Light | 4 MP | 0 turns  | Restores 30% HP to a single ally.                                |
| Mage      | Support  | 8   | 18  | 4   | 12  | 14  | 10  | Fireball      | 5 MP | 3 turns  | Deals 2x ATK damage.                                             |

### Combat Mechanics

- **Damage Calculation**:
  - `Damage = (ATK - DEF) * Role Ability * 1.5 * (LCK / 200) * Dodge Chance`
  - Minimum Damage: `ATK / 3`
- **Critical Hits**:
  - Chance: `LCK / 200`
- **Dodge Chance**:
  - `(LCK + SPD) / 200`
- **Targeting Rules**:
  - **Champions** must be attacked other **Champions** if they are still standing
  - **Support** may attack whoever

### How to Play

1. **Choose PVP/PVE**:
   - Computer selects random team setup to face against Player
2. **Team Selection**:
   - Choose up to 4 characters for your team, with a maximum of 2 **Support** and 2 **Champions**.
3. **Combat**:
   - On your turn, select an action (Attack, Skill, or Focus).
   - Follow the prompts to target enemies or allies.
4. **Victory**:
   - Defeat all enemies to win the battle.

---

## For Programmers

### Design Overview

The game is implemented in C++ and uses **inheritance** to model different character classes. Each character class inherits from a base `Character` class, which defines common attributes and methods. Polymorphism is used to handle unique skills and behaviors for each class.

### Class Hierarchy

- **Base Class**: `Character`
  - Attributes: `name`, `hp`, `atk`, `def`, `spd`, `mp`, `lck`, `isFrontline`
  - Methods: `attack`, `useSkill`, `focus`, `displayStats`, `reduceCooldown`, `isSkillReady`
- **Derived Classes**:
  - `Berserker`, `Paladin`, `Knight`, `Monk`, `Archer`, `Assassin`, `Healer`, `Mage`
  - Each class overrides `useSkill` and `displaySkills` to implement unique abilities.

### Key Features

- **Polymorphism**: Each character class has unique skills implemented through method overriding.
- **Turn Order**: Determined by `SPD` + random modifier (1-10).
- **Damage Calculation**: Includes modifiers for critical hits, dodge chance, and role abilities.
- **Cooldowns**: Skills have cooldowns to balance gameplay.

### Extending the Game

- **New Characters**:
  - Create a new class inheriting from `Character`.
  - Override `useSkill` and `displaySkills` to implement unique abilities.
- **New Mechanics**:
  - Add new stats (e.g., mana, energy).
  - Implement new damage types or resistances.
- **UI Improvements**:
  - Add ASCII art or a graphical interface.

---

## Requirements

- **C++ Compiler**: Supports C++17 or later.
- **Makefile**: Provided for easy compilation.
- **README**: This file, describing the game and its implementation.

---

## How to Compile and Run

1. **Clone the Repository**:

   ````bash
   git clone https://github.com/your-repo/jrpg-battle-system.git
   cd jrpg-battle-system```
   ````

2. **Compile and Run**:
   ```bash
       make
       ./RPG
   ```
