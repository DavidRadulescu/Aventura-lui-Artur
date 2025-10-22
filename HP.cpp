#include <iostream>
#include "HP.h"

HP::HP(int maxHP) {
    this->maxHP = maxHP;
    this->currentHP = maxHP;
}
HP::HP(const HP& other) {
    this->maxHP = other.maxHP;
    this->currentHP = other.currentHP;
}
HP& HP::operator = (const HP& other) {
    if (this != &other) {
        this->maxHP = other.maxHP;
        this->currentHP = other.currentHP;
    }
    return *this;
}

HP::~HP() = default;

bool HP::setMaxHP(int newMaxHP) {
    if (newMaxHP < 1)
        return false;
    this->maxHP = newMaxHP;
    if (this->currentHP > this->maxHP)
        this->currentHP = this->maxHP;
    return true;
}

bool HP::setHP (int newHP) {
    if (newHP < 1)
        return false;
    this->currentHP = newHP;
    return true;
}

void HP::heal(int amount) {
    if (amount == 0)
        return;
    this->currentHP += amount;
    if (this->currentHP > this->maxHP)
        this->currentHP = this->maxHP;
}

int HP::getMaxHP () const {
    return this->maxHP;
}

int HP::getCurrentHP() const{
    return this->currentHP;
}
void HP::takeDamage (int damage) {
    if (damage < 0)
        return;
    this->currentHP -= damage;
    if (this->currentHP <= 0)
        this->currentHP = 0;
}
bool HP::isAlive () const {
    if (this->currentHP <= 0)
        return false;
    return true;
}
std::ostream& operator<<(std::ostream& os, const HP& hp) {
    os << "HP: " << hp.getCurrentHP() << "/" << hp.getMaxHP();
    return os;
}

