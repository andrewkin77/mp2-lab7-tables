#include "ScanTable.h"
#include "SortTable.h"
#include "ArrayHash.h"
#include "ListHash.h"
#include "TreeTable.h"
#include <random>

enum TabType { SCAN, SORT, AR_HASH, LIST_HASH, TREE };
TTable *tb = nullptr;
void RandomTableGenerator(TabType type)
{
    delete tb;
    int MaxKey, RecNum, MaxSize, ListsNum, key;
    switch (type)
    {
        case SCAN:
            cout << "Enter max size, number of records and maximum key value: ";
            cin >> MaxSize >> RecNum >> MaxKey;
            cout << endl;
            tb = new TScanTable(MaxSize);
            break;
            
        case SORT:
            cout << "Enter max size, number of records and maximum key value: ";
            cin >> MaxSize >> RecNum >> MaxKey;
            cout << endl;
            tb = new TSortTable(MaxSize);
            break;
            
        case AR_HASH:
            cout << "Enter max size, number of records and maximum key value: ";
            cin >> MaxSize >> RecNum >> MaxKey;
            cout << endl;
            tb = new TArrayHashTable(MaxSize);
            break;
            
        case LIST_HASH:
            cout << "Enter number of lists, number of records and maximum key value: ";
            cin >> ListsNum >> RecNum >> MaxKey;
            cout << endl;
            tb = new TListHashTable(ListsNum);
            break;
        case TREE:
            cout << "Enter number of records and maximum key value: ";
            cin >> RecNum >> MaxKey;
            cout << endl;
            tb = new TTreeTable();
            break;
            
            
    }
    
    for (int i = 0; i < RecNum; i++)
    {
        key = rand() % MaxKey;
        tb->InsRecord(key, "d"+to_string(i));
    }
    cout << "Table generated. Efficiency: " << tb->GetEfficiency() << endl;
}

void MainLoop()
{
    TabType type;
    bool run = true;
    int key, RetCode;
    string cmd, value;
    bool table_generated = false;
    while(run)
    {
        cout << "What do you want to do? Type help to see commands" << endl;
        getline(cin >> ws, cmd);
        if (cmd == "generate")
        {
            cout << "What table type to generate?" << endl;
            getline(cin >> ws, cmd);
            cout << endl;
            if (cmd == "scan")
                type = SCAN;
            else if (cmd == "sort")
                type = SORT;
            else if (cmd == "array hash")
               type = AR_HASH;
            else if(cmd == "list hash")
                type = LIST_HASH;
            else if(cmd == "tree")
                type = TREE;
            
            RandomTableGenerator(type);
            table_generated = true;
        }
        
        if (cmd == "find")
        {
            if (!table_generated)
            {
                cout << "There is no table" << endl;
            }
            else
            {
                tb->ClearEfficiency();
                cout << "Enter key" << endl;
                cin >> key;
                RetCode = tb->FindRecord(key);
                if(RetCode)
                {
                    cout << "Record found!\nEfficiency: " << tb->GetEfficiency() << endl;
                }
                else if (!RetCode)
                {
                    cout << "Record not found!\nEfficiency: " << tb->GetEfficiency() << endl;
                }
            }
        }
        
        if (cmd == "insert")
        {
            if (!table_generated)
            {
                cout << "There is no table" << endl;
            }
            else
            {
                tb->ClearEfficiency();
                cout << "Enter key and value:" << endl;
                cin >> key >> value;
                RetCode = tb->InsRecord(key, value);
                if(RetCode == TabOK)
                {
                    cout << "Instruction complete!\nEfficiency: " << tb->GetEfficiency() << endl;
                }
                else if (RetCode == TabRecDbl)
                {
                    cout << "Record with this key already exists!" << endl;
                }
                else if (RetCode == TabNoRec)
                {
                    cout << "Record not found!\nEfficiency: " << tb->GetEfficiency() << endl;
                }
            }
        }
        
        if (cmd == "delete")
        {
            if (!table_generated)
            {
                cout << "There is no table" << endl;
            }
            else
            {
                tb->ClearEfficiency();
                cout << "Enter key" << endl;
                cin >> key;
                RetCode = tb->DelRecord(key);
                if(RetCode == TabOK)
                {
                    cout << "Instruction complete!\nEfficiency: " << tb->GetEfficiency() << endl;
                }
                else if (RetCode == TabEmpty)
                {
                    cout << "Table is empty!" << endl;
                }
                else if (RetCode == TabNoRec)
                {
                    
                    cout << "Record not found!\nEfficiency: " << tb->GetEfficiency() << endl;
                }
            }
        }
        
        if (cmd == "print")
        {
            if (!table_generated)
            {
                cout << "There is no table" << endl;
            }
            else if(type != TREE)
            {
                cout << *tb << endl;
            }
            else
            {
                ((TTreeTable*)tb)->Print();
            }
        }
        
        if (cmd == "number of records")
        {
            if (!table_generated)
            {
                cout << "There is no table" << endl;
            }
            else
            {
                RetCode = tb->GetDataCount();
                if(RetCode)
                {
                    cout << "Number of records: " << RetCode << endl;
                }
                else
                {
                    cout << "Table is Empty!" << endl;
                }
            }
        }
        
        if (cmd == "exit")
        {
            run = false;
        }
    }
            
}

int main()
{
    MainLoop();
}
