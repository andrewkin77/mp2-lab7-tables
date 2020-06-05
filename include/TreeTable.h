#ifndef TreeTable_h
#define TreeTable_h

#include <stack>
#include "Table.h"
#include "TreeNode.h"

class TTreeTable : public TTable
{
protected:
    TTreeNode  *pRoot;
    TTreeNode  *pCurrent;
    TTreeNode *pPrev;
    int CurrPos;
    stack<TTreeNode*> St;

    void PrintTreeTab(TTreeNode *pNode, int Level);
    void DeleteTreeTab(TTreeNode *pNode);
public:

    TTreeTable();
    ~TTreeTable();

    virtual bool IsFull() const;

    virtual bool FindRecord(TKey k);
    virtual int InsRecord(TKey k, TValue pVal);
    virtual int DelRecord(TKey k);

    virtual int Reset(void);
    virtual int IsTabEnded(void) const;
    virtual int GoNext(void);

    virtual TKey GetKey(void) const;
    virtual TValue GetValue(void) const;

    friend ostream& operator<<(ostream &os, TTreeTable &tab);
    void Print(void);
};

#endif
