#include"Ingredient.h"
#include<iomanip>

Ingredient::Ingredient(){};

Ingredient::Ingredient(std::string xname, int xamount, std::string xunit)
{
	Iname = xname;
	amount = xamount;
	unit = xunit;
}

void Ingredient::save(std::string Fname, int Famount, std::string Funit)
{
	Iname = Fname;
	amount = Famount;
	unit = Funit;
}

void Ingredient::show_Ing()
{
	//std::cout << std::setw(15) << this->Iname << this->amount << this->unit <<std::endl;
	std::cout <<this->Iname<< " " << this->amount << " " << this->unit << std::endl;
}

Ingredient::~Ingredient() {
	//std::cout << "\n\n jestem OOOO\n\n";
};