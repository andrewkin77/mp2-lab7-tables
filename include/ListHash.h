#ifndef ListHash_h
#define ListHash_h

#include <list>
#include "HashTable.h"

using namespace std;

class TListHashTable: public THashTable
{
protected:
    list<TTabRecord> *pList;
    int TabSize;
    int CurrList;
    list<TTabRecord>::iterator CurrI;
    
public:
    TListHashTable(int size = TabMaxSize);
    virtual ~TListHashTable();
    
    virtual bool IsFull() const;
    virtual bool FindRecord(TKey k);
    virtual int InsRecord(TKey k, TValue Val);
    virtual int DelRecord(TKey k);

    virtual int Reset(void);
    virtual int IsTabEnded(void) const;
    virtual int GoNext(void);

    virtual TKey GetKey(void) const;
    virtual TValue GetValue(void) const;
};

#endif
