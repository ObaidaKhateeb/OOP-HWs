//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include "Item.h"
#define BRANCH_SIZE 10
//Branch class
class Branch
{
    Item* catalog[BRANCH_SIZE]; //An Array of Item pointers, the store's item catalog 
    int quantity; //integer to keep track of the current quantity of items in the catalog
    string location;

public:
    Branch(string location); //Constructor
    ~Branch(); //Destructor

    Item** getCatalog(int& num);  //to get the catalog of items in the branch, also returns the quantity of items
    string getLocation() const; //get the loaction of teh branch
    void setLocation(const string& location); //set the location

    void addItem(Item* item); //add an item to the catalog
};

