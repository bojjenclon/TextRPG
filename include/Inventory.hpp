#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>

#include <boost/smart_ptr/shared_ptr.hpp>

#include "Item.hpp"

class Inventory {
    public:
        Inventory(int maxSize);

        int getMaxSize();
        void setMaxSize(int);
        void modMaxSize(int);
		
		int getNumItems();

		bool addItem(ptrItem item);
        void removeItem(int);
		void removeItem(ptrItem item);

		ptrItem getItem(int index);
		int getItemIndex(ptrItem item);

        int usePotion(int);

        std::string toString();
    private:
        std::vector<ptrItem> items_;
};

typedef boost::shared_ptr<Inventory> ptrInventory;

#endif
