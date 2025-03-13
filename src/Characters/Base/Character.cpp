#include "Character.h"
#include <iostream>

Character::Character(std::string name, int hp, int atk, int spatk, int def, int spdef, int spd, int mp, int lck, bool isFrontline)
    : name(name), hp(hp), maxHp(hp), atk(atk), spatk(spatk), def(def), spdef(spdef), spd(spd), mp(mp), lck(lck), isFrontline(isFrontline) {}

std::string Character::getName() const { return name; }
int Character::getHp() const { return hp; }
int Character::getMaxHp() const { return maxHp; }
int Character::getAtk() const { return atk; }
int Character::getSpatk() const { return spatk; }
int Character::getDef() const { return def; }
int Character::getSpdef() const { return spdef; }
int Character::getSpd() const { return spd; }
int Character::getMp() const { return mp; }
int Character::getLck() const { return lck; }
bool Character::getIsFrontline() const { return isFrontline; }

void Character::setHp(int newHp)
{
    hp = newHp;
    if (hp < 0)
        hp = 0;
    if (hp > maxHp)
        hp = maxHp;
}

void Character::setMp(int newMp)
{
    mp = newMp;
    if (mp < 0)
        mp = 0;
}

void Character::attack(Character &target)
{
    int damage = (atk - target.getDef());
    if (damage < atk / 3)
        damage = atk / 3;
    target.setHp(target.getHp() - damage);
    std::cout << name << " attacks " << target.getName() << " for " << damage << " damage!\n";
}

void Character::useSkill(Character &target)
{
    std::cout << name << " uses a skill!\n";
}

void Character::useSkill2(Character &target)
{
    std::cout << name << " uses a skill!\n";
}

void Character::focus()
{
    mp += 2;
}

void Character::displayStats() const
{
    std::cout << "Name: " << name << "\n";
}
