//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include "Item.h"
#include "HWExceptions.h"
#include "Computer.h"
#include <vector>
#include <algorithm>

//Branch class
class Branch
{
	std::vector<Item*> catalog; //An Array of Item pointers, the store's item catalog 
	int capacity; //integer to keep track of the current quantity of items in the catalog
	string location; //String that holds the branch location

	std::vector<Computer*> computers; //An Array of Computers pointers

public:
	Branch(std::string location, int capacity); //Constructor
	Branch(); // Default constructor
	~Branch(); //Destructor
	Branch(const Branch& other); //Copy constructor

	std::vector<Item*> getCatalog() const;  //to get the catalog of items in the branch
	string getLocation() const; //get the loaction of teh branch

	void addItem(Item* item); //add an item to the catalog
	Item* removeItem(int id); //remove item by id 

	int getItemsSum() const; //returns the total value of the items in the branch's catalog
	int getSize() const; //returns the number of items in the branch's catalog

	template<class T>
	T* giveMeFinest(T* item) const //A function that accept a pointer of item and return a pointer to same type item with the highest price in the branch catalog
	{
		int highPrice = 0;
		T* highItem = NULL;
		for (int i = 0; i < catalog.size(); i++)
		{
			if (typeid(*catalog[i]) == typeid(*item)) //check if the catalog item is the same type as the accepted item 
			{
				if (catalog[i]->getPrice() > highPrice)
				{
					highPrice = catalog[i]->getPrice();
					(highItem) = (dynamic_cast<T*>(catalog[i]));
				}
			}
		}
		if (highItem) //if there's an item in the catalog of the same type as the accepted item then it will return it, otherwise it will throw error
		{
			if (dynamic_cast<T*>(highItem))
				return highItem;
		}
		else
		{
			throw NoneExistingItemTypeError();
		}
	}
};

