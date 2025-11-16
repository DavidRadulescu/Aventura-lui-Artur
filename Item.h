#pragma once
#include <iostream>
#include <ostream>
#include <string>

class Item {
private:
    std::string name;
    std::string type;
    int effectValue;
public:
    Item();
    explicit Item(const std::string& name, const std::string& type, int effectValue);
    Item(const Item& other);

    Item& operator = (const Item& other);
    ~Item();
    std::string getName () const;
    std::string getType() const;
    int getEffectValue() const;
    //void use() const;
    friend std::ostream& operator << (std::ostream& os, const Item& item);
};



