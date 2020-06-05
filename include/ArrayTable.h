#pragma once
#include "Table.h"

#define TabMaxSize 25

enum TDataPos { FIRST_POS, CURRENT_POS, LAST_POS };

class TArrayTable : public TTable
{

protected:
	TTabRecord *pRecs;
	int TabSize;
	int CurrPos;

public:
	TArrayTable(int Size = TabMaxSize);
	virtual ~TArrayTable();
	virtual bool IsFull() const;

	int GetTabSize() const;
	virtual TKey GetKey(void) const;
	virtual TValue GetValue(void) const;
	virtual TKey GetKey(TDataPos mode) const; 
	virtual TValue GetValue(TDataPos mode) const; 

	virtual int Reset(void);       
	virtual int IsTabEnded(void) const; 
	virtual int GoNext(void);     
	virtual int SetCurrentPos(int pos); 
	int GetCurrentPos(void) const;

	friend class TSortTable;
};
