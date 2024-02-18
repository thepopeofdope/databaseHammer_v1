#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


class WarGear {
public:
	WarGear(string weaponName = "",
		string weaponType = "",
		int range = 0,
		int attacks = 0,
		int ballisticSkill = 0,
		int strength =0,
		int armorPenetration = 0,
		int damage = 0);
	WarGear(const WarGear& copyWarGear); //shallow copy
	~WarGear();

	WarGear& operator<< (const WarGear& rhs);
	//WarGear& operator= (const WarGear& rhs);


	//getters
	string getWeaponName() const;
	string getWeaponType() const;
	int getRange() const;
	int getAttacks() const;
	int getBallisticSkill() const;
	int getStrength() const;
	int getArmorPenetration() const;
	int getDamage() const;

	//setters
	void setWeaponName(string newWeaponName);
	void setWeaponType(string newWeaponType);
	void setRange(int newR);
	void setAttacks(int newA);
	void setBallisticSkill(int newBS);
	void setStrength(int newS);
	void setArmorPenetration(int newAP);
	void setDamage(int newDmg);

	//print	
	void printWarGear();
	
	void serialize(std::ofstream& file) const;

	void deserialize(std::ifstream& file);

private:
	string mWeaponName;
	string mWeaponType;
	int mR;
	int mA;
	int mBS;
	int mS;
	int mAP;
	int mD;
};
