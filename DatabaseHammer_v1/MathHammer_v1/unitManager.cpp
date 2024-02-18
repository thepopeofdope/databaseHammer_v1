#pragma once
#include "unitManager.hpp"

UnitManager::UnitManager()
{

}

UnitManager::~UnitManager()
{

}

// Add a new unit to the manager
void UnitManager::addUnit(const Unit& unit) 
{
    mUnits.push_back(unit);
}

vector<WarGear> UnitManager::loadWarGearFromFile(const std::string& filename) {
    vector<WarGear> warGearList;
    ifstream file(filename);
    string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        string weaponName, weaponType;
        int range, attacks, ballisticSkill, strength, armorPenetration, damage;

        std::getline(iss, weaponName, ',');
        std::getline(iss, weaponType, ',');
        iss >> range;
        iss.ignore();
        iss >> attacks;
        iss.ignore();
        iss >> ballisticSkill;
        iss.ignore();
        iss >> strength;
        iss.ignore();
        iss >> armorPenetration;
        iss.ignore();
        iss >> damage;

        WarGear warGear(weaponName, weaponType, range, attacks, ballisticSkill, strength, armorPenetration, damage);
        warGearList.push_back(warGear);
    }

    return warGearList;
}

WarGear* UnitManager::selectAndAddWarGear(const vector<WarGear>& warGearList) {
    cout << "Select War Gear:" << endl;
    for (size_t i = 0; i < warGearList.size(); ++i) {
        cout << i + 1 << ": " << warGearList[i].getWeaponName() << " - " << warGearList[i].getWeaponType() << endl;
    }

    cout << "Enter selection (number): ";
    int selection;
    cin >> selection;
    cin.ignore(); // Ignore newline

    if (selection > 0 && selection <= warGearList.size()) {
        // Create a new WarGear object based on the selection
        // This is a simplified approach; consider how you manage memory in your application
        return new WarGear(warGearList[selection - 1]);
    }
    else {
        cout << "Invalid selection. Returning nullptr." << endl;
        return nullptr;
    }
}


void UnitManager::addNewUnit()
{
    string unitName, armyName;
    int toughness, armorSave, wounds, leadership, numModels;
    vector<WarGear>warGearList = loadWarGearFromFile("wargear.txt");

    cout << "Enter unit name: ";
    getline(cin, unitName);

    cout << "Enter army name: ";
    getline(cin, armyName);

    cout << "Enter toughness: ";
    cin >> toughness;

    cout << "Enter Armor Save: ";
    cin >> armorSave;

    cout << "Enter Wounds: ";
    cin >> wounds;

    cout << "Enter leadership: ";
    cin >> leadership;

    cout << "Enter unit model count: ";
    cin >> numModels;

    WarGear* selectedWarGear = selectAndAddWarGear(warGearList);

    Unit unit(unitName, armyName, toughness, armorSave, wounds, leadership, numModels, selectedWarGear);
    mUnits.push_back(unit);
}

// Accessor for a specific unit
Unit& UnitManager::getUnit(int index) 
{
    return mUnits[index];
}


// Remove a unit from the manager
void UnitManager::removeUnit(int index) 
{
    mUnits.erase(mUnits.begin() + index);
}

// Get the number of units in the manager
int UnitManager::getNumUnits() const 
{
    return mUnits.size();
}

void UnitManager::printAllUnits()
{
    cout << " === Unit List === " << endl;
    for (const Unit& unit : mUnits){
        cout << "Unit: " << unit.getUnitName() << endl;
        cout << "Army: " << unit.getArmyName() << endl;
        cout << "Toughness: " << unit.getToughness() << endl;
        cout << "Armor Save: " << unit.getArmorSave() << endl;
        cout << "Wounds Per Model: " << unit.getWounds() << endl;
        cout << "Leadership: " << unit.getLeadership() << endl;
        cout << "Model Count: " << unit.getNumModels() << endl;
        WarGear* warGear = unit.getWarGear();
        if (warGear != nullptr) {
            cout << "Equipped War Gear: " << warGear->getWeaponName()
                << ", Type: " << warGear->getWeaponType() << endl;
        }
        else {
            cout << "Equipped War Gear: NONE" << endl;
        }
        //cout << "Equipped War Gear: " << unit.getWarGear() << endl;
    }
}

void UnitManager::displayMenu() 
{
   int selector;
   do {
       cout << "===== Unit Management Menu =====" << std::endl;
       cout << "1. Add a new unit" << std::endl;
       cout << "2. Print all units" << std::endl;
       cout << "3. Sort units by army name" << std::endl;
       cout << "4. Exit" << std::endl;
       cout << "=================================" << std::endl;
       cout << "Please enter your selection: ";
       cin >> selector;
       cin.ignore(); //this will ignore newline chars
       switch (selector) {
       case 1:
           addNewUnit();
           serialize("units.txt");
           break;
       case 2:
           deserialize("units.txt");
           printAllUnits();
           break;
       case 3:
           sortUnitsByArmy();
           break;
       case 4:
           serialize("units.txt");
           break;
       }
   } while (selector != 4);
}
bool UnitManager::compareByArmy(const Unit& unit1, const Unit& unit2) 
{
    return unit1.getArmyName() < unit2.getArmyName();
}

void UnitManager::sortUnitsByArmy()
{
    std::sort(mUnits.begin(), mUnits.end(), compareByArmy);
}

// Serialize all units to a file
void UnitManager::serialize(const std::string& filename) const 
{
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const Unit& unit : mUnits) {
            unit.serialize(file);
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
}

// Deserialize all units from a file
void UnitManager::deserialize(const std::string& filename) 
{
    std::ifstream file(filename);
    if (file.is_open()) {
        mUnits.clear(); // Clear existing units
        while (!file.eof()) {
            Unit unit;
            unit.deserialize(file);
            if (!unit.getUnitName().empty()) {
                addUnit(unit);
            }
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
    }
}