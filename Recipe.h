#pragma once
#include <iostream>
#include "Ingredient.h"

class Recipe
{
public:
	std::string Rname;
	int preparing_time;
	double weight;
	int calories;
	int amountofp;//amount of people
	double cost_for_1p;//1 person
	double rate;
	Ingredient* Ihead;


	Recipe(std::string xRname, int pt, double w, int cal, int aop, double cf1p, double rat, Ingredient* h);
	Recipe();
	void add_to_ingredients_list(Ingredient Ing);
	//void show_LoI();//List of Ingredients
	void delete_listofingredients();
	void show_Recipe();
	~Recipe();
	Recipe* next;
};