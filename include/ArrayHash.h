#ifndef ArrayHash_h
#define ArrayHash_h

#include "HashTable.h"

#define TabHashStep 7

class TArrayHashTable: public THashTable
{
protected:
    TTabRecord *pRecs;
    int TabSize;
    int HashStep;
    int FreePos;
    int CurrPos;
    TTabRecord Mark;
    TTabRecord Empty;
    
    int GetNextPos(int pos);
public:
    TArrayHashTable(int size = TabMaxSize, int step = TabHashStep);
    virtual ~TArrayHashTable();
    
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
