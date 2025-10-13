#pragma once
#include "Item.h"
#include <iostream>
#include <vector>

class Inventory {
private:
    std::vector<Item> items;
    int maxSize;
public:
    Inventory(int maxSize = 10);
    Inventory(const Inventory& other);
    Inventory& operator=(const Inventory& other);
    ~Inventory();

    bool addItem(const Item& newItem);
    bool removeItem(int index);
    bool useItem(int index);
    bool showInventory() const;
    int getItemCount() const;

    friend std::ostream& operator<<(std::ostream& os, const Inventory& inv);
};
