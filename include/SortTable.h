#pragma once
#include "ScanTable.h"

enum TSortMethod {INSERT_SORT, MERGE_SORT};

class TSortTable : public TScanTable
{
private:
	TTabRecord *pBuff;
	TSortMethod SortMethod;
	void SortData(void);
	void InsertSort();
	void MergeSort();
	void MergeSorter(int start, int finish);
	void MergeData(int start, int mid, int finish);

public:
	TSortTable(int Size = TabMaxSize, TSortMethod mode = MERGE_SORT) : TScanTable(Size)
	{
        SortMethod = mode;
		pBuff = new TTabRecord[DataCount];
	}
	TSortTable(const TScanTable &tab);
	~TSortTable()
	{
		delete[] pBuff;
	}
	TSortMethod GetSortMethod();
	void SetSortMethod(TSortMethod mode);
	TSortTable& operator=(const TScanTable &tab);

	virtual bool FindRecord(TKey k);                
	virtual int InsRecord(TKey k, TValue Val); 
	virtual int DelRecord(TKey k);                  
};
