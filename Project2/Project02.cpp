// Emily Foley
// ef2vr@mail.umkc.edu
// 09/11/19
// CS201R Project02

#include <iostream>
#include <string>
#include <cmath>
#include "functions.h"
using namespace std;
int main() {
	int userChoice, numWalls, numCansRound, x;
	float totalWallArea = 0.0f, numPaintCans, totalCost, bothCost = 0.0f;
	string indicateInteriorExterior, canPrice;

	userChoice = MainMenu();

	//if choice is 1 or 2, loop once, if 3, loop twice--set x to indicate
	switch (userChoice) {
	case 1:
	case 2:
		x = 1;
		break;
	case 3:
		x = 2;
		break;
	}
	for (int i = 0; i < x; ++i) {
		if (userChoice == 3 && i == 0) {
			cout << "\nFirst, let's paint the interior" << endl;
		}
		if (userChoice == 2 && i == 1) {
			cout << "\nNow, let's paint the exterior" << endl;
		}
		userChoice = (userChoice == 3) ? 1 : userChoice;
		numWalls = GetNumWalls();
		totalWallArea = CalculateTotalArea(numWalls);
		numPaintCans = CalculateNumPaintCans(totalWallArea);
		numCansRound = ceilf(numPaintCans);
		//determine indicator and can price by whether interior or exterior
		indicateInteriorExterior = (userChoice == 1) ? "interior" : "exterior";
		canPrice = (userChoice == 1) ? "100" : "150";
		totalCost = (userChoice == 1) ? (CalculateInteriorCost(numCansRound)) : (CalculateExteriorCost(numCansRound));
		cout << "\nAs each can covers 400 square feet," << endl
			<< "With area = " << totalWallArea
			<< " square feet, you will need to get " << numPaintCans
			<< "\nSo in total, we need " << numCansRound << " can(s)"
			<< "\nLet's calculate the cost to paint the " << indicateInteriorExterior
			<< " of the house" << endl
			<< "The price of the can is $ " << canPrice << endl
			<< "The total cost for the " << indicateInteriorExterior
			<< " is $ " << totalCost << endl;
		userChoice += 1;
		bothCost += totalCost;
	}
	if (userChoice == 3) {
		cout << "\nThe total cost for interior and exterior is $ " << bothCost << endl;
	}
	return 0;
}