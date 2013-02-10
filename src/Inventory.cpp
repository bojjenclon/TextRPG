#include <sstream>

#include "Inventory.hpp"
#include "Potion.hpp"

Inventory::Inventory(int maxSize) {
	items_.reserve(maxSize);
}

int Inventory::getMaxSize() {
	return items_.capacity();
}
void Inventory::setMaxSize(int maxSize) {
	items_.reserve(maxSize);
}
void Inventory::modMaxSize(int mod) {
	items_.reserve(items_.capacity() + mod);
}

int Inventory::getNumItems() {
    return items_.size();
}

bool Inventory::addItem(boost::shared_ptr<Item> item) {
	if (items_.size() < items_.capacity()) {
        items_.push_back(item);

        return true;
    }

    return false;
}

void Inventory::removeItem(int index) {
    items_.erase(items_.begin() + index);
}

void Inventory::removeItem(boost::shared_ptr<Item> item) { 
   for (unsigned int i = 0; i < items_.size(); i++) {
        if (items_[i]->equals(*item.get())) {
            items_.erase(items_.begin() + i);

            i--;
        }
    }
}

boost::shared_ptr<Item> Inventory::getItem(int index) {
    return items_[index];
}

int Inventory::getItemIndex(boost::shared_ptr<Item> item) {
    for (unsigned int i = 0; i < items_.size(); i++) {
        if (items_[i]->equals(*item.get())) {
            return i;
        }
    }

    return -1;
}

int Inventory::usePotion(unsigned int index) {
	if (index > 0 && index < items_.size()) {
		int resto = items_[index]->use();

		items_.erase(items_.begin() + index);

		return resto;
	}
	
	return -1;
}

/*std::string Inventory::getParent(int index) {
    return items_[index]->getParent();
}

bool Inventory::isEquipable(int index) {
    return items_[index]->isEquipable();
}*/

std::string Inventory::toString() {
    if (items_.size() > 0) {
        std::stringstream ss;

        for (unsigned int i = 0; i < items_.size(); i++) {
            ss << i + 1 << ": " << items_[i]->toString();

            if (i < items_.size() - 1) {
                ss << "\n";
            }
        }

        return ss.str();
    }

    return "Empty";
}

