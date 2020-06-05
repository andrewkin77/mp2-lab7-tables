#include "SortTable.h"

TSortTable::TSortTable(const TScanTable &tab)
{
	*this = tab;
}

TSortTable& TSortTable::operator=(const TScanTable &tab)
{
	if (!pRecs)
	{
		delete[] pRecs;
		delete[] pBuff;
	}
	TabSize = tab.GetTabSize();
	DataCount = tab.GetDataCount();
	pRecs = new TTabRecord[TabSize];
	pBuff = new TTabRecord[TabSize];
	for (int i = 0; i < DataCount; i++) {
		pRecs[i] = tab.pRecs[i];
	}
	SortData();
	CurrPos = 0;
	return *this;
} 

void TSortTable::SetSortMethod(TSortMethod mode)
{
	SortMethod = mode;
}

TSortMethod TSortTable::GetSortMethod()
{
    return SortMethod;
}

bool TSortTable::FindRecord(TKey k)
{
	int i, i1 = 0, i2 = DataCount - 1;                                                    
	while (i1 <= i2)
	{
		Efficiency++;
		i = (i1 + i2)/2;
		if (pRecs[i].Key == k)
		{
			i1 = i + 1;
			i2 = i;
			break;
		}
		if (pRecs[i].Key > k)
			i2 = i - 1;
		else
			i1 = i + 1;
	}
	if ((i2 < 0) || (pRecs[i2].Key < k))
		i2++;
	CurrPos = i2;
	if ((i2 < DataCount) && (pRecs[i].Key == k))
	{
		return true;
	}
	return false;                                                      
} 

int TSortTable::InsRecord(TKey k, TValue Val)
{
	if (IsFull())
	{
		return TabFull;
	}
	else
	{
		if(FindRecord(k))
			return TabRecDbl;
		for (int i = DataCount; i > CurrPos; i--)
		{
			pRecs[i] = pRecs[i - 1];
			Efficiency++;
		}
		TTabRecord t(k, Val);
		pRecs[CurrPos] = t;
		DataCount++;
		return TabOK;
	}
} 
int TSortTable::DelRecord(TKey k)
{
    if (IsEmpty())
    {
        return TabEmpty;
    }
	if(!FindRecord(k))
    {
		return TabNoRec;
    }
	for (int i = CurrPos; i < DataCount - 1; i++)
    {
        Efficiency++;
		pRecs[i] = pRecs[i + 1];
    }
	DataCount--;
	return TabOK;                                                              
} 

void TSortTable::SortData()
{
	Efficiency = 0;
	switch (SortMethod)
	{
	case INSERT_SORT:
		InsertSort(); 
		break;
	case MERGE_SORT:
		MergeSort(); 
		break;
	}
} 

void TSortTable::InsertSort()
{
	int pos; 
	TTabRecord st;
    for (int i = 1; i < DataCount; i++)
    {
        pos=0;
        for (int j = i-1; j >= 0; j--){
            Efficiency++;
            if (pRecs[j]<=pRecs[i])
            {
                pos = j+1; break;
            }
        }
        st = pRecs[i];
        for (int k = i-1; k >= pos; k--){
            pRecs[k+1] = pRecs[k];
            Efficiency++;
        }
        pRecs[pos] = st;
    }
}

void TSortTable::MergeSort()
{
	MergeSorter(0, DataCount-1);
}

void TSortTable::MergeSorter(int start, int finish)
{
    if (start == finish)
        return;
    else
    {
        int mid = (start + finish)/2;
        MergeSorter(start, mid);
        MergeSorter(mid+1, finish);
        MergeData(start, mid, finish);
    }
}

void TSortTable::MergeData(int start, int mid, int finish)
{
	int i = start, j = mid + 1, pos = start;
    while (i <= mid && j <= finish)
    {
        if (pRecs[i] > pRecs[j])
        {
            pBuff[pos] = pRecs[j];
            j++;
            pos++;
        }
        else
        {
            pBuff[pos] = pRecs[i];
            i++;
            pos++;
        }
    }
    if (i > mid)
    {
        for (; j <= finish; j++)
        {
            pBuff[pos] = pRecs[j];
            pos++;
        }
    }
    else
    {
        for (; i <= mid; i++)
        {
            pBuff[pos] = pRecs[i];
            pos++;
        }
    }
    for (i = start; i <= finish; i++)
    {
        pRecs[i] = pBuff[i];
    }
}
