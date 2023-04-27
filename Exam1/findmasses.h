#ifndef findmasses_h
#define findmasses_h

#include <vector>
#include <algorithm>

using namespace std;

/*
* finds the lowest needed mass to successfully destroid all asteroids
* @Param, vector of unsigned ints
* @Return, unsigned int, minimun mass value needed to destroy all asteroids
*/
unsigned int findmass(vector<unsigned int>& masses) {

	//variables needed for function
	int i;
	int startingMass;
	bool success = false;
	int tempMass;

	//sort masses
	sort(masses.begin(), masses.end());

	//assign starting mass to first value of masses
	startingMass = masses.at(0) + 1;

	//loop to check through and find the needed starting mass
	while (!success) {

		tempMass = startingMass;

		//iterate through vector, checking if mass is greater
		for (i = 0; i < masses.size(); ++i) {

			if (tempMass > masses.at(i)) { 
				tempMass = tempMass + masses.at(i);
			}
			else { 
				startingMass += 1;
				break;
			}
		}

		//check if tempMass is greater than the last asteroid, thus signifying success and set bool to true
		if (tempMass > masses.at(masses.size() - 1)) {
			success = true;
		}
	}

	return startingMass;
}
#endif