#include "Goblin.h"
#include <iostream>

Goblin::Goblin() : Enemy("Goblin", 50, 8){}
int Goblin::attack() const {
    std::cout << this->name << " ataca si da " << this->damage << " damage!" << std::endl;
    return this->damage;
}

std::string Goblin::getName() const {
    return this->name;
}

bool Goblin::isAlive() const {
    return this->health > 0;
}

void Goblin::takeDamage(int dmg) {
    if (dmg < 0) return;
    this->health -= dmg;
    if (this->health < 0) {
        this->health = 0;
    }
    std::cout << this->name << " primeste " << dmg << " damage! HP ramas: " << this->health << std::endl;
}

std::unique_ptr<Enemy> Goblin::clone() const {
    return std::make_unique<Goblin>(*this);
}

void Goblin::doDisplayStatus() const {
    std::cout << "Un " << this->name << "! | HP: " << this->health << "/" << this->maxHealth << std::endl;
}