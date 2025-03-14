# Turn-Based RPG

## Player Guide

Welcome to our turn-based RPG! This game features strategic combat where two players build squads and battle against each other. While we planned to include a **PvE mode**, it wasn’t completed in time, so **only PvP is available**. Rarely, the game may **crash with a segmentation fault**, but if that happens, just restart and try again.

### **Gameplay Overview**
- **Turn-based combat**: Players take turns selecting actions.
- **Squad Selection**: Each player picks 2 **frontline** and 2 **backline** characters.
- **Targeting Rules**:
  - **Frontline characters** must attack the enemy **frontline first**.
  - **Backline characters** (except the Healer) can use skills to attack **anyone**.
  - **Archer, Mage, and Assassin** can bypass targeting rules with their skills.
  - **Healer** can only target allies with healing.

### **Character Classes**
Each class has unique strengths and weaknesses, so **building a balanced team** is key to victory.

#### **Frontline Fighters (Tanks & Melee)**
1. **Paladin** – High defense, solid support with **Shield Bash** (reduces enemy speed).
2. **Berserker** – High attack, but reckless. **Rage Strike** deals **huge damage** but causes recoil.
3. **Knight** – A well-rounded fighter with **Royal Spear**, which **pierces defense**.
4. **Monk** – Agile and resilient, can **heal itself** and remove debuffs.

#### **Backline Fighters (Ranged & Magic)**
5. **Archer** – Powerful ranged attacks with **Snipe Shot**, which **ignores targeting rules**.
6. **Mage** – Uses **Fireball** to deal **massive area damage**.
7. **Assassin** – The fastest character, using **Shadow Strike** to deal **lethal critical hits**.
8. **Healer** – The only dedicated support class, using **Healing Light** to restore **allies' HP**.

### **Combat Mechanics**
- **Damage Formula**: `(ATK – DEF) * Role Ability * 1.5 (LCK) * Dodge Chance`
- **Minimum Damage**: **ATK // 3**
- **Critical Chance**: **LCK / 200**
- **Dodge Chance**: **(LCK + SPD) / 200**
- **MP Regeneration**: Characters **regenerate 1 MP per turn**.
- **Actions Per Turn**:
  1. **Attack** – Basic attack (scales from ATK).
  2. **Skill** – Special ability (uses MP).
  3. **Focus** – Restores MP but skips turn.

---

## Developer Notes

## Project Structure

The project is organized into different folders for clarity and maintainability:

- **`/src`** - Contains all source code files.
  - **`Characters/`** - Houses all character-related classes.
    - **`Base/`** - Contains the base `Character` class, which all characters inherit from.
    - **`Paladin/`**, **`Berserker/`**, **`Monk/`**, etc. - Each character class is in its own folder.
  - **`Combat/`** - Handles all battle mechanics.
    - **`CombatSystem.cpp`** - Manages the overall combat flow.
    - **`TurnOrder.cpp`** - Determines the turn sequence.
    - **`DamageCalculator.cpp`** - Calculates attack damage.
  - **`Game/`** - Controls game logic.
    - **`Game.cpp`** - Manages player squad selection and game start.
  - **`UI/`** - Handles user interaction.
    - **`UI.cpp`** - Displays game menus and in-game prompts.
  - **`Utils/`** - Utility functions (e.g., random number generation).
  - **`main.cpp`** - The entry point of the game.

This structure keeps the project modular and easy to manage.



### **Key Components**
- **Game.cpp**: Handles **player selection** and **game loop**.
- **CombatSystem.cpp**: Controls **turn-based combat** and **action handling**.
- **TurnOrder.cpp**: Ensures characters **act in order based on speed**.
- **Character Classes**: Each character class is in its own folder and **inherits from `Character`**.
- **UI.cpp**: Displays menus and updates during combat.

### **Known Issues**
- **PvE Mode is incomplete**, so it’s not functional.
- **Rare Segmentation Faults** may occur. If the game crashes, **restart and try again**.

