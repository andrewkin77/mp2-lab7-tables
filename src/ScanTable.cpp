#include "ScanTable.h"

bool TScanTable::FindRecord(TKey k)
{
	int i;
	for (i = 0; i < DataCount; i++)
	{
		if (pRecs[i].Key == k)
			break;
		Efficiency++;
	}
	if (i < DataCount)
	{
		CurrPos = i;
		return true;
	}
	return false;
}

int TScanTable::InsRecord(TKey k, TValue Val)
{
	if (IsFull())
	{
		return TabFull;
	}
	if (FindRecord(k))
    {
        return TabRecDbl;
    }
		pRecs[DataCount].Key = k;
		pRecs[DataCount].Value = Val;
		DataCount++;
        Efficiency++;
		return TabOK;
}

int TScanTable::DelRecord(TKey k)
{
    if (IsEmpty())
    {
        return TabEmpty;
    }
	if (!FindRecord(k))
	{
		return TabNoRec;
	}
	pRecs[CurrPos] = pRecs[DataCount - 1];
	DataCount--;
	return TabOK;
}
