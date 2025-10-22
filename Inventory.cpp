#include "Inventory.h"

Inventory::Inventory(int maxSize) {
    this->maxSize = maxSize;
}

Inventory::Inventory(const Inventory& other) {
    this->maxSize = other.maxSize;
    this->items = other.items;
}

Inventory& Inventory::operator = (const Inventory& other) {
    if (this != &other) {
        this->maxSize = other.maxSize;
        this->items = other.items;
    }
    return *this;
}

Inventory::~Inventory() = default;

bool Inventory::addItem(const Item& newItem) {
    if ((int)this->items.size() == this->maxSize) {
        std::cout << "Inventarul este plin!" << std::endl;
        return false;
    }
    this->items.push_back(newItem);
    std::cout << "Ai adaugat item-ul " << newItem.getName() << std::endl;
    return true;
}

/**bool Inventory::removeItem(int index) {
    if (index < 0 || index >= (int)this->items.size()) {
        std::cout << "Nu ai ales un item valid" << std::endl;
        return false;
    }
    std::cout << "Ai eliminat item-ul " << this->items[index].getName() << std::endl;
    this->items.erase(this->items.begin() + index);
    return true;
}**/

Item Inventory::useItem(int index) {
    index = index - 1;
    if (index < 0 || index >= (int)this->items.size()) {
        std::cout << "Nu ai ales un item valid" << std::endl;
        return Item("", "", 0);
    }
    Item usedItem = this->items[index];
    this->items.erase(this->items.begin() + index);
    std::cout << "Ai eliminat item-ul " << usedItem.getName() << " din inventar." << std::endl;
    return usedItem;
}

bool Inventory::showInventory() const {
    if (this->items.empty()) {
        std::cout << "Nu ai iteme" << std::endl;
        return false;
    }
    for (int i = 0; i < (int)this->items.size(); i++)
        std::cout << i + 1 << ". " << this->items[i] << std::endl;
    return true;
}

/**
int Inventory::getItemCount() const {
    return (int)this->items.size();
}
**/

std::ostream& operator<<(std::ostream& os, const Inventory& inv) {
    os << "Inventory (" << inv.items.size() << "/" << inv.maxSize << ")";
    return os;
}
