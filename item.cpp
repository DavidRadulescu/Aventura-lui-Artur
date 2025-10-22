#include "item.h"
#include <string>

Item::Item() = default;

Item::Item(const std::string& name, const std::string& type, int effectValue) {
    this->name = name;
    this->type = type;
    this->effectValue = effectValue;
}
Item::Item(const Item& other) {
    this->name = other.name;
    this->type = other.type;
    this->effectValue = other.effectValue;
}
Item& Item::operator = (const Item& other) {
    if (this != &other) {
        this->name = other.name;
        this->type = other.type;
        this->effectValue = other.effectValue;
    }
    return *this;
}

Item::~Item() = default;

std::string Item::getName() const {
    return this->name;
}
std::string Item::getType() const {
    return this->type;
}
int Item::getEffectValue() const {
    return this->effectValue;
}
void Item::use() const {
    std::cout << "Folosesti item-ul " << this->name << " (" << this->type << ") cu adaosul de: " << this->effectValue << std::endl;
}

std::ostream& operator << (std::ostream& os, const Item& item) {
    os << "[" << item.name << "] Tip: " << item.type << " Efect: " << item.effectValue;
    return os;
}