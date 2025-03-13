#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>

class Character
{
protected:
    std::string name;
    int hp;
    int maxHp, atk, spatk, def, spdef, spd, mp, lck;
    bool isFrontline;

public:
    Character(std::string name, int hp, int atk, int spatk, int def, int spdef, int spd, int mp, int lck, bool isFrontline);

    virtual ~Character() = default;

    std::string getName() const;
    int getHp() const;
    int getMaxHp() const;
    int getAtk() const;
    int getSpatk() const;
    int getDef() const;
    int getSpdef() const;
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
};

#endif // CHARACTER_H