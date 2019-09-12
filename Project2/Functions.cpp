#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int MainMenu() {
	int userChoice;
	//display menu to user
	cout << "Welcome to Paint Shop" << endl
		<< "Here are the options you can choose from:" << endl
		<< "1 - Paint the interior of a house" << endl
		<< "2 - Paint the exterior of a house" << endl
		<< "3 - Paint both the interior and the exterior of a house" << endl
		<< "Which option do you choose?" << endl;
	cin >> userChoice;
	//while loop insures user selects valid option
	while (userChoice <= 0 || userChoice >= 4) {
		cout << "Please input a valid number" << endl;
		cin >> userChoice;
	}
	return userChoice;
}
int GetNumWalls() {
	int numWalls;
	cout << "\nHow many walls do you want to paint?" << endl;
	cin >> numWalls;
	//while loop insures nonnegative input
	while (numWalls < 0) {
		cout << "Please input a valid number" << endl;
		cin >> numWalls;
	}
	return numWalls;
}
float GetWallLength() {
	float wallLength;
	cout << "Length = ";
	cin >> wallLength;
	//while loop insures nonnegative input
	while (wallLength < 0) {
		cout << "Please input a valid number" << endl;
		cin >> wallLength;
	}
	return wallLength;
}
float GetWallHeight() {
	float wallHeight;
	cout << "Height = ";
	cin >> wallHeight;
	//while loop insures nonnegative input
	while (wallHeight < 0) {
		cout << "Please input a valid number" << endl;
		cin >> wallHeight;
	}
	return wallHeight;
}
float CalculateWallArea(float length, float height) {
	float wallArea;
	wallArea = length * height;
	return wallArea;
}
float CalculateTotalArea(int numWalls) {
	/*get length and height for each wall, calculate wall area,
	and add it to running total area*/
	float totalArea = 0.0f, wallLength, wallHeight, wallArea;
	for (int i = 1; i <= numWalls; ++i) {
		cout << "\nWhat is the length and height for wall " << i << " : " << endl;
		wallLength = GetWallLength();
		wallHeight = GetWallHeight();
		wallArea = CalculateWallArea(wallLength, wallHeight);
		totalArea += wallArea;
	}
	return totalArea;
}
float CalculateNumPaintCans(float totalArea) {
	float numPaintCans;
	const float COVERAGE = 400.0f; //can of paint covers 400 square feet
	numPaintCans = totalArea / COVERAGE;
	return numPaintCans;
}
float CalculateInteriorCost(int numPaintCansINT) {
	float interiorCost;
	const float CAN_PRICE = 100.0f;
	interiorCost = numPaintCansINT * CAN_PRICE;
	return interiorCost;
}
float CalculateExteriorCost(int numPaintCansINT) {
	float exteriorCost;
	const float CAN_PRICE = 150.0f;
	exteriorCost = numPaintCansINT * CAN_PRICE;
	return exteriorCost;
}