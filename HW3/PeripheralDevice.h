//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include "Item.h"
#include "Computer.h"
#include <iostream>

class PeripheralDevice : public Item  //the PeripheralDevice class, which is a child class of Item
{
    std::string color;
    bool isWireless;

public:
    PeripheralDevice(int price, const std::string& manufacturer, const std::string& color, bool isWireless); //constructor

    std::string getColor() const; //to get the color
    void setColor(const std::string& color); //to set teh color
    bool getIsWireless() const; //to get if its Wireless
    void setIsWireless(bool isWireless); //to set it whether Wireless

    virtual void connect(const Computer& computer) const; //virtual connect functio

    virtual string toString() const; //virtual toString function to get a string representation of the PeripheralDevice
    operator string() const; //string conversion operator for the PeripheralDevice class
};
