//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include "PeripheralDevice.h"

class Mouse : public PeripheralDevice //Mouse class, which is a subclass of PeripheralDevice
{
    int dpi;

public:
    Mouse(int price, const std::string& manufacturer, const std::string& color, bool isWireless, int dpi); //Constructor for the Mouse class

    int getDpi() const; //to get the DPI
    void setDpi(int dpi); //to set the DPI

    virtual void connect( Computer& computer) ; //Virtual method to simulate connecting the mouse to a computer

    virtual string toString() const; // Virtual method to get a string representation of the mouse
    operator string() const; //Overloaded operator to convert the mouse to a string
};