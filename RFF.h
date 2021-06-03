#pragma once
#include <iostream>
#include <fstream>
#include "ListofRecipes.h"

class RFF  // recipes from file
{
public:
	std::string filename;
	std::fstream file;

public:
	RFF(std::string);
	Recipe downloadfromfile(std::string);
	~RFF();
};