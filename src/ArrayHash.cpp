#include "ArrayHash.h"

TArrayHashTable::TArrayHashTable(int size, int step): TabSize(size), HashStep(step)
{
    pRecs = new TTabRecord[TabSize];
    Empty = TTabRecord(-1);
    Mark = TTabRecord(-2);
    for (int i = 0; i < TabSize; i++)
    {
        pRecs[i] = Empty;
    }
}

TArrayHashTable::~TArrayHashTable()
{
    delete[] pRecs;
}

 int TArrayHashTable::GetNextPos(int pos)
{
    return (pos+HashStep) % TabSize;
}

bool TArrayHashTable::IsFull() const
{
    return DataCount >= TabSize;
}

bool TArrayHashTable::FindRecord(TKey k)
{
    bool result = false;
    FreePos = -1;
    CurrPos = HashFunc(k) % TabSize;
    for (int i = 0; i < TabSize; i++)
    {
        Efficiency++;
        if (pRecs[CurrPos] == Empty)
            break;
        else if (pRecs[CurrPos] == Mark)
        {
            if(FreePos == -1)
                FreePos = CurrPos;
        }
        else if(pRecs[CurrPos].GetKey() == k)
        {
            result = true;
            break;
        }
        CurrPos = GetNextPos(CurrPos);
    }
    return result;
}

int TArrayHashTable::InsRecord(TKey k, TValue val)
{
    if(IsFull())
    {
        return TabFull;
    }
    else if(FindRecord(k))
    {
      return TabRecDbl;
    }
    else
    {
      if(FreePos != -1)
      {
          CurrPos = FreePos;
      }
      pRecs[CurrPos] = TTabRecord(k, val);
      DataCount++;
      return TabOK;
    }
    }

int TArrayHashTable::DelRecord(TKey k)
{
    if (IsEmpty())
    {
        return TabEmpty;
    }
    if (!FindRecord(k))
    {
        return TabNoRec;
    }
    pRecs[CurrPos] = Mark;
    DataCount--;
    return TabOK;
}

int TArrayHashTable::Reset()
{
    CurrPos = 0;
    while(CurrPos < TabSize)
    {
        if((pRecs[CurrPos] != Empty) && (pRecs[CurrPos] != Mark))
        {
            break;
        }
        else
        {
            CurrPos++;
        }
    }
    return IsTabEnded();
}

int TArrayHashTable::IsTabEnded() const
{
    return CurrPos >= TabSize;
}

int TArrayHashTable::GoNext()
{
    CurrPos++;
    while(CurrPos < TabSize)
    {
        if((pRecs[CurrPos] != Empty) && (pRecs[CurrPos] != Mark))
        {
            break;
        }
        else
        {
            CurrPos++;
        }
    }
    return IsTabEnded();
}

TKey TArrayHashTable::GetKey() const
{
    return pRecs[CurrPos].GetKey();
}

TValue TArrayHashTable::GetValue() const
{
    return pRecs[CurrPos].GetValue();
}
