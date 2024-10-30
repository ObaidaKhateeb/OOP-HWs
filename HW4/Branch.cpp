//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include "Branch.h"
#include "Computer.h"
#include "PeripheralDevice.h"

//Constructor
Branch::Branch(string location, int capacity) : location(location), capacity(capacity)
{
}

//Default constructor 
Branch::Branch() : location("~"), capacity(0)
{
}

//Destructor
Branch::~Branch()
{
    std::vector<Item*>::iterator i; 

    for (i = catalog.begin(); i != catalog.end(); ++i)
    {
        delete* i;
    }
}

//Copy constructor 
Branch::Branch(const Branch& other) : location(other.location), capacity(other.capacity)
{
}

//method to get the catalog of items in the branch . also returns the quantity of items 
std::vector<Item*> Branch::getCatalog() const 
{
    return catalog;
}

// to get the location of the branch
string Branch::getLocation() const
{
    return location;
}

//method to add an item 
void Branch::addItem(Item* item)
{

    if (find(catalog.begin(), catalog.end(), item) != catalog.end()) //checks if the item is already in the catalog
    {
        throw ExistingItemError();
    }

    if (catalog.size() >= capacity) //checks if the catalog is full
    {
        throw FullCatalogError();
    }

    catalog.push_back(item);

    if (typeid(*item) == typeid(Computer))
    {
        computers.push_back(dynamic_cast<Computer*>(item));
    }
}

//method that removes an item by its id 
Item* Branch::removeItem(int id)
{
    std::vector<Item*>::iterator i;
    Item* itemToRemove = nullptr;
    for (i = catalog.begin(); i != catalog.end(); ++i)
    {
        if ((*i)->getId() == id)
        {
            itemToRemove = *i;
            catalog.erase(i);
            break;
        }
    }

    if (itemToRemove == nullptr) //if not such item with the given id 
    {
        throw NonExistingItemError();
    }
    else
    {
        for (int k=0; k < computers.size(); ++k) //if it's a computer, it will remove it from the computers vector also
        {
            for (int i = 0; i < computers[k]->connected.size(); i++) { 
                computers[k]->connected.erase(std::remove(computers[k]->connected.begin(), computers[k]->connected.end(), itemToRemove));
            }
        }
        return itemToRemove;
    }
}

//method that returns the total value of the items in the branch's catalog
int Branch::getItemsSum() const 
{
    int sum = 0;
    std::vector<Item*>::const_iterator i;
    for (i = catalog.begin(); i != catalog.end(); ++i)
    {
        sum += (*i)->getPrice();
    }
    return sum;
}

//method that returns the number of items in the branch's catalog
int Branch::getSize() const 
{
    return catalog.size();

}
