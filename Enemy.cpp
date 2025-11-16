#include "Enemy.h"

int Enemy::enemyCount = 0;
Enemy::Enemy(std::string& name, int health, int damage) {
    this->name = name;
    this->health = health;
    this->maxHealth = health;
    this->damage = damage;
    enemyCount++;
}

int Enemy::getHealth() const {
    return this->health;
}

int Enemy::getMaxHealth() const {
    return this->maxHealth;
}

/**int Enemy::getEnemyCount() {
    return enemyCount;
}
**/

void Enemy::displayStatus() const {
    doDisplayStatus();
}

void Enemy::doDisplayStatus() const {
    std::cout << "Inamic: " << this->name << " | HP: " << this->health << "/" << this->maxHealth << std::endl;
}


