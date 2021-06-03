#include "ListofRecipes.h"
#include "Recipe.h"

LoR::LoR()
{
	Rhead = nullptr;
}

void LoR::add_to_Rlist(Recipe Rec)
{
	if (Rhead == nullptr)
	{
		Rhead = new Recipe(Rec);
		Rhead->next = nullptr;
	}
	else
	{
		Recipe* another = new Recipe(Rec);
		Recipe* tmp = Rhead;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = another;
		another->next = nullptr;
	}
}

void LoR::show_LoR()
{
	if (Rhead)// nie jestem pewien czy nie powinno tu byc samego RHead
	{
		Recipe* R = Rhead;
		while (R)
		{
			R->show_Recipe();
			std::cout << std::endl;
			R = R->next;
		}
	}
	else
	{
		std::cout << " Niestety zaden przepis nie zostal dodany !" << std::endl;
	}
}

LoR::~LoR() {
	//std::cout << "\n\n XDDD jestem\n\n";
};
