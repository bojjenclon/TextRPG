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

		bool addItem(boost::shared_ptr<Item> item);
        void removeItem(int);
		void removeItem(boost::shared_ptr<Item> item);

		boost::shared_ptr<Item> getItem(int index);
		int getItemIndex(boost::shared_ptr<Item> item);

        int usePotion(int);

        /*std::string getParent(int);
        bool isEquipable(int);*/

        std::string toString();
    private:
        std::vector<boost::shared_ptr<Item>> items_;
};

#endif
