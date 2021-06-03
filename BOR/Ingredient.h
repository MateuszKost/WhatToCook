#pragma once
#include<iostream>
class Ingredient
{
public:
	std::string Iname;
	int amount = 0;
	std::string unit;

	Ingredient();
	Ingredient(std::string xIname, int xamount, std::string xunit);
	void save(std::string xIname, int xamount, std::string xunit);
	void show_Ing();
	Ingredient* Next = nullptr;
	~Ingredient();
};