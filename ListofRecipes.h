#pragma once
#include "Recipe.h"

class LoR // list of recipes
{
protected:
	Recipe* Rhead;

public:
	LoR();
	void add_to_Rlist(Recipe Rec);
	void show_LoR();
	~LoR();
};