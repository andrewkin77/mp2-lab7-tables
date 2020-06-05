#include "ArrayTable.h"

TArrayTable::TArrayTable(int Size)
{
	pRecs = new TTabRecord[Size];
	TabSize = Size;
	DataCount = CurrPos = 0;
}

TArrayTable::~TArrayTable()
{
	delete[] pRecs;
}

bool TArrayTable::IsFull() const
{
	return DataCount >= TabSize;
}

int TArrayTable::GetTabSize() const
{
	return TabSize;
}

TKey TArrayTable::GetKey() const
{
	return GetKey(CURRENT_POS);
}

TValue TArrayTable::GetValue() const
{
	return GetValue(CURRENT_POS);
}

TKey TArrayTable::GetKey(TDataPos mode) const
{ 
	int pos;
	if (!IsEmpty())
	{
		switch (mode)
		{
			case FIRST_POS:
				pos = 0;
				return pRecs[pos].Key;
			case LAST_POS:
				pos = DataCount - 1;
				return pRecs[pos].Key;
			case CURRENT_POS:
				pos = CurrPos;
				return pRecs[pos].Key;
		}
	}
	return 0;
} 

TValue TArrayTable::GetValue(TDataPos mode) const
{
	int pos;
	if (!IsEmpty())
	{
		switch (mode)
		{
			case FIRST_POS:
				pos = 0;
				return pRecs[pos].Value;
			case LAST_POS:
				pos = DataCount - 1;
				return pRecs[pos].Value;
			case CURRENT_POS:
				pos = CurrPos;
				return pRecs[pos].Value;
		}
	}
	return "";
} 

int TArrayTable::Reset()
{
	CurrPos = 0;
	return IsTabEnded();
} 

int TArrayTable::IsTabEnded() const
{
	return CurrPos >= DataCount;
} 

int TArrayTable::GoNext()
{
	if (!IsTabEnded())
		CurrPos++;
	return IsTabEnded();
} 

int TArrayTable::SetCurrentPos(int pos)
{
	CurrPos = ((pos > -1) && (pos < DataCount)) ? pos : 0;
	return IsTabEnded();
}

int TArrayTable::GetCurrentPos() const
{      
	return CurrPos;
}
