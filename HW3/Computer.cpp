//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include "Computer.h"

Computer::Computer(int price, const string& manufacturer, const string& cpu, bool isALaptop)
    : Item(price, manufacturer), cpu(cpu), isALaptop(isALaptop) //the constructor for the Computer class
{
}

string Computer::getCpu() const //to get the CPU
{
    return cpu;
}

void Computer::setCpu(const string& cpu) //to set the CPU
{
    this->cpu = cpu;
}

bool Computer::getIsALaptop() const //to get whether the Computer is a laptop
{
    return isALaptop;
}

void Computer::setIsALaptop(bool isALaptop) //to set whether the Computer is a laptop
{
    this->isALaptop = isALaptop;
}

string Computer::toString() const //to get a string representation of the Computer
{
    return Item::toString() + (this->isALaptop ? "Laptop" : "Desktop") + ", " + cpu;
}

Computer::operator string() const //string conversion operator for the Computer class
{
    return toString();
}