#pragma once
#include "Recipe.h"
#include "UnitExtraction.h"

class LoR : public UE// list of recipes
{
public:
	Recipe* Rhead;
	UE* Uhead = nullptr;

	LoR();
	void add_to_Rlist(Recipe Rec);
	void show_LoR();
	void show_LoU();
	void delete_LoR();
	void add_to_UElist(UE UNIT);

	void unique(LoR);
	LoR extraction(const LoR);
	void delete_LoU();
	~LoR();
};