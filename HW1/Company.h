//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066

#pragma once
#define MAX_SHOPS_NUMBER 10
#include "Shop.h"

class Company
{
	//Private features
	string name;
	Shop shops[MAX_SHOPS_NUMBER];
	int shopsNumber; 

public:
	//Constructor 
	Company(string name = "~", int shopsNumber = 0) : shopsNumber(shopsNumber) /*company Constructor */
	{ 
		if (name.length() <= 10) /*we check if the name length is more than 10 characters , the name length should not be more than 10 characters */
		{
			this->name = name;
		}
		else
		{
			cout << "Company name length is too long" << endl;
			this->name = "~";
		}
	}

	//Class get methods
	string getName() const;
	int getShopsNumber() const; 

	//Class set methods
	void setName(const string& newName);

	//Class other methods
	void addShop(const Shop& newShop);
	void printShopsByName();
	void printShopsByDay();
};

