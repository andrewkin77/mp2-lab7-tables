#include "TreeTable.h"

TTreeTable::TTreeTable() : TTable()
{
    CurrPos = 0; pRoot = pCurrent = nullptr;
}

TTreeTable::~TTreeTable()
{
    DeleteTreeTab(pRoot);
}

bool TTreeTable::IsFull() const
{
    TTreeNode* pNode = new TTreeNode();
    int temp = pNode == nullptr;
    delete pNode;
    return temp;
}

bool TTreeTable::FindRecord(TKey k)
{
    pPrev = nullptr;
    pCurrent = pRoot;
    while (pCurrent)
    {
        Efficiency++;
        if (pCurrent->Key == k)
        {
            break;
        }
        pPrev = pCurrent;
        if (pCurrent->Key < k)
        {
            pCurrent = pCurrent->pRight;
        }
        else
        {
            pCurrent = pCurrent->pLeft;
        }
    }
    if (pCurrent)
    {
        return true;
    }
    else
    {
        pCurrent = pPrev;
        return false;
    }
}

int TTreeTable::InsRecord(TKey k, TValue pVal) {
    if (IsFull())
    {
        return TabFull;
    }
    else if (FindRecord(k))
    {
        return TabRecDbl;
    }
    else
    {
        TTreeNode *tmp = new TTreeNode(k, pVal);
        if (!pRoot)
        {
            pRoot = tmp;
            pCurrent = pRoot;
        }
        else
        {
            if (k < pCurrent->Key)
            {
                pCurrent->pLeft = tmp;
                pCurrent = tmp;
            }
            else
            {
                pCurrent->pRight = tmp;
                pCurrent = tmp;
            }
        }
        Efficiency++;
        DataCount++;
        return TabOK;
    }
}

int TTreeTable::DelRecord(TKey k)
{
    if (!FindRecord(k))
    {
        return TabNoRec;
    }
    else
    {
        TTreeNode* pNode = pCurrent;
        if (!pNode->pRight)
        {
            if (!pPrev)
            {
                pRoot = pNode->pLeft;
            }
            else
            {
                if (pPrev->pRight == pNode)
                {
                    pPrev->pRight = pNode->pLeft;
                }
                else
                {
                    pPrev->pLeft = pNode->pLeft;
                }
            }
            Efficiency++;
        }
        else if (!pNode->pLeft)
        {
            if (!pPrev)
            {
                pRoot = pNode->pRight;
            }
            else
            {
                if (pPrev->pRight == pNode)
                {
                    pPrev->pRight = pNode->pRight;
                }
                else
                {
                    pPrev->pLeft = pNode->pRight;
                }
            }
            Efficiency++;
        }
        else
        {
            TTreeNode *pN = pNode->pLeft;
            pPrev = pNode;
            while (pN->pRight)
            {
                pPrev = pN;
                pN = pN->pRight;
                Efficiency++;
            }
            pNode->Value = pN->Value;
            pNode->Key = pN->Key;
            if (pPrev->pRight == pN)
            {
                pPrev->pRight = pN->pLeft;
            }
            else
            {
                pPrev->pLeft = pN->pLeft;
            }
            pNode = pN;
            Efficiency++;
        }
        delete pNode;
        DataCount--;
        return TabOK;
    }
}

TKey TTreeTable::GetKey(void) const
{
    if(pCurrent)
        return pCurrent->Key;
    throw -1;
}

TValue TTreeTable::GetValue(void) const
{
    if(pCurrent)
        return pCurrent->Value;
    throw "pCurrent is Null";
}

int TTreeTable::Reset(void)
{
    TTreeNode* pNode = pCurrent = pRoot;
    while (!St.empty())
        St.pop();
    CurrPos = 0;
    while (pNode)
    {
        St.push(pNode);
        pCurrent = pNode;
        pNode = pNode->pLeft;
    }
    return IsTabEnded();
}

int TTreeTable::IsTabEnded(void) const
{
    return CurrPos >= DataCount;
}

int TTreeTable::GoNext(void)
{
    if (!IsTabEnded() && (pCurrent != nullptr))
    {
        TTreeNode* pNode = pCurrent = pCurrent->pRight;
        St.pop();
        while (pNode)
        {
            St.push(pNode);
            pCurrent = pNode;
            pNode = pNode->pLeft;
        }
        if ((pCurrent == nullptr) && !St.empty())
        {
            pCurrent = St.top();
        }
        CurrPos++;
    }
    return IsTabEnded();
}


ostream& operator<<(ostream &os, TTreeTable &tab)
{
    cout << "Table printing" << endl;
    tab.Print();
    return os;
}

void TTreeTable::Print(void)
{
    cout << "Table printing" << endl;
    PrintTreeTab(pRoot, 0);
}

void TTreeTable::PrintTreeTab(TTreeNode* pNode, int Level)
{
    if (pNode)
    {
        PrintTreeTab(pNode->pRight, Level + 1);
        for (int i = 0; i < 2 * Level; i++)
        {
            cout << "  ";
        }
        cout<< *pNode << endl;
        PrintTreeTab(pNode->pLeft, Level + 1);
    }
}

void TTreeTable::DeleteTreeTab(TTreeNode* pNode)
{
    if (pNode)
    {
        DeleteTreeTab(pNode->pLeft);
        DeleteTreeTab(pNode->pRight);
        delete pNode;
    }
}
