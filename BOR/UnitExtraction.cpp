#include "UnitExtraction.h"

UE::UE() {};

UE::UE(std::string xunitname)
{
	unit_extr = xunitname;
}

void UE::show_UE()
{
	std::cout << " Nazwa jednostki: " <<this->unit_extr << std::endl;
};