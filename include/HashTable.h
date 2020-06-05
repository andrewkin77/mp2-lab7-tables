#ifndef HashTable_h
#define HashTable_h

#include "Table.h"

class THashTable: public TTable
{
protected:
    virtual unsigned int HashFunc(const TKey key);
public:
    THashTable();
};
    
#endif
