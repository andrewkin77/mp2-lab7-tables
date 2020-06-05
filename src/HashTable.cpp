#include "HashTable.h"

THashTable::THashTable(): TTable()
{
    
}

unsigned int THashTable::HashFunc(const TKey key)
{
    unsigned int HashVal = key;
    return HashVal;
}
