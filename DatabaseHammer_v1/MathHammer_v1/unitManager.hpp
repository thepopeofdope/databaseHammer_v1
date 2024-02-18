#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "unit.hpp"
#include "warGear.hpp"

using std::vector;
using std::ifstream;
using std::string;


class UnitManager {
public:
    // Constructor
    UnitManager();

    // Destructor
    ~UnitManager();

    // Add a new unit to the manager
    void addUnit(const Unit& unit);
    void addNewUnit();

    vector<WarGear> loadWarGearFromFile(const string& filename);
    WarGear* selectAndAddWarGear(const vector<WarGear>& warGearList);

    // Accessor for a specific unit
    Unit& getUnit(int index);

    // Remove a unit from the manager
    void removeUnit(int index);

    // Get the number of units in the manager
    int getNumUnits() const;

    void displayMenu();

    void printAllUnits();
    static bool compareByArmy(const Unit& unit1, const Unit& unit2);
    void sortUnitsByArmy();

    // Serialize all units to a file
    void serialize(const std::string& filename) const;

    // Deserialize all units from a file
    void deserialize(const std::string& filename);

private:
    //declare vector of units
    vector<Unit> mUnits;
};