#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>

class Character
{
protected:
    std::string name;
    int hp, maxHp, atk, def, spd, mp, lck;
    bool isFrontline;
    std::string type; 

public:
    Character(std::string name, int hp, int atk, int def, int spd, int mp, int lck, bool isFrontline, std::string type);

    virtual ~Character() = default;

    std::string getName() const;
    int getHp() const;
    int getMaxHp() const;
    int getAtk() const;
    int getDef() const;
    int getSpd() const;
    int getMp() const;
    int getLck() const;
    bool getIsFrontline() const;

    void setHp(int newHp);
    void setMp(int newMp);

    virtual void attack(Character &target);
    virtual void useSkill(Character &target);
    virtual void focus();

    virtual void displayStats() const;
    bool isAlive() const;

    virtual void displaySkills() const = 0;

    bool isInFrontline() const; 
    bool isBackline() const;
    bool isHealer() const;

};

#endif // CHARACTER_H