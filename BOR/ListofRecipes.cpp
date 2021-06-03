#include "ListofRecipes.h"
#include "Recipe.h"
#include "UnitExtraction.h"

LoR::LoR()
{
	Uhead = nullptr;
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

void LoR::add_to_UElist(UE UNIT)
{
	if (Uhead == nullptr)
	{
		Uhead = new UE(UNIT);
		Uhead->UEnext = nullptr;
	}
	else
	{
		UE* another = new UE(UNIT);
		UE* tmp = Uhead;
		while (tmp->UEnext != nullptr)
		{
			tmp = tmp->UEnext;
		}
		tmp->UEnext = another;
		another->UEnext = nullptr;
	}
}

void LoR::show_LoU()
{
	if (this->Uhead)// nie jestem pewien czy nie powinno tu byc samego RHead
	{
		UE* R = Uhead;
		while (R)
		{
			R->show_UE();
			R = R->UEnext;
		}
	}
	else
	{
		std::cout << " Niestety zadna jednostka nie zostala dodany !" << std::endl;
	}
}

void LoR::show_LoR()
{
	if (this->Rhead)// nie jestem pewien czy nie powinno tu byc samego RHead
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

void LoR::unique(LoR LIST)
{
	UE* HEAD, * TMP, * tmp;
	TMP = LIST.Uhead;
	while (TMP)
	{
		HEAD = TMP;
		while (HEAD->UEnext)
			if (HEAD->UEnext->unit_extr == TMP->unit_extr)
			{
				tmp = HEAD->UEnext;
				HEAD->UEnext = tmp->UEnext;
				delete tmp;
			}
			else HEAD = HEAD->UEnext;
		TMP = TMP->UEnext;
	}
}

LoR LoR::extraction(LoR LIST)
{
	Recipe* TMP = LIST.Rhead;
	std::string unitname;
	LoR LoU;

	while (TMP)
	{
		Ingredient* ING = TMP->Ihead;
		while (ING)
		{
			if (unitname != ING->unit)
			{
				unitname = ING->unit;
				UE UE(unitname);
				LoU.add_to_UElist(UE);
			}
			ING = ING->Next;
		}
		TMP = TMP->next;
	}
	LoU.unique(LoU);
	return LoU;
};

void LoR::delete_LoR()
{
	Recipe* x;
	while (Rhead)
	{
		x = Rhead->next;
		Rhead->delete_listofingredients();
		delete Rhead;
		Rhead = x;
	}
	Rhead = NULL;
}

void LoR::delete_LoU()
{
	UE* x;
	while (Uhead)
	{
		x = Uhead->UEnext;
		delete Uhead;
		Uhead = x;
	}
	Uhead = NULL;
}

LoR::~LoR() {
	//std::cout << "\n\n XDDD jestem\n\n";
};
