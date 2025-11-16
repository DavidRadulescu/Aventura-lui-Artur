#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton() : Enemy("Skeleton", 40, 7) {}

int Skeleton::attack() const {
    std::cout << this->name << " zdranganeste oasele si loveste cu o sabie ruginita, dând " << this->damage << " damage!" << std::endl;
    return this->damage;
}

void Skeleton::takeDamage(int dmg) {
    if (dmg < 0) return;
    int damageTaken = dmg + 3;
    this->health -= damageTaken;
    if (this->health < 0) {
        this->health = 0; 
    }
    std::cout << this->name << " primeste " << damageTaken << " damage! Oasele sale se imprastie. HP ramas: " << this->health << std::endl;
}

std::string Skeleton::getName() const {
    return this->name;
}

bool Skeleton::isAlive() const {
    return this->health > 0;
}

std::unique_ptr<Enemy> Skeleton::clone() const {
    return std::make_unique<Skeleton>(*this);
}

void Skeleton::doDisplayStatus() const {
    std::cout << "Un " << this->name << " reinviat! | HP: " << this->health << "/" << this->maxHealth << std::endl;
}