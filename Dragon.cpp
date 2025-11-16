#include "Dragon.h"
#include <iostream>

Dragon::Dragon() : Enemy("Dragon", 150, 20) {}

int Dragon::attack() const {
    std::cout << this->name << " sufla flacari si da " << this->damage << " damage!" << std::endl;
    return this->damage;
}

std::string Dragon::getName() const {
    return this->name;
}

bool Dragon::isAlive() const {
    return this->health > 0;
}

void Dragon::takeDamage(int dmg) {
    if (dmg < 0) return;
    int damageTaken = dmg - 5; 
    if (damageTaken < 0) {
        damageTaken = 0; 
    }
    this->health -= damageTaken;
    if (this->health < 0) {
        this->health = 0; 
    }
    std::cout << this->name << " primeste " << damageTaken << " damage! Solzii sai grosi au blocat o parte. HP ramas: " << this->health << std::endl;
}

std::unique_ptr<Enemy> Dragon::clone() const {
    return std::make_unique<Dragon>(*this);
}

void Dragon::doDisplayStatus() const {
    std::cout << "Un " << this->name << " magnific! | HP: " << this->health << "/" << this->maxHealth << std::endl;
}