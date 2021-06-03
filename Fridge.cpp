#include "Fridge.h"

//Fridge::Fridge(std::string xname, int amount, std::string xunit)
//{
	//Iname = xname;
	//amount = amount;
	//unit = xunit;
//}

//Fridge::~Fridge() {};

void Fridge::save(std::string Fname, int Famount, std::string Funit)
{
	Iname = Fname;
	amount = Famount;
	unit = Funit;
}

void Fridge::show_LOF()
{
	if (this->Ihead)
	{
		int nr = 1;
		Ingredient* I = Ihead;
		while (I)
		{
			std::cout << " " << nr << ". ";
			I->show_Ing();
			nr++;
			I = I->Next;
		}
	}
}

LoR Fridge::compare_FandInginRec(Fridge F, Recipe Rec)
{
	bool did = false;
	Rhead = &Rec;
	LoR list;
	Fridge* FRIDGE;
	FRIDGE = &F;
	Fridge* Ftmp;
	Ftmp = FRIDGE;
	while (Rhead)
	{
		while (Rhead->Ihead)
		{
			if ((Rhead->Ihead->Iname == FRIDGE->Iname) && (Rhead->Ihead->amount <= FRIDGE->amount)&&(Rhead->Ihead != nullptr))
			{
				did = true;
				Ihead = Ihead->Next;//przechodzimy na nastepny skladnik przepisu
				if (FRIDGE->Next)
				{
					FRIDGE = FRIDGE->Next;
				}
				else
				{
					FRIDGE = Ftmp;
				}
			}
			else
			{
				FRIDGE = FRIDGE->Next;
			}

			if (!Rhead->Ihead)
			{
				Rec = *Rhead;
				list.add_to_Rlist(Rec);
				goto end;
			}

			if ((!FRIDGE)&&(did==true))
			{
					FRIDGE = Ftmp;
			}
			else if ((!FRIDGE) && (did==false))
			{
				goto end;
			}
		}
	end:
		Rhead = Rhead->next;
	}
	return list;
}