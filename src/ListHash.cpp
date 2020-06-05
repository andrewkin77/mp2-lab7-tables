#include "ListHash.h"

TListHashTable::TListHashTable(int size): TabSize(size)
{
    pList = new list<TTabRecord>[TabSize];
}

TListHashTable::~TListHashTable()
{
    delete[] pList;
}

bool TListHashTable::IsFull() const
{
    return false;
}

bool TListHashTable::FindRecord(TKey k)
{
    bool result = false;
    CurrList = HashFunc(k) % TabSize;
    for (CurrI = pList[CurrList].begin(); CurrI != pList[CurrList].end(); CurrI++)
    {
        Efficiency++;
        if(CurrI->GetKey() == k)
        {
            result = true;
            break;
        }
    }
    return result;
}

int TListHashTable::InsRecord(TKey k, TValue val)
{
    if (IsFull())
    {
        return TabFull;
    }
    if (FindRecord(k))
    {
        return TabRecDbl;
    }
    pList[CurrList].push_front(TTabRecord(k, val));
    CurrI--;
    DataCount++;
    return TabOK;
}

int TListHashTable::DelRecord(TKey k)
{
    if (IsEmpty())
    {
        return TabEmpty;
    }
    if (!FindRecord(k))
    {
        return TabNoRec;
    }
    pList[CurrList].erase(CurrI);
    DataCount--;
    return TabOK;
}

int TListHashTable::Reset()
{
    CurrList = 0;
    while(pList[CurrList].begin() == pList[CurrList].end())
    {
        CurrList++;
    }
    CurrI = pList[CurrList].begin();
    return IsTabEnded();
}

int TListHashTable::IsTabEnded() const
{
    return (CurrList >= TabSize - 1) && (CurrI == pList[CurrList].end());
}

int TListHashTable::GoNext()
{
    CurrI++;
    while(CurrI == pList[CurrList].end() && (CurrList < TabSize - 1) )
    {
        CurrList++;
        CurrI = pList[CurrList].begin();
    }
    return IsTabEnded();
}

TKey TListHashTable::GetKey() const { 
    return CurrI->GetKey();
}

TValue TListHashTable::GetValue() const { 
     return CurrI->GetValue();
}

