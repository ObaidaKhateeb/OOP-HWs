//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066

#include "Company.h"

//Class get methods
string Company::getName() const  /*Function to return the name */
{
	return this->name;
}
int Company::getShopsNumber() const /*Function to return the Shops Number */
{
	return this->shopsNumber;
}

//Class set methods
void Company::setName(const string& newName)
{
	if (newName.length() <= 10) /*Check if the name length is more than 10 characters*/
	{
		this->name = newName;
	}
	else
	{
		cout << "Company name length is too long" << endl; 
		this->name = "~";
	}
}

//Class other methods
void Company::addShop(const Shop& newShop) 
{
	//Check if the company is full. if it's full the shop will not be added, and the user will be informed about that
	if (this->shopsNumber < MAX_SHOPS_NUMBER)
	{
		this->shops[this->shopsNumber] = newShop;
		this->shopsNumber++;
	}
	else
	{
		cout << "There is no place for new shops! ";
	}

}
void Company::printShopsByName() 
{
	int i, j; 
	if (Company::getShopsNumber() == 0) /*if we have zero shops that means that we dont have shops*/
	{
		cout << "There are no shops in this company." << endl; 
	}
	else /*if the shops number is not zero then we ahve shops so we have to print the shops number*/
	{
		cout << "There are " << this->shopsNumber << " shops in this company. The shops details are : " << endl;
	}

	Shop tempCompany[MAX_SHOPS_NUMBER];
	for (i = 0; i < this->shopsNumber; i++)
	{
		tempCompany[i] = this->shops[i];
	}

	Shop temp1, temp2;
	string string1, string2;

	for (i = (this->shopsNumber - 1); i >= 0; i--) /*this function is used to print the shops detailes , the shops is sorted by the name*/
	{
		for (j = 0; j < (this->shopsNumber - 1); j++)
		{
			temp1 = tempCompany[j];
			temp2 = tempCompany[j + 1];
			string1 = temp1.getName();
			string2 = temp2.getName();
			if (string1.compare(string2) > 0)
			{
				tempCompany[j + 1] = temp1;
				tempCompany[j] = temp2;
			}
		}
	}

	for (i = 0; i < this->shopsNumber; i++)
	{
		cout << "Shop #" << i+1 << " :" << endl;
		tempCompany[i].print();
		cout << endl;
	}

}
void Company::printShopsByDay() /*this function to print the shops detailes , sorted by Day*/
{
	if (Company::getShopsNumber() == 0)
	{
		cout << "There are no shops in this company." << endl; /*if we have zero shops , then we dont have shops */
	}
	else /*else we have to print the shops number */
	{
		cout << "There are " << this->shopsNumber << " shops in this company. The shops details are : " << endl;
	}
	int i, j;

	Shop tempCompany[MAX_SHOPS_NUMBER];
	for (i = 0; i < this->shopsNumber; i++)
	{
		tempCompany[i] = this->shops[i];
	}

	Shop temp1, temp2;

	for (i = (this->shopsNumber - 1); i >= 0; i--) /*sort the shops by the day */
	{
		for (j = 0; j < (this->shopsNumber - 1); j++)
		{
			temp1 = tempCompany[j];
			temp2 = tempCompany[j + 1];
			if (temp1.getClosedDay() > temp2.getClosedDay())
			{
				tempCompany[j + 1] = temp1;
				tempCompany[j] = temp2;
			}
		}
	} 

	for (i = 0; i < this->shopsNumber; i++)
	{
		cout << "Shop #" << i + 1 << " :" << endl;
		tempCompany[i].print();
		cout << endl;
	}

}