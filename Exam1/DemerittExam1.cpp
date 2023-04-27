#include <iostream>
#include <vector>
#include <fstream>
#include "findmasses.h"

using namespace std;

int main() {

	//declare variables
	vector<unsigned int> asteroids;
	unsigned int tempNum;

	//open input file
	ifstream fin("masses.txt");

	//test input file
	if (!fin) {
		cout << "File doesn't exist" << endl;
		system("pause");
		return -1;
	}

	//read input file and get masses into asteroids vector
	while (fin >> tempNum) {
		asteroids.push_back(tempNum);
	}

	//create output file
	ofstream fout("result.txt");

	//call function and output result
	fout << findmass(asteroids);

	//close files and exit
	fout.close();
	fin.close();
	return 0;
}