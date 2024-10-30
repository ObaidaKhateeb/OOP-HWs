//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.
#pragma once
#include <exception>
#include <string>

class ExistingBranchInsertError : public std::exception //Error appears when trying to add a branch with an already existing location
{
public:
    const char* what() const throw() 
    {
        return "Trying to add a branch with an already existing location";
    }
};

class NonExistingBranchRemoveError : public std::exception //Error appears when trying to remove a branch with a non existing location
{
public:
    const char* what() const throw() 
    {
        return "Trying to remove a branch with a non existing location";
    }
};

class NonExistingBranchRetrieveError : public std::exception //Error appears when trying to retrieve a branch with a non existing location
{
public:
    const char* what() const throw() 
    {
        return "Trying to retrieve a branch with a non existing location";
    }
};

class ExistingItemError : public std::exception //Error appears when rying to add an item with an id that is already in the catalog
{
public:
    const char* what() const throw() 
    {
        return "Trying to add an item with an id already in the catalog";
    }
};

class FullCatalogError : public std::exception //Error appears when trying to add an item to a full catalog. 
{
public:
    const char* what() const throw() 
    {
        return "Trying to add an item to a full catalog";
    }
};

class NonExistingItemError : public std::exception //Error appears when trying to remove an item with a non existing id
{
public:
    const char* what() const throw() 
    {
        return "Trying to remove an item with a non existing id";
    }
};

class NoneExistingItemTypeError : public std::exception //Error appears when trying to get an item with a non-existing type
{
public:
    const char* what() const throw() 
    {
        return "Trying to get an item with a non existing type";
    }
};

class ConnectError : public std::exception //Error appears when it fails to connect a peripheral device to a computer.
{
public:
    const char* what() const throw() 
    {
        return "Failed connection attempt";
    }
};