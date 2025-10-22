#pragma once
class HP {
private:
    int maxHP;
    int currentHP;
public:
    HP(int maxHP = 100);
    HP(const HP& other);
    HP& operator = (const HP& other);
    ~HP();

    bool setMaxHP(int newMaxHP);
    bool setHP(int newHP);
    void heal(int amount);
    int getMaxHP() const;
    int getCurrentHP() const;
    void takeDamage(int damage);
    bool isAlive() const;
    friend std::ostream& operator << (std::ostream& os, const HP& hp);
};
