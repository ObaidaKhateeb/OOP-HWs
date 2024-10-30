//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.
#pragma once
#include "PeripheralDevice.h"

PeripheralDevice::PeripheralDevice(int price, const string& manufacturer, const string& color, bool isWireless)
	: Item(price, manufacturer), color(color), isWireless(isWireless) //constructor of the PeripheralDevice class
{
	computerConnectedTo = NULL;
}

PeripheralDevice::~PeripheralDevice() //Destructor
{
	if (computerConnectedTo != NULL) //if the peripheral device is connected to a computer, the function removes it from the connected devices vector of that computer
	{
		std::remove(computerConnectedTo->connected.begin(), computerConnectedTo->connected.end(), this);
	}
}

string PeripheralDevice::getColor() const //getter for color
{
    return color;
}

void PeripheralDevice::setColor(const string& color) //setter for color
{
    this->color = color;
}

bool PeripheralDevice::getIsWireless() const //getter for isWireless
{
    return isWireless;
}

void PeripheralDevice::setIsWireless(bool isWireless) //setter for isWireless
{
    this->isWireless = isWireless;
}

Computer* PeripheralDevice::getComputerConnectedTo() const //getter that returns the computer that the device connected to 
{
	return computerConnectedTo;
}

void PeripheralDevice::connect(Computer* computer) //function that connect the peripheral device to a given computer
{
		if (computerConnectedTo != computer) //if the given computer is the same computer that the peripheral device connected to do nothing 
		{
			if (computerConnectedTo) // check if the peripheral device already connected to a computer, if yes the function throw error 
			{
				throw ConnectError();
			}
			else
			{
				std::cout << operator std::string();
				std::cout << " is connecting to computer: " + computer->Computer::operator std::string(); std::cout << std::endl;
				for (int i = 0; i < computer->connected.size(); i++)
				{
					if (typeid(computer->connected[i]) == typeid(*this)) //checks if the computer is connected to a device of the same type, if yes it throw error
					{
						throw ConnectError();
					}
				}
				if (computer->connected.size() == computer->getNumOfPorts()) //checks if the computer is already connected to a number of devices as its USB ports, if yes it throw error
				{

					throw ConnectError();
				}
				else
				{
					computer->connected.push_back(this);
					computerConnectedTo = computer;
				}
			}
		}
} 

void PeripheralDevice::disconnect() //function that disconnect the peripheral device from the computer it's connected to
{ 
    if (computerConnectedTo)
    {
        std::vector<PeripheralDevice*>::iterator neww;
        computerConnectedTo->connected.erase(std::remove(computerConnectedTo->connected.begin(), computerConnectedTo->connected.end(), this)); //remove the peripheral device from the vector of computer's connected devices 
        computerConnectedTo = NULL; 
    }
} 

string PeripheralDevice::toString() const //toString function to return a string representation of the PeripheralDevice
{
    return Item::toString() + (this->isWireless ? "Wireless" : "Wired") + ", " + color;
}

PeripheralDevice::operator string() const   //string conversion operator for the PeripheralDevice class
{
    return toString();
}
