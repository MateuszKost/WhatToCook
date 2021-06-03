#include "Raport.h"
#include "Fridge.h"

Raport::Raport(std::string xfilename)
{
	Tfilename = xfilename;
};

std::ostream& operator<<(std::ostream& file, Ingredient*& Ing)
{
	file << Ing->Iname << " " << Ing->amount << " " << Ing->unit<< "\n";
	return file;
}

void Raport::send_to_file(Ingredient* ING, std::string where, std::string fname)
{
	Tfilename = fname;
	//int Ramount;
	//std::string Rname, Runit;
	std::string lineone, linetwo; //linethree;
	Tfile.open(Tfilename);
	lineone = "Gdzie pojda resztki: ";
	linetwo =  "\nA to pozostalosci: \n";
	//linethree = "\n";
	Tfile.write(&lineone[0], lineone.length());
	Tfile << where;
	Tfile.write(&linetwo[0], linetwo.length());
	while (ING)
	{
		//Rname = ING->Iname;
		//Ramount = ING->amount;
		//Runit = ING->unit;
		//Tfile << Rname << " " << Ramount << " " << Runit;
		Tfile << ING;
		//Tfile.write(&linethree[0], linethree.length());
		ING = ING->Next;
	}

	Tfile.close();
}


Raport::~Raport() {};