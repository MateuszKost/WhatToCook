#include "Searching.h"

LoR Searching::searchByAll(int ptime, int amountofp, double cost, LoR LIST)
{
	Recipe* REC = LIST.Rhead;
	LoR LOR;
	Recipe TMP;
	while (REC)
	{
		TMP = *REC;
		if ((REC->preparing_time <= ptime) && (REC->amountofp <= amountofp) && (REC->cost_for_1p <= cost))
		{
			LOR.add_to_Rlist(TMP);
			REC = REC->next;
		}
		else
		{
			REC = REC->next;
		}
	}
	return LOR;
}

LoR Searching::searchByTwo_1(int ptime, int amountofp, LoR LIST)
{
	Recipe* REC = LIST.Rhead;
	LoR LOR;
	Recipe TMP;
	while (REC)
	{
		TMP = *REC;
		if ((REC->preparing_time <= ptime) && (REC->amountofp <= amountofp))
		{
			LOR.add_to_Rlist(TMP);
			REC = REC->next;
		}
		else
		{
			REC = REC->next;
		}
	}
	return LOR;
}

LoR Searching::searchByTwo_2(int ptime, double cost, LoR LIST)
{
	Recipe* REC = LIST.Rhead;
	LoR LOR;
	Recipe TMP;
	while (REC)
	{
		TMP = *REC;
		if ((REC->preparing_time <= ptime) && (REC->cost_for_1p <= cost))
		{
			LOR.add_to_Rlist(TMP);
			REC = REC->next;
		}
		else
		{
			REC = REC->next;
		}
	}
	return LOR;
}

LoR Searching::searchByTwo_3(int amountofp, double cost, LoR LIST)
{
	Recipe* REC = LIST.Rhead;
	LoR LOR;
	Recipe TMP;
	while (REC)
	{
		TMP = *REC;
		if ((REC->amountofp <= amountofp) && (REC->cost_for_1p <= cost))
		{
			LOR.add_to_Rlist(TMP);
			REC = REC->next;
		}
		else
		{
			REC = REC->next;
		}
	}
	return LOR;
}

LoR Searching::searchByOne_1(int ptime, LoR LIST)
{
	Recipe* REC = LIST.Rhead;
	LoR LOR;
	Recipe TMP;
	while (REC)
	{
		TMP = *REC;
		if (REC->preparing_time <= ptime)
		{
			LOR.add_to_Rlist(TMP);
			REC = REC->next;
		}
		else
		{
			REC = REC->next;
		}
	}
	return LOR;
}

LoR Searching::searchByOne_2(int amountofp, LoR LIST)
{
	Recipe* REC = LIST.Rhead;
	LoR LOR;
	Recipe TMP;
	while (REC)
	{
		TMP = *REC;
		if (REC->amountofp <= amountofp)
		{
			LOR.add_to_Rlist(TMP);
			REC = REC->next;
		}
		else
		{
			REC = REC->next;
		}
	}
	return LOR;
}

LoR Searching::searchByOne_3(double cost, LoR LIST)
{
	Recipe* REC = LIST.Rhead;
	LoR LOR;
	Recipe TMP;
	while (REC)
	{
		TMP = *REC;
		if (REC->cost_for_1p <= cost)
		{
			LOR.add_to_Rlist(TMP);
			REC = REC->next;
		}
		else
		{
			REC = REC->next;
		}
	}
	return LOR;
}

LoR Searching::search(int time, int amountofp, double cost, LoR LIST)
{
	LoR TMP = LIST;
	LoR LOR;
	if ((time != 0) && (amountofp != 0) && (cost != 0))
	{
		LOR = Searching::searchByAll(time, amountofp, cost, TMP);
	}
	else if ((time != 0) && (amountofp != 0) && (cost == 0))
	{
		LOR = Searching::searchByTwo_1(time, amountofp, TMP);
	}
	else if ((time != 0) && (amountofp == 0) && (cost != 0))
	{
		LOR = Searching::searchByTwo_2(time, cost, TMP);
	}
	else if ((time == 0) && (amountofp != 0) && (cost != 0))
	{
		LOR = Searching::searchByTwo_3(amountofp, cost, TMP);
	}
	else if ((time != 0) && (amountofp == 0) && (cost == 0))
	{
		LOR = Searching::searchByOne_1(time, TMP);
	}
	else if ((time == 0) && (amountofp != 0) && (cost == 0))
	{
		LOR = Searching::searchByOne_2(amountofp, TMP);
	}
	else if ((time == 0) && (amountofp == 0) && (cost != 0))
	{
		LOR = Searching::searchByOne_3(cost, TMP);
	}
	return LOR;
}