#include "warGearManager.hpp"

WarGearManager::WarGearManager()
{

}

WarGearManager::~WarGearManager()
{

}

// Add a new unit to the manager
void WarGearManager::addWarGear(const WarGear& warGear)
{
    mWarGear.push_back(warGear);
}

// Accessor for a specific unit
WarGear& WarGearManager::getWarGear(int index)
{
    if (index >= 0 && index < mWarGear.size()) {
        return mWarGear[index];
    }
    else {
        // Handle index out of range error
        throw std::out_of_range("Index out of range");
    }
}

// Remove a unit from the manager
void WarGearManager::removeWarGear(int index)
{
    mWarGear.erase(mWarGear.begin() + index);
}

// Get the number of units in the manager
int WarGearManager::getNumWarGear() const
{
    return mWarGear.size();
}

void WarGearManager::printWarGear()
{
    cout << " === War Gear List === " << endl;
    for (const WarGear& warGear : mWarGear) {
        cout << "Weapon: " << warGear.getWeaponName() << endl;
        cout << "Type: " << warGear.getWeaponType() << endl;
        cout << "Range: " << warGear.getRange() << "\"" << endl;
        cout << "Attacks: " << warGear.getAttacks() << endl;
        cout << "Ballistic Skill: " << warGear.getBallisticSkill() << "+" << endl;
        cout << "Strength: " << warGear.getStrength() << endl;
        cout << "Armor Penetration: " << warGear.getArmorPenetration() << endl;
        cout << "Damage: " << warGear.getDamage() << endl;
    }
}

void WarGearManager::displayMenu()
{
    int selector;
    do {
        cout << "===== War Gear Management Menu =====" << std::endl;
        cout << "1. Add a new War Gear" << std::endl;
        cout << "2. Print all War Gear" << std::endl;
        cout << "3. Sort War Gear by type" << std::endl;
        cout << "4. Exit" << std::endl;
        cout << "=================================" << std::endl;
        cout << "Please enter your selection: ";
        cin >> selector;
        cin.ignore(); //this will ignore newline chars
        switch (selector) {
        case 1:
            addNewWarGear();
            serialize("wargear.txt");
            break;
        case 2:
            deserialize("wargear.txt");
            printWarGear();
            break;
        case 3:
            sortWarGearByType();
            break;
        case 4:
            serialize("wargear.txt");
            break;
        }
    } while (selector != 4);
}
bool WarGearManager::compareByType(const WarGear& warGear1, const WarGear& warGear2)
{
    return warGear1.getWeaponType() < warGear2.getWeaponType();
}

void WarGearManager::sortWarGearByType()
{
    std::sort(mWarGear.begin(), mWarGear.end(), compareByType);
}
void WarGearManager::addNewWarGear()
{
    string weaponName, weaponType;
    int range, attacks, ballisticSkill, strength, armorPenetration, damage;

    cout << "Enter weapon name: ";
    getline(cin, weaponName);

    cout << "Enter weapon type: ";
    getline(cin, weaponType);

    cout << "Enter range: ";
    cin >> range;

    cout << "Enter attacks: ";
    cin >> attacks;

    cout << "Enter ballistic skill: ";
    cin >> ballisticSkill;

    cout << "Enter strength: ";
    cin >> strength;

    cout << "Enter armor penetration: ";
    cin >> armorPenetration;

    cout << "Enter damage: ";
    cin >> damage;

    WarGear newWarGear(weaponName, weaponType, range, attacks, ballisticSkill, strength, armorPenetration, damage);
    addWarGear(newWarGear);
}

// Serialize all units to a file
void WarGearManager::serialize(const std::string& filename) const
{
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const WarGear& warGear : mWarGear) {
            warGear.serialize(file);
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
}

// Deserialize all units from a file
void WarGearManager::deserialize(const std::string& filename)
{
    std::ifstream file(filename);
    if (file.is_open()) {
        mWarGear.clear(); // Clear existing units
        while (!file.eof()) {
            WarGear warGear;
            warGear.deserialize(file);
            if (!warGear.getWeaponName().empty()) {
                addWarGear(warGear);
            }
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
    }
}