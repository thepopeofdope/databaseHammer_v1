#include "unit.hpp"

Unit::Unit(string unitName, string armyName, int toughness, 
	int armorSave, int wounds, int leadership, int numModels, WarGear* warGear)
{
	mUnitName = unitName;
	mArmyName = armyName;
	if (toughness < 2) {
		mT = 2;
	}
	else {
		mT = toughness;
	}
	if (armorSave < 2 || armorSave > 6)
	{
		mSv = 6;
	}
	else {
		mSv = armorSave;
	}
	if (wounds < 1) {
		mW = 1;
	}
	else {
		mW = wounds;
	}
	if (leadership > 6 || leadership < 9) {
		mLd = 9;
	}
	else {
		mLd = leadership;
	}
	if (numModels < 0) {
		mMod = 1;
	}
	else {
		mMod = numModels;
	}
	if (warGear != nullptr) {
		mWarGear = new WarGear(*warGear);
	}
	else {
		warGear = nullptr;
	}

}

Unit::Unit(const Unit& copyUnit)
{
	mUnitName = copyUnit.getUnitName();
	mArmyName = copyUnit.getArmyName();
	mT = copyUnit.getToughness();
	mSv = copyUnit.getArmorSave();
	mW = copyUnit.getWounds();
	mLd = copyUnit.getLeadership();
	mMod = copyUnit.getNumModels();
	mWarGear = copyUnit.getWarGear();
}

Unit::~Unit()
{

}

string Unit::getUnitName() const
{
	return mUnitName;
}

string Unit::getArmyName() const
{
	return mArmyName;
}

int Unit::getToughness() const
{
	return mT;
}

int Unit::getArmorSave() const
{
	return mSv;
}

int Unit::getWounds() const
{
	return mW;
}

int Unit::getLeadership() const
{
	return mLd;
}

int Unit::getNumModels() const
{
	return mMod;
}

// Get all war gear associated with the unit
WarGear* Unit::getWarGear() const {
	return mWarGear;
}


void Unit::setUnitName(string newUnitName)
{
	mUnitName = newUnitName;
}

void Unit::setArmyName(string newArmyName)
{
	mArmyName = newArmyName;
}

void Unit::setToughness(int newT)
{
	mT = newT;
}

void Unit::setArmorSave(int newSv)
{
	mSv = newSv;
}

void Unit::setWounds(int newW)
{
	mW = newW;
}

void Unit::setLeadership(int newLd)
{
	mLd = newLd;
}

// Add a piece of war gear to the unit
//void Unit::addWarGear(const WarGear& warGear) {
//	mWarGear.push_back(warGear);
//}
//void Unit::setWarGear(WarGear newWg)

// Serialize the unit to a file
void Unit::serialize(std::ofstream& file) const {
	file << mUnitName << "," << mArmyName << "," << mT << "," << mSv << "," << mW << "," << mLd << "\n";
}

void Unit::deserialize(std::ifstream& file) {
	std::getline(file, mUnitName, ',');
	std::getline(file, mArmyName, ',');
	file >> mT;
	file.ignore(); // Ignore the comma
	file >> mSv;
	file.ignore(); // Ignore the comma
	file >> mW;
	file.ignore(); // Ignore the comma
	file >> mLd;
	file.ignore(); // Ignore the newline
}

void Unit::printUnit()
{
	cout << "Unit Name: " << mUnitName << endl;
	cout << "Army Name: " << mArmyName << endl;
	cout << "T: " << mT << endl;
	cout << "Sv: " << mSv << endl;
	cout << "W: " << mW << endl;
	cout << "Ld: " << mLd << endl;
	//cout << "WarGear: " << mWG << endl;
}
