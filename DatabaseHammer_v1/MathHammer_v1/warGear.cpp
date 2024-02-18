#include "warGear.hpp"

WarGear::WarGear(string weaponName, string weaponType, int range, int attacks, 
	int ballisticSkill,	int strength, int armorPenetration, int damage)
{
	mWeaponName = weaponName;
	mWeaponType = weaponType;
	if (range < 0){
		mR = 0;
	}
	else {
		mR = range;
	}
	if (attacks < 0){
		mA = 0;
	}
	else {
		mA = attacks;
	}
	if (ballisticSkill > 6 || ballisticSkill < 2) {
		mBS = 6;
	}
	else {
		mBS = ballisticSkill; 
	}
	if (strength < 2 || strength > 24) {
		mS = 2;
	}
	else {
		mS = strength;
	}
	if (armorPenetration > 6 || armorPenetration < 0) {
		mAP = 0;
	}
	else {
		mAP = armorPenetration;
	}
	if (damage > 6 || damage < 1) {
		mD = 1;
	}
	else {
		mD = damage;
	}
}

//Unit& operator= (const WarGear* rhs) {
//
//}

WarGear::WarGear(const WarGear& copyWarGear)
{
	mWeaponName = copyWarGear.getWeaponName();
	mWeaponType = copyWarGear.getWeaponType();
	mR = copyWarGear.getRange();
	mA = copyWarGear.getAttacks();
	mBS = copyWarGear.getBallisticSkill();
	mS = copyWarGear.getStrength();
	mAP = copyWarGear.getArmorPenetration();
	mD = copyWarGear.getDamage();
}

WarGear::~WarGear()
{
	//does nothing for now
	//may decide to go dynamic w/ wargear
}

string WarGear::getWeaponName() const
{
	return mWeaponName;
}

string WarGear::getWeaponType() const
{
	return mWeaponType;
}

int WarGear::getRange() const
{
	return mR;
}

int WarGear::getAttacks() const
{
	return mA;
}

int WarGear::getBallisticSkill() const
{
	return mBS;
}

int WarGear::getStrength() const
{
	return mS;
}

int WarGear::getArmorPenetration() const
{
	return mAP;
}

int WarGear::getDamage() const
{
	return mD;
}

void WarGear::setWeaponName(string newWeaponName)
{
	mWeaponName = newWeaponName;
}

void WarGear::setWeaponType(string newWeaponType)
{
	mWeaponType = newWeaponType;
}

void WarGear::setRange(int newR)
{
	mR = newR;
}

void WarGear::setAttacks(int newA)
{
	mA = newA;
}

void WarGear::setBallisticSkill(int newBS)
{
	mBS = newBS;
}

void  WarGear::setStrength(int newS)
{
	mS = newS;
}

void WarGear::setArmorPenetration(int newAP)
{
	mAP = newAP;
}

void WarGear::setDamage(int newD)
{
	mD = newD;
}

void WarGear::serialize(std::ofstream& file) const {
	file << mWeaponName << "," << mWeaponType << "," << mR << "," << mA << "," << mBS << "," << mS << "," << mAP << "," << mD << "\n";
}

void WarGear::deserialize(std::ifstream& file) {
	std::getline(file, mWeaponName, ',');
	std::getline(file, mWeaponType, ',');
	file >> mR;
	file.ignore(); // Ignore the comma
	file >> mA;
	file.ignore(); // Ignore the comma
	file >> mBS;
	file.ignore(); // Ignore the comma
	file >> mS;
	file.ignore(); // Ignore the newline
	file >> mAP;
	file.ignore();
	file >> mD;
	file.ignore();
}

void WarGear::printWarGear()
{
	cout << "Weapon Name: " << mWeaponName << endl;
	cout << "Weapon Type: " << mWeaponType << endl;
	cout << "Range: " << mR << "\"" << endl;
	cout << "A: " << mA << endl;
	cout << "BS: " << mBS << endl;
	cout << "S: " << mS << endl;
	cout << "AP: " << mAP << endl;
	cout << "D: " << mD << endl;
}