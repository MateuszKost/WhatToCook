#pragma once
#include "Ingredient.h"
#include "Recipe.h"
#include "ListofRecipes.h"

class Fridge : public Ingredient, public Recipe, public LoR  //should be kitchen but i am not sur
{
public:
	//Fridge(std::string xname, int xamount, std::string xunit);
	//~Fridge();
	void save(std::string, int, std::string);
	void show_LOF();
	LoR compare_FandInginRec(Fridge F, Recipe Rec);
	Fridge* Next;
};

//this class creates list of products in your kitchen or fridge