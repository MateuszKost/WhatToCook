#pragma once
#include <iostream>
#include "ListofRecipes.h"


class Searching : public LoR // looking for recipes in LOR
{
public:

	LoR search(int, int, double, Recipe);

	LoR searchByAll(int, int, double, Recipe);
	LoR searchByTwo_1(int, int, Recipe);
	LoR searchByTwo_2(int, double, Recipe);
	LoR searchByTwo_3(int, double, Recipe);
	LoR searchByOne_1(int, Recipe);
	LoR searchByOne_2(int, Recipe);
	LoR searchByOne_3(double, Recipe);
};