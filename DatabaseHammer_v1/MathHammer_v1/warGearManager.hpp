#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <algorithm>
#include "warGear.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class WarGearManager {
public:
	WarGearManager();


	~WarGearManager();

	void addWarGear(const WarGear& warGear);
	WarGear& getWarGear(int index);
	void removeWarGear(int index);
	int getNumWarGear() const;
	void printWarGear();
	void displayMenu();
	void addNewWarGear();
	static bool compareByType(const WarGear& warGear1, const WarGear& warGear2);
	void sortWarGearByType();


	// Serialize all units to a file
	void serialize(const std::string& filename) const;

	// Deserialize all units from a file
	void deserialize(const std::string& filename);

private:
	vector<WarGear> mWarGear;
};

