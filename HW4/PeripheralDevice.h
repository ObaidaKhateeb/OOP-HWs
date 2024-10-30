//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include "Item.h"
#include "HWExceptions.h"
#include "Computer.h"
#include <iostream>

//PeripheralDevice class
class PeripheralDevice : public virtual Item 
{
    std::string color;
    bool isWireless;
    Computer* computerConnectedTo;

public:
    PeripheralDevice(int price, const std::string& manufacturer, const std::string& color, bool isWireless); //constructor
    ~PeripheralDevice(); //Destructor
    std::string getColor() const; //to get the color
    void setColor(const std::string& color); //to set the color
    bool getIsWireless() const; //to get if it's Wireless 
    void setIsWireless(bool isWireless); //to set it whether its Wireless or not
    Computer* getComputerConnectedTo() const; //to get the computer that the device connected to 

    virtual void connect(Computer* computer); //function that connect the peripheral device to a given computer
    virtual void disconnect(); //function that disconnect the peripheral device from the computer it's connected to

    virtual string toString() const; //virtual toString function to get a string representation of the PeripheralDevice
    operator string() const; //string conversion operator for the PeripheralDevice class
};
