//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066

#pragma once
#include "Manager.h"

enum Day /*define the days number starting with sunday its the day 1 to the day 7 that its saturday*/
{
	Sunday = 1,
	Monday,
	Tuesday, 
	Wednesday, 
	Thursday, 
	Friday, 
	Saturday
};

class Shop
{
	//Private features
	Manager manager; 
	string name;
	Day closedDay; 
	bool isOnline;

public:
	//Constructor 
	Shop(Manager manager= (0, "~", "~", 0), string name = "~", Day closedDay = Sunday, bool isOnline = false) : manager(manager), closedDay(closedDay), isOnline(isOnline)
	{
		if (name.length() <= 10) /*check if the name length is more than 10  characters */
		{
			this->name = name;
		}
		else
		{
			cout << "Shop name length is too long" << endl;
			this->name = "~";
		}
	}


	//Class get methods
	Manager getManager() const;
	string getName() const;
	int getClosedDay() const;
	bool getIsOnline() const;

	//Class set methods
	void setManager(const Manager& newManager);
	void setName(const string& newName);
	void setClosedDay(const Day& newClosedDay);
	void setIsOnline(const bool& newIsOnline);

	//Class print method
	void print() const;
};

