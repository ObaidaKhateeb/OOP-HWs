//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once
#include <string>
#include <iostream>
using std::string;
//Item Class
class Item
{
    static int nextId; //static integer for the next ID to be assigned
    int id; //item's ID
    int price; //item's price
    string manufacturer; //item's manufacturer

public:
    Item(int price, const string& manufacturer); //Constructor for the Item class
    virtual ~Item(); //Virtual destructor

    int getId() const; //to get ID 
    int getPrice() const; //to get the price
    void setPrice(int price); //to set the price
    string getManufacturer() const; //to get manufacturer
    void setManufacturer(const string& manufacturer); //to set the manufacturer

    virtual string toString() const; //Virtual method to get a string representation of the item
    operator string() const; //Overloaded operator to convert the item to a string

    static bool itemPtrCompare(const Item* a, const Item* b); //method that returns the item with the smallest Id number 

};

