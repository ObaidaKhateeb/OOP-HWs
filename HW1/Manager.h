//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066
#pragma once
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Manager
{
	//Private features
		int id, birthYear;
		string firstName, lastName;

	public:
		//Constructor 
		Manager(int id = 0, string firstName = "~", string lastName = "~", int birthYear = 0) : id(id), birthYear(birthYear)
		{
			if (firstName.length() <= 10) /*check if the first name is more than 10 characters*/
			{
				this->firstName = firstName;
			}
			else
			{
				cout << "Manager first name length is too long" << endl;
				this->firstName = "~";
			}
			if (lastName.length() <= 10) /*check if the last name length is more than 10 characters*/
			{
				this->lastName = lastName;
			}
			else
			{
				cout << "Manager last name length is too long" << endl;
				this->lastName = "~";
			}
		}

		//Class get methods
		int getId() const; 
		int getBirthYear() const; 
		string getFirstName() const; 
		string getLastName() const;

		//Class set methods
		void setId(const int& newId);
		void setBirthYear(const int& newBirthYear);
		void setFirstName(const string& newFirstName);
		void setLastName(const string& newLastName);

		//Class print method
		void print() const;
};

