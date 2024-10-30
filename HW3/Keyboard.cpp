//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include "Keyboard.h"

Keyboard::Keyboard(int price, const string& manufacturer, const string& color, bool isWireless, int numberOfKeys)
    : PeripheralDevice(price, manufacturer, color, isWireless), numberOfKeys(numberOfKeys) //constructor for the Keyboard class
{
}

int Keyboard::getNumberOfKeys() const //to get the number of keys on the Keyboard
{
    return numberOfKeys;
}

void Keyboard::setNumberOfKeys(int numberOfKeys)  //to set the number of keys on the Keyboard
{
    this->numberOfKeys = numberOfKeys;
}

void Keyboard::connect(const Computer& computer) const //to simulate connecting the Keyboard to a Computer
{
    std::cout << "Connecting a keyboard" << std::endl;
    PeripheralDevice::connect(computer);
}

string Keyboard::toString() const //to get a string representation of the Keyboard
{
    return PeripheralDevice::toString() + ", Keyboard with " + std::to_string(numberOfKeys) + " Keys";
}

Keyboard::operator string() const //string conversion operator for the Keyboard class
{
    return toString();
}
