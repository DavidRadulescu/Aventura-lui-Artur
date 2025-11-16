#pragma once
#include "Enemy.h"

class Skeleton : public Enemy {
public:
    Skeleton();
    ~Skeleton() override = default;
    int attack() const override;
    void takeDamage(int dmg) override;
    std::string getName() const override;
    bool isAlive() const override;
    std::unique_ptr<Enemy> clone() const override;
protected:
    void doDisplayStatus() const override;
};