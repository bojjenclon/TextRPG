#include <string>

#include "Item.hpp"

Item::Item(const std::string& name, const std::string& id, const std::string& description) {
    name_ = name;
    id_ = id;
    description_ = description;

    parent_ = "object";

    equipable_ = false;
}

std::string Item::getName() {
    return name_;
}

std::string Item::getID() {
    return id_;
}

std::string Item::getDescription() {
    return description_;
}

void Item::setName(const std::string& name) {
    name_ == name;
}

void Item::setID(const std::string& id) {
    id_ = id;
}

void Item::setDescription(const std::string& description) {
    description_ = description;
}

std::string Item::getParent() {
    return parent_;
}

void Item::setParent(const std::string& parent) {
    parent_ = parent;
}

bool Item::isEquipable() {
    return equipable_;
}

void Item::setEquipable(bool equipable) {
    equipable_ = equipable;
}

int Item::use() {
    return -1;
}

bool Item::equals(Item*& other) {
    if (name_ == other->getName()) {
        return true;
    }

    return false;
}

bool Item::equals(Item& other) {
    if (name_ == other.getName()) {
        return true;
    }

    return false;
}

std::string Item::toString() {
    return getID() + ": " + getName() + ", " + getDescription();
}
