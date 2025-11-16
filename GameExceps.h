#pragma once

#include <stdexcept>
#include <string>

class GameException : public std::runtime_error {
public:
    explicit GameException(const std::string& message) : std::runtime_error(message) {}
};

class InventoryFullException : public GameException {
public:
    explicit InventoryFullException(const std::string& message) : GameException(message) {}
};

class InvalidItemException : public GameException {
public:
    explicit InvalidItemException(const std::string& message) : GameException(message) {}
};

class CombatException : public GameException {
public:
    explicit CombatException(const std::string& message) : GameException(message) {}
};