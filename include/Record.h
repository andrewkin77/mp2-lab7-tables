#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef int TKey;
typedef string TValue;

class TTabRecord
{
protected:
	TKey Key;    
	TValue Value; 

public:
	TTabRecord(TKey k = 0, TValue _Value = "");
    virtual ~TTabRecord() {};
	void SetKey(TKey k);
	TKey GetKey(void);
	void SetValue(TValue v);
	TValue GetValue(void);
	virtual int operator==(const TTabRecord &tr) { return Key == tr.Key; }
    virtual int operator!=(const TTabRecord &tr) { return Key != tr.Key; }
	virtual int operator< (const TTabRecord &tr) { return Key < tr.Key; }
	virtual int operator<= (const TTabRecord &tr) { return Key <= tr.Key; }
	virtual int operator> (const TTabRecord &tr) { return Key > tr.Key; }
	virtual int operator>= (const TTabRecord &tr) { return Key >= tr.Key; }

	friend ostream& operator<<(ostream& os, const TTabRecord& tr)
	{
		return os << tr.Key << " " << tr.Value << endl;
	}

	friend class TArrayTable;
	friend class TScanTable;
	friend class TSortTable;
	friend class TTreeNode;
	friend class TTreeTable;

};
