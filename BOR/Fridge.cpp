#include "Fridge.h"


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

LoR Fridge::compare_FandInginRec(Ingredient *ING, LoR LIST)
{
	bool did = false;
	Recipe *TMP = LIST.Rhead;
	Recipe recipe;
	LoR listofF;
	Ingredient* Ftmp = ING;

	while (TMP)
	{
		recipe = *TMP;
		Ingredient* tmpING = TMP->Ihead;
		while (TMP->Ihead)
		{
			if ((tmpING->Iname == ING->Iname) && (tmpING->amount <= ING->amount) && (tmpING != nullptr))
			{
				did = true;
				if ((!tmpING ->Next) && (did == true))
				{
					listofF.add_to_Rlist(recipe);
					goto end;
				}
				if (tmpING->Next)
				{
					tmpING = tmpING->Next;
				}//przechodzimy na nastepny skladnik przepisu
				if (ING->Next)
				{
					ING = ING->Next;
				}
				else
				{
					ING = Ftmp;
				}
			}
			else
			{
				ING = ING->Next;
			}
			if ((!ING)&&(did==true))
			{
				did = false;
				ING = Ftmp;
			}
			else if ((!ING) && (did==false))
			{
				ING = Ftmp;
				goto end;
			}
		}
	end:
		TMP = TMP->next;
	}
	return listofF;
}