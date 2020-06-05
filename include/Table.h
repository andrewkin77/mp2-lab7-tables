#pragma once
#include <iostream>
#include "Record.h"

#define TabOK        0
#define TabEmpty  -101
#define TabFull   -102
#define TabNoRec  -103
#define TabRecDbl -104
#define TabNoMem  -105 
#define TabMaxSize 25

using namespace std;

class TTable
{

protected:
	int DataCount;
	int Efficiency;

public:
	TTable();
	virtual ~TTable() { };

	int GetDataCount() const;
	int GetEfficiency() const;
	void ClearEfficiency();
	int IsEmpty() const;
	virtual bool IsFull() const = 0;

	virtual bool FindRecord(TKey k) = 0;        
	virtual int InsRecord(TKey k, TValue Val) = 0;
	virtual int DelRecord(TKey k) = 0;        

	virtual int Reset(void) = 0; 
	virtual int IsTabEnded(void) const = 0; 
	virtual int GoNext(void) = 0; 

	virtual TKey GetKey(void) const = 0;
	virtual TValue GetValue(void) const = 0;

	friend ostream& operator<<(ostream &os, TTable &tab)
	{
		os << "Table printing" << endl;
        for (tab.Reset(); !tab.IsTabEnded(); tab.GoNext())
        {
            os << " Key: " << tab.GetKey() << " Val: " << tab.GetValue() << endl;
        }
        return os;
	}
};
