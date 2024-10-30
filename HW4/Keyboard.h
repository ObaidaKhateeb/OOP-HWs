//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include "PeripheralDevice.h"

class Keyboard : public PeripheralDevice //Keyboard class, which is a subclass of PeripheralDevice.
{
    int numberOfKeys;

public:
    Keyboard(int price, const std::string& manufacturer, const std::string& color, bool isWireless, int numberOfKeys); //Constructor for the Keyboard class

    int getNumberOfKeys() const; //to get the number of keys on the keyboard
    void setNumberOfKeys(int numberOfKeys); //o set the number of keys on the keyboard

    virtual void connect( Computer& computer) ; //to simulate connecting the keyboard to a computer

    virtual string toString() const; //Virtual method to get a string representation of the keyboard
    operator string() const; //Overloaded operator to convert the keyboard to a string
};

