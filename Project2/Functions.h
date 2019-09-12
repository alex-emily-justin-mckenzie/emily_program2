#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int MainMenu();
float CalculateWallArea(float length, float height);
float CalculateTotalArea(int numWalls);
float CalculateNumPaintCans(float totalArea);
float CalculateInteriorCost(int numPaintCansINT);
float CalculateExteriorCost(int numPaintCansINT);
int GetNumWalls();
float GetWallLength();
float GetWallHeight();