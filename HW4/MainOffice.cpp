//Student Bshara Haj, 212590186.
//Student Obaeda Khatib, 201278066.

#include "MainOffice.h"

//Method that adds a branch to the map
void MainOffice::addBranch(const std::string& location, int capacity)
{
    std::pair<std::map<std::string, Branch>::iterator, bool> result = branches.try_emplace(location, location, capacity);
    if (!result.second)
        throw ExistingBranchInsertError();
}

//Method that removes from the map a branch that is situated in a given location
void MainOffice::removeBranch(const std::string& location)
{
    if (branches.erase(location) == 0)
        throw NonExistingBranchRemoveError();
}

//Method that returns a reference to a branch that is situated in a given location
Branch& MainOffice::getBranch(const std::string& location)
{
    std::map<std::string, Branch>::iterator i = branches.find(location);
    if (i == branches.end())
        throw NonExistingBranchRetrieveError();
    return i->second;
}

//Method that print the branches in alphabetically order by its location
void MainOffice::printBranchesByLocation(void (*printFunction)(const Branch&)) const
{
    std::cout << "There are " + std::to_string(branches.size()) + " branches in Main Office:" << std::endl;
    for (std::map<std::string, Branch>::const_iterator i = branches.begin(); i != branches.end(); ++i)
    {
        std::cout << i->first << " : " << "Item count: " << i->second.getSize() << ", Total Value: " << i->second.getItemsSum() << std::endl;
        printFunction(i->second);
    }
}

//Method that prints the branches in order by the sum of its items values
void MainOffice::printBranchesByValue(void (*printFunction)(const Branch&)) const
{
    std::vector<std::pair<std::string, const Branch*>> branchV;
    std::map<std::string, Branch>::const_iterator i;
    for (i = branches.begin(); i != branches.end(); ++i)
        branchV.push_back(std::make_pair(i->first, &(i->second)));

    std::sort(branchV.begin(), branchV.end(), [](const std::pair<std::string, const Branch*>& a, const std::pair<std::string, const Branch*>& b) 
        {
            int sumA = a.second->getItemsSum();
            int sumB = b.second->getItemsSum();
            if (sumA == sumB)
                return a.first < b.first;
            return sumA < sumB;
        });
    std::cout << "There are " << branches.size() << " branches in Main Office: " << std::endl;
    for (std::vector<std::pair<std::string, const Branch*>>::const_iterator pair = branchV.begin(); pair != branchV.end(); ++pair)
    {
        std::cout << pair->first << " : " << "Item count: " << pair->second->getSize() << ", Total Value: " << pair->second->getItemsSum() << std::endl;
        printFunction(*(pair->second));
    }
}


