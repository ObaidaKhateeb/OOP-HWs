//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.
#pragma once
#include "PeripheralDevice.h"
#include "Computer.h"

//Tablet class
class Tablet : public PeripheralDevice, public Computer
{
    int screenSize;

public:
    Tablet(int price, const std::string& manufacturer, const std::string& color, const std::string& cpu, int numOfPorts, int screenSize); //Constructor

    int getScreenSize() const; //Getter for screenSize
    void setScreenSize(int screenSize); //Setter for screenSize
    void setIsWireless(bool isWireless); //Setter for IsWireless

    virtual void connect(Computer& computer); //Method that connect the tablet to a given computer

    virtual string toString() const; //Helper method to get a string representation of the mouse
    operator string() const; //Method to get a string representation of the mouse

};
