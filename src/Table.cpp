#include "Table.h"

TTable::TTable()
{
	DataCount = 0;
	Efficiency = 0;
}

int TTable::GetDataCount() const
{
	return DataCount;
}

int TTable::GetEfficiency() const {
	return   Efficiency;
} 

void TTable::ClearEfficiency()
{
	Efficiency = 0;
} 

int TTable::IsEmpty() const 
{
	return DataCount == 0;
} 