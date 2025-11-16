#include <iostream>
#include <string>
#include <memory>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "Player.h"
#include "Item.h"
#include "Enemy.h"
#include "Goblin.h"
#include "Orc.h"
#include "Dragon.h"
#include "GameExceps.h"
#include "Skeleton.h"

int main() {
    srand(time(0));
    std::string playerName;
    std::cout << "Introduceti numele jucatorului: ";
    std::getline(std::cin, playerName);

    std::cout << "Alegeti clasa: " << std::endl;
    std::cout << "1. Warrior (Strength 10, Speed 5, Damage 5, HP 120)" << std::endl;
    std::cout << "2. Rogue (Strength 5, Speed 10, Damage 4, HP 100)" << std::endl;
    std::cout << "3. Mage (Strength 3, Speed 7, Damage 6, HP 80, Intelligence 10)" << std::endl;

    int choice;
    while (!(std::cin >> choice) || choice < 1 || choice > 3) {
        if (std::cin.fail()) {
            std::cout << "Intrare invalida. Va rugam introduceti un numar (1, 2 sau 3): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cout << "Clasa invalida. Va rugam introduceti un numar valid (1, 2 sau 3): ";
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Player player(playerName, "", 0, 0, 0, 100, 0);

    switch(choice) {
        case 1:
            player = Player(playerName, "Warrior", 10, 5, 5, 120, 2);
        break;
        case 2:
            player = Player(playerName, "Rogue", 5, 10, 4, 100, 3);
        break;
        case 3:
            player = Player(playerName, "Mage", 3, 7, 6, 80, 10);
        break;
    }

    std::cout << "\nSalut, " << playerName << "! Ai ales clasa " << player.getClass() << "\n" << std::endl;
    try {
        player.addItemToInventory(Item("Health Potion", "Healing", 20));
        player.addItemToInventory(Item("Mana Potion", "Mana Refill", 10));
    } catch (const GameException& e) {
        std::cout << "Eroare la initializarea inventarului: " << e.what() << std::endl;
    }
    std::vector<std::unique_ptr<Enemy>> enemies;
    enemies.push_back(std::make_unique<Goblin>());
    enemies.push_back(std::make_unique<Skeleton>());
    enemies.push_back(std::make_unique<Orc>());
    enemies.push_back(std::make_unique<Dragon>());

    std::cout << "Inamicii se apropie! Pregateste-te de lupta!" << std::endl;

    while(player.isAlive() && !enemies.empty()) {
        std::unique_ptr<Enemy>& currentEnemy = enemies[0];

        std::cout << "\n-------------------------------------" << std::endl;
        std::cout << "Batalie cu " << currentEnemy->getName()
                  << " (HP: " << currentEnemy->getHealth()
                  << "/" << currentEnemy->getMaxHealth() << ")" << std::endl;
        std::cout << "Inamici ramasi: " << enemies.size() << std::endl;
        std::cout << "-------------------------------------" << std::endl;

        std::cout << "\nCe vrei sa faci?" << std::endl;
        std::cout << "1. Ataca inamicul" << std::endl;
        std::cout << "2. Foloseste un item" << std::endl;
        std::cout << "3. Vezi statusul tau" << std::endl;
        std::cout << "4. Vezi inventar" << std::endl;
        std::cout << "5. Termina jocul" << std::endl;
        std::cout << "Alege optiunea: ";

        int action;
        while (!(std::cin >> action)) {
            std::cout << "Intrare invalida. Va rugam introduceti un numar pentru actiune (1-5): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        try {
            switch(action) {
                case 1: {
                    int dmg = player.attack();
                    currentEnemy->takeDamage(dmg);
                    if(currentEnemy->isAlive()) {
                        int dmgTaken = currentEnemy->attack();
                        player.takeDamage(dmgTaken);
                    } else {
                        std::cout << "Ai invins inamicul: " << currentEnemy->getName() << "!" << std::endl;
                        enemies.erase(enemies.begin());
                        if (!enemies.empty()) {
                            std::cout << "Un nou inamic apare!" << std::endl;
                            int chance = rand() % 100;
                            if (chance < 40) {
                                std::cout << "Inainte de lupta, ai gasit un cufar!" << std::endl;
                                Item loot;
                                int lootType = rand() % 2;
                                if (lootType == 0) {
                                    loot = Item("Health Potion", "Healing", 20);
                                } else {
                                    loot = Item("Mana Potion", "Mana Refill", 10);
                                }
                                player.addItemToInventory(loot);
                            }
                        }
                    }
                    break;
                }
                case 2: {
                    player.showInventory();
                    std::cout << "Introdu index-ul itemului de folosit: ";
                    int index;
                    while (!(std::cin >> index)) {
                        std::cout << "Intrare invalida. Va rugam introduceti un numar: ";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    player.useItem(index);
                    break;
                }
                case 3:
                    player.showStatus();
                currentEnemy->displayStatus();
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
        catch (const GameException& e) {
            std::cout << "\n[EROARE] " << e.what() << std::endl;
            std::cout << "Te rugam sa incerci din nou." << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "\n[EROARE SISTEM] " << e.what() << std::endl;
        }
    }
    if(!player.isAlive()) {
        std::cout << "Ai murit. Joc terminat." << std::endl;
    }
    else if (enemies.empty()) {
        std::cout << "\nFELICITARI! Ai invins toti inamicii si ai castigat jocul!" << std::endl;
    }
}
