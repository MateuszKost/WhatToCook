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

Recipe RFF::downloadfromfile(std::string FILENAME)
{
	std::string ingname, ingunit; int ingamount;// do listy skladnikow
	std::string recname; int recpreptime, reccalories, aofp; double recwweight, recrate; float reccostf1p;//do listy przepisow
	std::string line;
	//Ingredient* ING;
	LoR LOR;
	Ingredient GIN, TMP;
	Recipe HEAD;
	int helper = 0;
	
	file.open(FILENAME);
	std::cout << "   Zawartosc pliku " << FILENAME << " to:\n\n";

	if (file.good() == false)
	{
		std::cout << "Plik nie istnieje !!!\n";
	}
	/*if (file.good() == true)
	{
		while (getline(file, line))
			std::cout << line << std::endl;
		std::cout << std::endl;
	}

	file.clear();
	file.seekg(0);*/

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
						file >> ingname >> ingamount >> ingunit;
						//TMP.save(ingname, ingamount, ingunit);
						Ingredient Head(ingname, ingamount, ingunit);

						//ING = &Head;
						GIN = Head;
						//GIN = TMP;
						//Head.show_Ing();
						//ING->show_Ing();
						Recipe REC(recname, recpreptime, recwweight, reccalories, aofp, reccostf1p, recrate, &GIN);
						//tmp = REC;
						if (helper == 0)
						{
							HEAD = REC;
							helper++;
						}
						while ((file >> x) && (x == '-'))
						{
							file >> ingname >> ingamount >> ingunit;
							//std::cout << ingname << std::endl;
							Ingredient NEXT(ingname, ingamount, ingunit);
							//TMP.save(ingname, ingamount, ingunit);
							//NEXT.show_Ing();
							//REC.add_to_ingredients_list(TMP);
							REC.add_to_ingredients_list(NEXT);
						}
						LOR.add_to_Rlist(REC);
						//REC.show_Recipe();
						//LOR.show_LoR();
					}
				}
				else
				{
					std::string wyjatek = "Blad w kodzie!!";
					throw wyjatek;
				}
			}
			//std::cout << ingname << ingamount << ingunit << std::endl << std::endl;
		}
		else
		{
			std::string wyjatek = "Blad w kodzie!!";
			throw wyjatek;
		}
		//LOR.show_LoR(); //do sprawdzania pliku
	}
	//GIN.show_Ing();
	LOR.show_LoR(); //do sprawdzania pliku
	//HEAD.show_Recipe();
	return HEAD;
}

RFF::~RFF() {}