//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include "Item.h"

class Computer : public Item //Computer class, which is a subclass of Item
{
    std::string cpu;
    bool isALaptop;

public:
    Computer(int price, const std::string& manufacturer, const std::string& cpu, bool isALaptop); //Constructor for the Computer class

    std::string getCpu() const; //to get the CPU of the computer
    void setCpu(const std::string& cpu); //to set the CPU
    bool getIsALaptop() const; //to get whether the computer is a laptop
    void setIsALaptop(bool isALaptop); //to set whether the computer is a laptop

    virtual string toString() const; //Virtual method to get a string representation of the computer
    operator string() const; // Overloaded operator to convert the computer to a string
};

