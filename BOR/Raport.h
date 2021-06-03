#pragma once
#include <iostream>
#include <fstream>
#include "Ingredient.h"

class Raport
{
public:
	std::string Tfilename;
	std::ofstream Tfile;

	Raport (std::string);
	void send_to_file(Ingredient*, std::string, std::string);
	friend std::ostream& operator<<(std::ostream& o, Ingredient*& Ing);
	~Raport();
};