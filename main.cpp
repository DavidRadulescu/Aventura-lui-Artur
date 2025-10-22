#include <iostream>
#include <string>
#include "Player.h"
#include "Item.h"

class Enemy {
private:
    std::string name;
    int health;
    int damage;
public:
    Enemy (std::string n, int hp, int dmg) : name(n), health(hp), damage(dmg) {}
    bool isAlive() const { return health > 0; }
    void takeDamage(int dmg) {
        health -= dmg;
        std::cout << name << " primeste " << dmg << " damage! HP ramas: " << health << std::endl;
    }
    int getHealth() const {
        return health;
    }
    int attack() const {
        std::cout << name << " ataca si da " << damage << " damage!" << std::endl;
        return damage;
    }
    std::string getName() const {
        return name;
    }
};

int main() {
    std::string playerName;
    std::cout << "Introduceti numele jucatorului: ";
    std::getline(std::cin, playerName);

    std::cout << "Alegeti clasa: " << std::endl;
    std::cout << "1. Warrior (Strength 10, Speed 5, Damage 5, HP 120)" << std::endl;
    std::cout << "2. Rogue (Strength 5, Speed 10, Damage 4, HP 100)" << std::endl;
    std::cout << "3. Mage (Strength 3, Speed 7, Damage 6, HP 80, Intelligence 10)" << std::endl;

    int choice;
    std::cin >> choice;

    Player player(playerName, "", 0, 0, 0); // temporary default stats

    switch(choice) {
        case 1:
            player.setClass("Warrior");
            player.setStrength(10);
            player.setSpeed(5);
            player.setDamage(5);
            player.setIntelligence(2);
            player = Player(playerName, "Warrior", 10, 5, 5, 120);
            break;
        case 2:
            player.setClass("Rogue");
            player.setStrength(5);
            player.setSpeed(10);
            player.setDamage(4);
            player.setIntelligence(3);
            player = Player(playerName, "Rogue", 5, 10, 4, 100);
            break;
        case 3:
            player.setClass("Mage");
            player.setStrength(3);
            player.setSpeed(7);
            player.setDamage(6);
            player.setIntelligence(10);
            player = Player(playerName, "Mage", 3, 7, 6, 80);
            break;
        default:
            std::cout << "Clasa invalida. Se va folosi Warrior default." << std::endl;
            player = Player(playerName, "Warrior", 10, 5, 5, 120);
            break;
    }

    std::cout << "\nSalut, " << playerName << "! Ai ales clasa " << player.getClass() << "\n" << std::endl;

    player.addItemToInventory(Item("Health Potion", "Healing", 20));
    player.addItemToInventory(Item("Mana Potion", "Mana Refill", 10));

    Enemy goblin("Goblin", 50, 8);

    while(player.isAlive() && goblin.isAlive()) {
        std::cout << "Batalie cu " << goblin.getName() << " (HP: " << goblin.getHealth() << ")" << std::endl;
        //player.showStatus();
        std::cout << "\nCe vrei sa faci?" << std::endl;
        std::cout << "1. Ataca inamicul" << std::endl;
        std::cout << "2. Foloseste un item" << std::endl;
        std::cout << "3. Vezi statusul tau" << std::endl;
        std::cout << "4. Vezi inventar" << std::endl;
        std::cout << "5. Termina jocul" << std::endl;
        std::cout << "Alege optiunea: ";

        int action;
        std::cin >> action;

        switch(action) {
            case 1: {
                int dmg = player.attack();
                goblin.takeDamage(dmg);
                if(goblin.isAlive()) {
                    int dmgTaken = goblin.attack();
                    player.takeDamage(dmgTaken);
                } else {
                    std::cout << "Ai invins inamicul!" << std::endl;
                }
                break;
            }
            case 2: {
                player.showInventory();
                std::cout << "Introdu index-ul itemului de folosit: ";
                int index;
                std::cin >> index;
                player.useItem(index);
                break;
            }
            case 3:
                player.showStatus();
                break;
            case 4:
                player.showInventory();
                break;
            case 5:
                std::cout << "Ai ales sa termini jocul.";
                return 0;
            default:
                std::cout << "Optiune invalida." << std::endl;
                break;
        }
    }

    if(!player.isAlive()) {
        std::cout << "Ai murit. Joc terminat." << std::endl;
    }

    return 0;
}
