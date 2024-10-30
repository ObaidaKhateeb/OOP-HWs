//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.
#include "Tablet.h"

//constructor
Tablet::Tablet(int price, const std::string& manufacturer, const std::string& color, const std::string& cpu, int numOfPorts, int screenSize)
    : Item(price, manufacturer), PeripheralDevice(price, manufacturer, color, true), Computer(price, manufacturer, cpu, false, numOfPorts), screenSize(screenSize)
{
}

//Getter for screenSize
int Tablet::getScreenSize() const
{
    return screenSize;
}

//Setter for screenSize

void Tablet::setScreenSize(int screenSize)
{
    this->screenSize = screenSize;
}

void Tablet::setIsWireless(bool isWireless) //To ensure that Tablet is always wirless
{
}

//Method that connect the tablet to a given computer
void Tablet::connect(Computer& computer)
{
    std::cout << "Connecting a tablet" << std::endl;
    PeripheralDevice::connect(&computer);
}

//Helper method to get a string representation of the mouse
string Tablet::toString() const
{
    return Item::toString()  + PeripheralDevice::getColor() + ", " + Computer::getCpu() + ", Tablet with screen size: " + std::to_string(screenSize);
}

//Method to get a string representation of the mouse
Tablet::operator string() const
{
    return toString();
}
