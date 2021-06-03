#include "Searching.h"

LoR Searching::searchByAll(int ptime, int amountofp, double cost, Recipe REC)
{
	LoR LOR;
	Rhead = &REC;
	Recipe TMP;
	while (Rhead)
	{
		if ((Rhead->preparing_time <= ptime) && (Rhead->amountofp <= amountofp) && (Rhead->cost_for_1p <= cost))
		{
			TMP = *Rhead;
			LOR.add_to_Rlist(TMP);
			Rhead = Rhead->next;
		}
		else
		{
			Rhead = Rhead->next;
		}
	}
	return LOR;
}

LoR Searching::searchByTwo_1(int ptime, int amountofp, Recipe REC)
{
	LoR LOR;
	Rhead = &REC;
	Recipe TMP;
	while (Rhead)
	{
		if ((Rhead->preparing_time <= ptime) && (Rhead->amountofp <= amountofp))
		{
			TMP = *Rhead;
			LOR.add_to_Rlist(TMP);
			Rhead = Rhead->next;
		}
		else
		{
			Rhead = Rhead->next;
		}
	}
	return LOR;
}

LoR Searching::searchByTwo_2(int ptime, double cost, Recipe REC)
{
	LoR LOR;
	Rhead = &REC;
	Recipe TMP;
	while (Rhead)
	{
		if ((Rhead->preparing_time <= ptime) && (Rhead->cost_for_1p <= cost))
		{
			TMP = *Rhead;
			LOR.add_to_Rlist(TMP);
			Rhead = Rhead->next;
		}
		else
		{
			Rhead = Rhead->next;
		}
	}
	return LOR;
}

LoR Searching::searchByTwo_3(int amountofp, double cost, Recipe REC)
{
	LoR LOR;
	Rhead = &REC;
	Recipe TMP;
	while (Rhead)
	{
		if ((Rhead->amountofp <= amountofp) && (Rhead->cost_for_1p <= cost))
		{
			TMP = *Rhead;
			LOR.add_to_Rlist(TMP);
			Rhead = Rhead->next;
		}
		else
		{
			Rhead = Rhead->next;
		}
	}
	return LOR;
}

LoR Searching::searchByOne_1(int ptime, Recipe REC)
{
	LoR LOR;
	Rhead = &REC;
	Recipe TMP;
	while (Rhead)
	{
		if (Rhead->preparing_time <= ptime)
		{
			TMP = *Rhead;
			LOR.add_to_Rlist(TMP);
			Rhead = Rhead->next;
		}
		else
		{
			Rhead = Rhead->next;
		}
	}
	return LOR;
}

LoR Searching::searchByOne_2(int amountofp, Recipe REC)
{
	LoR LOR;
	Rhead = &REC;
	Recipe TMP;
	while (Rhead)
	{
		if (Rhead->amountofp <= amountofp)
		{
			TMP = *Rhead;
			LOR.add_to_Rlist(TMP);
			Rhead = Rhead->next;
		}
		else
		{
			Rhead = Rhead->next;
		}
	}
	return LOR;
}

LoR Searching::searchByOne_3(double cost, Recipe REC)
{
	LoR LOR;
	Rhead = &REC;
	Recipe TMP;
	while (Rhead)
	{
		if (Rhead->cost_for_1p <= cost)
		{
			TMP = *Rhead;
			LOR.add_to_Rlist(TMP);
			Rhead = Rhead->next;
		}
		else
		{
			Rhead = Rhead->next;
		}
	}
	return LOR;
}

LoR Searching::search(int time, int amountofp, double cost, Recipe REC)
{
	LoR LOR;
	if ((time != 0) && (amountofp != 0) && (cost != 0))
	{
		LOR = Searching::searchByAll(time, amountofp, cost, REC);
	}
	else if ((time != 0) && (amountofp != 0) && (cost == 0))
	{
		LOR = Searching::searchByTwo_1(time, amountofp, REC);
	}
	else if ((time != 0) && (amountofp == 0) && (cost != 0))
	{
		LOR = Searching::searchByTwo_2(time, cost, REC);
	}
	else if ((time == 0) && (amountofp != 0) && (cost != 0))
	{
		LOR = Searching::searchByTwo_3(amountofp, cost, REC);
	}
	else if ((time != 0) && (amountofp == 0) && (cost == 0))
	{
		LOR = Searching::searchByOne_1(time, REC);
	}
	else if ((time == 0) && (amountofp != 0) && (cost == 0))
	{
		LOR = Searching::searchByOne_2(amountofp, REC);
	}
	else if ((time == 0) && (amountofp == 0) && (cost != 0))
	{
		LOR = Searching::searchByOne_3(cost, REC);
	}
	return LOR;
}