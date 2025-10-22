#include "Player.h"

Player::Player(const std::string& name, const std::string& classType, int strength, int speed, int damage, int maxHP, int intelligence) {
    this->name = name;
    this->classType = classType;
    this->strength = strength;
    this->speed = speed;
    this->damage = damage;
    this->intelligence = intelligence;
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
    this->intelligence = other.intelligence;
}
Player& Player::operator = (const Player& other) {
    if (this != &other) {
        this->name = other.name;
        this->classType = other.classType;
        this->strength = other.strength;
        this->speed = other.speed;
        this->damage = other.damage;
        this->health = other.health;
        this->inventory = other.inventory;
        this->intelligence = other.intelligence;
    }
    return *this;
}
Player::~Player() = default;


void Player::showStatus() const {
    std::cout << "Informatii caracter: " << std::endl;
    std::cout << "Nume: " << this->name << " (" << this->classType << ")" << std::endl;
    std::cout << "Strength: " << this->strength<< " | Speed: " << this->speed << " | Damage: " << this->damage << " | Intelligence: " << this->intelligence << std::endl;
    std::cout << this->health << std::endl;
}

int Player::attack() const {
    int totalDamage = this->damage + this->strength;
    totalDamage += this->intelligence / 4;
    bool isCritical = (rand() % 100) < (this->intelligence * 2);
    if (isCritical) {
        totalDamage *= 2;
        std::cout << this->name << " a nimerit o CRITICA si da " << totalDamage << " damage!" << std::endl;
    }
    else
        std::cout << this->name << " ataca si da " << totalDamage << " damage!" << std::endl;
    return totalDamage;
}

void Player::takeDamage(int dmg) {
    bool didDodge = (rand() % 100) < (this->speed * 3);
    if (didDodge) {
        dmg /= 2;
        std::cout << this->name << " EVITA partial atacul!" << std::endl;
    }
    std::cout << this->name << " primeste " << dmg << " damage!" << std::endl;
    this->health.takeDamage(dmg);
}

bool Player::addItemToInventory(const Item& newItem) {
    return this->inventory.addItem(newItem);
}

void Player::useItem(int index) {
    Item usedItem = this->inventory.useItem(index);
    if (usedItem.getName() == "Unknown")
        return;
    if (usedItem.getType() == "Healing") {
        std::cout << "Aplic efectul de vindecare: +" << usedItem.getEffectValue() << " HP." << std::endl;
        this->health.heal(usedItem.getEffectValue());
        std::cout << "HP-ul tau este acum: " << this->health << std::endl;
    }
    else {
        std::cout << "Itemul " << usedItem.getName() << "nu are un efect definit." << std::endl;
    }
    //this->inventory.useItem(index);
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

/**
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
**/

std::ostream& operator<<(std::ostream& out, const Player& p) {
    out << "Player: " << p.name << " (" << p.classType << ")";
    return out;
}
