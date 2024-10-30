//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include "Branch.h"
//Constructor
Branch::Branch(string location) : location(location)
{
    quantity = 0;
    for (int i = 0; i < BRANCH_SIZE; i++)
    {
        catalog[i] = NULL;
    }
}
//Destructor
Branch::~Branch()
{
    for (int i = 0; i < BRANCH_SIZE; i++)
    {
        delete catalog[i];
    }
}
//Function to get the catalog of items in the branch . also returns the quantity of items 
Item** Branch::getCatalog(int& num)
{
    num = quantity;
    return catalog;
}

// to get the location of the branch
string Branch::getLocation() const
{
    return location;
}
// to set the location 
void Branch::setLocation(const std::string& location)
{
    this->location = location;
}
//method to add an item 
void Branch::addItem(Item* item)
{
    if (quantity == BRANCH_SIZE) //checks if the array if full
    {
        delete catalog[0]; //deleting the oldest item
        quantity--;
        for (int i = 0; i < quantity - 1; i++)
        {
            catalog[i] = catalog[i + 1];
        }
    }
    catalog[quantity] = item;
    quantity++;
}
