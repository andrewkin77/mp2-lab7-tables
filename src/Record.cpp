#include "Record.h"

TTabRecord::TTabRecord(TKey k, TValue _Value)
{
	Key = k; Value = _Value;
}

void TTabRecord::SetKey(TKey k)
{
	Key = k;
}

TKey TTabRecord::GetKey()
{
	return Key;
}

void TTabRecord::SetValue(TValue v)
{
	Value = v;
}

TValue TTabRecord::GetValue()
{
	return Value;
}

