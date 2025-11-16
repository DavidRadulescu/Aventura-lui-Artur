#pragma once
#include "Enemy.h"

class Orc : public Enemy {
public:
    Orc();
    ~Orc() override = default;
    int attack() const override;
    void takeDamage(int dmg) override;
    std::unique_ptr<Enemy> clone() const override;
    std::string getName() const override;
    bool isAlive() const override;
protected:
    void doDisplayStatus() const override;
};
