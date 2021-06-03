#pragma once
#include "Ingredient.h"
#include "Recipe.h"
#include "ListofRecipes.h"

class Fridge : public Ingredient, public Recipe, public LoR  //should be kitchen but i am not sur
{
public:
	void save(std::string, int, std::string);
	void show_LOF();
	LoR compare_FandInginRec(Ingredient *, LoR LOR);
	Fridge* Next;
};

//this class creates list of products in your kitchen or fridge