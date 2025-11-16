#pragma once

#include <string>
#include <iostream>
#include <memory>

class Enemy {
protected:
    std::string name;
    int health;
    int maxHealth;
    int damage;
    virtual void doDisplayStatus() const;
public:
    Enemy (std::string name, int health, int damage);
    int getHealth() const;
    int getMaxHealth() const;
    virtual ~Enemy() = default;
    virtual int attack() const = 0;
    virtual void takeDamage(int dmg) = 0;
    virtual std::string getName() const = 0;
    virtual bool isAlive() const = 0;
    virtual std::unique_ptr<Enemy> clone() const = 0;
    void displayStatus() const;
    static int getEnemyCount();
private:
    static int enemyCount;
};
