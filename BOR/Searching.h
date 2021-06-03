#pragma once
#include <iostream>
#include "ListofRecipes.h"


class Searching : public LoR // looking for recipes in LOR
{
public:

	LoR search(int, int, double, LoR);

	LoR searchByAll(int, int, double, LoR);
	LoR searchByTwo_1(int, int, LoR);
	LoR searchByTwo_2(int, double, LoR);
	LoR searchByTwo_3(int, double, LoR);
	LoR searchByOne_1(int, LoR);
	LoR searchByOne_2(int, LoR);
	LoR searchByOne_3(double, LoR);
};