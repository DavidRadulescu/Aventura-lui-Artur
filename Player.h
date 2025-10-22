#pragma once
#include <iostream>
#include <string>
#include "HP.h"
#include "Inventory.h"
#include "Item.h"

class Player {
private:
    std::string name;
    std::string classType;
    int strength;
    int speed;
    int damage;
    int intelligence;
    HP health;
    Inventory inventory;

public:
    Player(const std::string& name, const std::string& classType, int strength, int speed, int damage, int maxHP = 100, int intelligence = 0);
    Player(const Player& other);
    Player& operator=(const Player& other);
    ~Player();

    void setClass(const std::string& cls);
    void setIntelligence(int intel);
    void setStrength(int str);
    void setSpeed(int spd);
    void setDamage(int dmg);

    std::string getClass() const;
    //int getIntelligence() const;
    //int getStrength() const;
    //int getSpeed() const;
    //int getDamage() const;

    void showStatus() const;
    int attack() const;
    void takeDamage(int dmg);
    bool addItemToInventory(const Item& newItem);
    void useItem(int index);
    bool isAlive() const;
    void showInventory() const;
    friend std::ostream& operator<<(std::ostream& out, const Player& p);
};
