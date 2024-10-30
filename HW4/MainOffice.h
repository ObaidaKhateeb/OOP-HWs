//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#pragma once

#include <map>
#include "Branch.h"
#include <algorithm>

//Main Office class
class MainOffice
{
private:
    MainOffice() {}
    MainOffice(const MainOffice&) = delete;
    void operator=(const MainOffice&) = delete;
    std::map<std::string, Branch> branches; //STL map of branches 
public:
    static MainOffice& getInstance()
    {
        static MainOffice instance;
        return instance;
    }
    void addBranch(const std::string& location, int capacity); //Method that adds a branch to the map
    void removeBranch(const std::string& location); //Method that removes from the map a branch that is situated in a given location
    Branch& getBranch(const std::string& location); //Method that returns a reference to a branch that is situated in a given location
    void printBranchesByLocation(void (*printFunction)(const Branch&)) const; //Method that print the branches in alphabetically order by its location
    void printBranchesByValue(void (*printFunction)(const Branch&)) const; //Method that prints the branches in order by the sum of its items values
};


