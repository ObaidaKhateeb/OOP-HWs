//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include "Item.h"

int Item::nextId = 1;

Item::Item(int price, const std::string& manufacturer)
    : id(nextId++), price(price), manufacturer(manufacturer) //Constructor for the Item class
{
}

Item::~Item()  //Destructor for the Item class
{
    std::cout << "Throwing away an item" << std::endl;
}

int Item::getId() const  //to get Id
{
    return this->id;
}

int Item::getPrice() const //to get price 
{
    return this->price;
}

void Item::setPrice(int price) //to set the price
{
    this->price = price;
}

string Item::getManufacturer() const //to get manufacturer
{
    return this->manufacturer;
}

void Item::setManufacturer(const string& manufacturer) //to set manufacturer
{
    this->manufacturer = manufacturer;
}

string Item::toString() const  //to get a string representation of the Item
{
    return "id " + std::to_string(id) + ": " + manufacturer + ", " + std::to_string(price) + "$, ";
}

Item::operator string() const //Overloaded operator to convert the item to a string
{
    return toString();
}

bool Item::itemPtrCompare(const Item* a, const Item* b) //method that returns the item with the smallest Id number 
{
    return a->getId() < b->getId();
}


