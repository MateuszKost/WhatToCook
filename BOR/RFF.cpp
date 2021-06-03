#include "Ingredient.h"
#include "ListofRecipes.h"
#include "RFF.h"
#include "Recipe.h"
#include <string>
#include <fstream>

RFF::RFF(std::string xfilename)
{
	filename = xfilename;
}

std::istream& operator>>(std::istream &file, Ingredient &Ing)
{
	file >> Ing.Iname >> Ing.amount >> Ing.unit;
	return file;
}


LoR RFF::downloadfromfile(std::string FILENAME)
{
	std::string recname; int recpreptime, reccalories, aofp; double recwweight, recrate; float reccostf1p;//do listy przepisow
	LoR LOR;
	
	file.open(FILENAME);

	if (file.good() == false)
	{
		std::cout << "Plik nie istnieje !!!\n";
	}

	char x, y;

	if (file.good() == true)
	{
		file >> y;
		x = '*';

		if (y == '*')
		{
			while (file >> recname >> recpreptime >> recwweight >> reccalories >> aofp >> reccostf1p >> recrate)
			{
				if (x == '*')
				{
					file >> x;
					if (x == '-')
					{
						Ingredient Head;
						file >> Head;
						Recipe REC(recname, recpreptime, recwweight, reccalories, aofp, reccostf1p, recrate, Head);

						while ((file >> x) && (x == '-'))
						{
							Ingredient NEXT;
							file >> NEXT;
							REC.add_to_ingredients_list(NEXT);
						}
						LOR.add_to_Rlist(REC);
					}
				}
				else
				{
					std::string wyjatek = "Blad w kodzie!!";
					throw wyjatek;
				}
			}
		}
		else
		{
			std::string wyjatek = "Blad w kodzie!!";
			throw wyjatek;
		}
	}
	return LOR;
}

RFF::~RFF() {}