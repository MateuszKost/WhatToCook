#pragma once
#include <iostream>
#include <fstream>
#include "ListofRecipes.h"

class RFF  // recipes from file
{
public:
	std::string filename;
	std::fstream file;

	RFF(std::string);
	friend std::istream& operator>>(std::istream& s, Ingredient& p);
	LoR downloadfromfile(std::string);
	~RFF();
};