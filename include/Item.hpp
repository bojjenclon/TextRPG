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

        void setName(const std::string&);
        void setID(const std::string&);
        void setDescription(const std::string&);

        std::string getParent();
        void setParent(const std::string&);

        bool isEquipable();
        void setEquipable(bool);

        int use();

        bool equals(Item*&);
        bool equals(Item&);

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
