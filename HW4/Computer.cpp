//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include "Computer.h"
#include"PeripheralDevice.h" 

//Constructor
Computer::Computer(int price, const string& manufacturer, const string& cpu, bool isALaptop, int numOfPorts)
    : Item(price, manufacturer), cpu(cpu), isALaptop(isALaptop), numOfPorts(numOfPorts) 
{
}

//Destructor
Computer::~Computer() 
{
    for (int i = 0; i < connected.size(); i++)
        connected[i]->disconnect();
    connected.clear();
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

int Computer::getNumOfPorts() const
{
    return numOfPorts;
}

string Computer::toString() const //to get a string representation of the Computer
{
    return Item::toString() + (this->isALaptop ? "Laptop" : "Desktop") + ", " + cpu;
}

Computer::operator string() const //string conversion operator for the Computer class
{
    return toString();
}

//A method that prints the peripheral devices connected to the computer in order from the first that has been connected to the last
void Computer::printConnected() const  
{
    std::cout << "There are " + std::to_string(connected.size()) + " connections to " + Computer::operator std::string();
    for (int i = 0; i < connected.size(); i++) {
        std::cout << std::endl;
        std::cout << connected[i]->operator std::string();
    }
    std::cout << std::endl;
}
