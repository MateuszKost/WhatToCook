#include "Ingredient.h"
#include "Recipe.h"
#include<iomanip>

Recipe::Recipe() {};

Recipe::Recipe(std::string xname, int pt, double w, int cal, int aop, double cf1p, double rat, Ingredient* h)
{
	Rname = xname;
	preparing_time = pt;
	weight = w;
	calories = cal;
	amountofp = aop;
	cost_for_1p = cf1p;
	rate = rat;
	Ihead = h;
}

void Recipe::add_to_ingredients_list(Ingredient Ing)
{
	if (this->Ihead == nullptr)
	{
		Ihead = new Ingredient(Ing);
		Ihead->Next = nullptr;
	}
	else
	{
		Ingredient* another = new Ingredient(Ing);
		Ingredient* tmp = Ihead;
		while (tmp->Next != nullptr)
		{
			tmp = tmp->Next;
		}
		tmp->Next = another;
		another->Next = nullptr;
	}
}

void Recipe::show_Recipe()
{
	std::cout << "\n Nazwa: " << this->Rname << " | " << " ocena: " << this->rate << std::endl;
	std::cout << " Czas przygotowania: " << this->preparing_time << " | " << " waga: " << this->weight << " | " << " kalorie: " << this->calories << " | " << " ilosc osob: " << this->amountofp << " | " <<" cena za osobe: "<<this->cost_for_1p << std::endl;
	std::cout << "\nSkladniki:" << std::endl; 
	if (this->Ihead)
	{
		int nr = 1;
		Ingredient* I = Ihead;
		while (I)
		{
			std::cout <<" "<< nr << ". ";
			I->show_Ing();
			nr++;
			I = I->Next;
		}
	}
}

void Recipe::delete_listofingredients()
{
	Ingredient* x;
	while (Ihead)
	{
		x = Ihead->Next;
		delete Ihead;
		Ihead = x;
	}
	Ihead = NULL;
}

Recipe::~Recipe() {
	//std::cout << "\n\n jestem XDDD\n\n";
}
