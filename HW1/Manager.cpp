//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066

#include "Manager.h"

//Class get methods
int Manager::getId() const /*function to return the ID */
{
	return this->id;
}
int Manager::getBirthYear() const /*Function to return the Birth year*/
{
	return this->birthYear;
}
string Manager::getFirstName() const /*Function to return the first name*/
{
	return this->firstName;
}
string Manager::getLastName() const /*Function to return the last name*/
{
	return this->lastName;
}

//Class set methods
void Manager::setId(const int& newId) /*set the ID */
{
	this->id = newId;
}
void Manager::setBirthYear(const int& newBirthYear) /*Set the Birth Year*/
{
	this->birthYear = newBirthYear;
}
void Manager::setFirstName(const string& newFirstName) /*Set the first name*/
{
	if (newFirstName.length() <= 10)
	{
		this->firstName = newFirstName;
	}
	else
	{
		cout << "Manager first name length is too long" << endl;
		this->firstName = "~"; 
			
	}
}
void Manager::setLastName(const string& newLastName) /*set the last name*/
{
	if (newLastName.length() <= 10)
	{
		this->lastName = newLastName;
	}
	else
	{
		cout << "Manager last name length is too long" << endl;
		this->lastName = "~";
	}
}

//Class print method
void Manager::print() const /*Function to print the detailes*/
{
	cout << "Printing manager: " << endl; 
	cout << "Id : " << this->id << endl;
	cout << "First name : " << this->firstName << endl;
	cout << "Last name : " << this->lastName << endl;
	cout << "Birth year : " << this->birthYear << endl;
}
