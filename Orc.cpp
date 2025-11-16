#include "Orc.h"
#include <iostream>

Orc::Orc() : Enemy("Orc", 80, 12) {}

int Orc::attack() const {
    std::cout << this->name << " loveste crunt si da " << this->damage << " damage!" << std::endl;
    return this->damage;
}

std::string Orc::getName() const {
    return this->name;
}

bool Orc::isAlive() const {
    return this->health > 0;
}

void Orc::takeDamage(int dmg) {
    if (dmg < 0) return;
    int damageTaken = dmg - 2;
    if (damageTaken < 0) {
        damageTaken = 0;
    }
    this->health -= damageTaken;
    if (this->health < 0) {
        this->health = 0;
    }
    std::cout << this->name << " primeste " << damageTaken << " damage! HP ramas: " << this->health << std::endl;
}

std::unique_ptr<Enemy> Orc::clone() const {
    return std::make_unique<Orc>(*this);
}

void Orc::doDisplayStatus() const {
    std::cout << "Un " << this->name << " masiv! | HP: " << this->health << "/" << this->maxHealth << std::endl;
}
