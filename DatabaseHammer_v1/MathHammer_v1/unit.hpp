#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "warGear.hpp"
//#include "unitManager.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


class Unit {
public:
	Unit(
		string unitName = "",
		string armyName = "",
		int toughness = 0,
		int armorSave = 0,
		int wounds = 0,
		int leadership = 0,
		int numberOfModels = 0,
		WarGear* warGear = nullptr);
	Unit(const Unit& copyUnit);//shallow copy
	
	~Unit(); //destructor
	
	//Unit& operator= (const WarGear* rhs);

	//getters

	string getUnitName() const;
	string getArmyName() const;
	int getToughness() const;
	int getArmorSave() const;
	int getWounds() const;
	int getLeadership() const;
	int getNumModels() const;
	WarGear* getWarGear() const; //with this I'm not sure if I want to copy the wargear all in or if I should allow the operator to choose their wargear at runtime

	// Add a piece of war gear to the unit
	//void addWarGear(const WarGear& warGear);

	// Get all war gear associated with the unit
	



	//setters
	void setUnitName(string newUnitName);
	void setArmyName(string newArmyName); //potentially incorp an army selection menu
	void setToughness(int newT);
	void setArmorSave(int newSv);
	void setWounds(int newW);
	void setLeadership(int newLd);
	void setNumModels(int newMod);
	void setWarGear(); //need to figure out how to turn this into a menu of some sort

	//printer

	void printUnit();


	// Serialize the unit to a file
	void serialize(std::ofstream& file) const;

	// Deserialize the unit from a file
	void deserialize(std::ifstream& file);

private:
	string mUnitName;
	string mArmyName;
	int mT;
	int mSv;
	int mW;
	int mLd;
	int mMod;
	WarGear* mWarGear;
	//vector<WarGear> mWarGear;
};