#include "Player.h"


Player::Player(std::string name, std::string classType, int strength, int speed, int damage, int maxHP) {
    this->name = name;
    this->classType = classType;
    this->strength = strength;
    this->speed = speed;
    this->damage = damage;
    HP tempHP(maxHP);
    this->health = tempHP;
    Inventory tempInv(10);
    this->inventory = tempInv;
}
Player::Player(const Player& other) {
    this->name = other.name;
    this->classType = other.classType;
    this->strength = other.strength;
    this->speed = other.speed;
    this->damage = other.damage;
    this->health = other.health;
    this->inventory = other.inventory;
}
Player& Player::operator=(const Player& other) {
    if (this != &other) {
        this->name = other.name;
        this->classType = other.classType;
        this->strength = other.strength;
        this->speed = other.speed;
        this->damage = other.damage;
        this->health = other.health;
        this->inventory = other.inventory;
    }
    return *this;
}
Player::~Player() {};


void Player::showStatus() const {
    std::cout << "Informatii caracter: " << std::endl;
    std::cout << "Nume: " << this->name << " (" << this->classType << ")" << std::endl;
    std::cout << "Strength: " << this->strength<< " | Speed: " << this->speed << " | Damage: " << this->damage << std::endl;
    std::cout << this->health << std::endl;
    this->inventory.showInventory();
}

int Player::attack() const {
    int totalDamage = this->damage + this->strength;
    std::cout << this->name << " ataca si da " << totalDamage << " damage!" << std::endl;
    return totalDamage;
}

void Player::takeDamage(int dmg) {
    std::cout << this->name << " primeste " << dmg << " damage!" << std::endl;
    this->health.takeDamage(dmg);
}

bool Player::addItemToInventory(const Item& newItem) {
    return this->inventory.addItem(newItem);
}

void Player::useItem(int index) {
    this->inventory.useItem(index);
}

bool Player::isAlive() const {
    return this->health.isAlive();
}

void Player::showInventory() const {
    this->inventory.showInventory();
}

void Player::setClass(const std::string& cls) {
    this->classType = cls;
}

void Player::setIntelligence(int intel) {
    this->intelligence = intel;
}

void Player::setStrength(int str) {
    this->strength = str;
}

void Player::setSpeed(int spd) {
    this->speed = spd;
}

void Player::setDamage(int dmg) {
    this->damage = dmg;
}

std::string Player::getClass() const {
    return this->classType;
}

int Player::getIntelligence() const {
    return this->intelligence;
}

int Player::getStrength() const {
    return this->strength;
}

int Player::getSpeed() const {
    return this->speed;
}

int Player::getDamage() const {
    return this->damage;
}

std::ostream& operator<<(std::ostream& out, const Player& p) {
    out << "Player: " << p.name << " (" << p.classType << ")";
    return out;
}
