//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.
#pragma once
#include "PeripheralDevice.h"

PeripheralDevice::PeripheralDevice(int price, const string& manufacturer, const string& color, bool isWireless)
    : Item(price, manufacturer), color(color), isWireless(isWireless) //constructor of the PeripheralDevice class
{
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

void PeripheralDevice::connect(const Computer& computer) const //connect function to print connection details
{
    std::cout << toString() << " is connecting to computer: " << computer.toString() << std::endl;
}

string PeripheralDevice::toString() const //toString function to return a string representation of the PeripheralDevice
{
    return Item::toString() + (this->isWireless ? "Wireless" : "Wired") + ", " + color;
}

PeripheralDevice::operator string() const   //string conversion operator for the PeripheralDevice class
{
    return toString();
}
