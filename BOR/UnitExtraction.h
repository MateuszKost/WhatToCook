#pragma once
#include <iostream>

class UE 
{
public:
	std::string unit_extr;
	UE();
	UE(std::string);
	void show_UE();
	UE* UEnext = nullptr;
};