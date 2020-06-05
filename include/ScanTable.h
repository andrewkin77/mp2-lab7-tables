#pragma once

#include "ArrayTable.h"

class TScanTable : public TArrayTable
{
public:

	TScanTable(int Size = TabMaxSize) : TArrayTable(Size) { };

	virtual bool FindRecord(TKey k);  
	virtual int InsRecord(TKey k, TValue Val); 
	virtual int DelRecord(TKey k); 
};