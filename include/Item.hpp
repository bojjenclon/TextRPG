#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

#include <boost/smart_ptr/shared_ptr.hpp>

class Item {
    public:
        Item(const std::string& name, const std::string& id, const std::string& description);

        std::string getName();
        std::string getID();
        std::string getDescription();

        void setName(const std::string& name);
        void setID(const std::string& id);
        void setDescription(const std::string& description);

        std::string getParent();
        void setParent(const std::string& parent);

        bool isEquipable();
        void setEquipable(bool equipable);

        int use();

        bool equals(Item*& other);
        bool equals(Item& other);

        std::string toString();
		
    private:
        std::string name_;
        std::string id_;
        std::string description_;

        std::string parent_;

        bool equipable_;
};

typedef boost::shared_ptr<Item> ptrItem;

#endif
