//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066

#include "Shop.h"

//Class get methods
Manager Shop::getManager() const /*Function to return the manager*/
{
	return this->manager;
}
string Shop::getName() const /*Function to return the Name*/
{
	return this->name;
}
int Shop::getClosedDay() const /*Function to return the Closed Day*/
{
	return this->closedDay;
}
bool Shop::getIsOnline() const /*Function to return the Online Status*/
{
	return this->isOnline;
}

//Class set methods
void Shop::setManager(const Manager& newManager) /*set for the manager*/
{
	this->manager = newManager;
}
void Shop::setName(const string& newName) /*set for the name */
{
	if (newName.length() <= 10)
	{
		this->name = newName;
	}
	else
	{
		cout << "Shop name length is too long" << endl;
		this->name = "~"; 
	}
}
void Shop::setClosedDay(const Day& newClosedDay) /*set for the Closed Day*/
{
	this->closedDay = newClosedDay;
}
void Shop::setIsOnline(const bool& newIsOnline)
{
	this->isOnline = newIsOnline;
}


//Class print method
void Shop::print() const /*Function used to print the Shop and the manager detailes */
{
	cout << "Printing shop: " << endl;
	cout << "Printing manager: " << endl; 
	cout << "Id : " << manager.getId() << endl;
	cout << "First name : " << manager.getFirstName() << endl;
	cout << "Last name : " << manager.getLastName() << endl;
	cout << "Birth year : " << manager.getBirthYear() << endl;
	cout << "Name : " << this->name << endl;
	//cout << "Closed day : " << this->closedDay << endl;
	switch (this->closedDay) { /*printing the closed Day respectivly to the number of the day , starting the with Sunday is the day nimber one */
	case 1:
		cout << "Closed day: Sunday" << endl;
		break;
	case 2:
		cout << "Closed day: Monday" << endl;
		break;
	case 3:
		cout << "Closed day: Tuesday" << endl;
		break;
	case 4:
		cout << "Closed day : Wednesday" << endl;
		break;
	case 5:
		cout << "Closed day : Thursday" << endl;
		break;
	case 6:
		cout << "Closed day: Friday" << endl;
		break;
	case 7:
		cout << "Closed day: Saturday" << endl;
		break;
	}
	//cout << "Is Online : " << this->isOnline << endl;
	switch (this->isOnline) { /*printing the Online Status respectivly to the number , 0 its falase , 1 its true*/
	case 0:
		cout << "Is Online : False" << endl;
		break;
	case 1:
		cout << "Is Online : True " << endl;
		break;
	}
}