#include "ScanTable.h"
#include "SortTable.h"
#include "ArrayHash.h"
#include "ListHash.h"
#include "TreeTable.h"

#include<gtest.h>
using namespace std;

#define size 50
#define recSize 25

TEST(TScanTable, can_create_table)
{
    ASSERT_NO_THROW(TScanTable tb(35));
}

TEST(TScanTable, can_insert)
{
    TScanTable tb(35);
    ASSERT_NO_THROW(tb.InsRecord(2, "new"));
    EXPECT_EQ(tb.GetKey(), 2);
    EXPECT_EQ(tb.GetValue(), "new");
    EXPECT_EQ(tb.GetDataCount(), 1);
}

TEST(TScanTable, can_find)
{
    TScanTable tb(size);
    for (int i = 0; i < recSize; i++)
    {
         ASSERT_NO_THROW(tb.InsRecord(i, to_string(i)));
    }
    EXPECT_TRUE(tb.FindRecord(2));
    EXPECT_EQ(tb.GetKey(), 2);
    EXPECT_EQ(tb.GetValue(), to_string(2));
    EXPECT_EQ(tb.GetDataCount(), recSize);
    EXPECT_FALSE(tb.FindRecord(150));
}

TEST(TScanTable, can_delete)
{
    TScanTable tb(size);
    for (int i = 0; i < recSize; i++)
    {
         tb.InsRecord(i, to_string(i));
    }
    ASSERT_NO_THROW(tb.DelRecord(2));
    EXPECT_EQ(tb.GetDataCount(), recSize-1);
    EXPECT_FALSE(tb.FindRecord(2));
}

/*--------------------------------------------------------------*/

TEST(TSortTable, can_create_table)
{
    ASSERT_NO_THROW(TSortTable tb(35));
}

TEST(TSortTable, can_insert)
{
    TSortTable tb(size);
    for (int i = 0; i < recSize; i++)
    {
         ASSERT_NO_THROW(tb.InsRecord(recSize - 1 - i, to_string(recSize - 1 -i)));
    }
    tb.Reset();
    EXPECT_EQ(tb.GetKey(), 0);
    EXPECT_EQ(tb.GetDataCount(), recSize);
}

TEST(TSortTable, can_find)
{
    TSortTable tb(size);
    for (int i = 0; i < recSize; i++)
    {
         ASSERT_NO_THROW(tb.InsRecord(i, to_string(i)));
    }
    EXPECT_TRUE(tb.FindRecord(2));
    EXPECT_EQ(tb.GetKey(), 2);
    EXPECT_EQ(tb.GetValue(), to_string(2));
    EXPECT_EQ(tb.GetDataCount(), recSize);
    EXPECT_FALSE(tb.FindRecord(150));
}

TEST(TSortTable, is_sorted)
{
    TSortTable tb(size);
    for (int i = 0; i < size; i++)
    {
         tb.InsRecord(size - 1 - i, to_string(size - 1 -i));
    }
    int i = 0;
    for (tb.Reset(); tb.IsTabEnded(); tb.GoNext())
    {
         EXPECT_EQ(tb.GetKey(), i);
    }
}

TEST(TSortTable, can_delete)
{
    TSortTable tb(size);
    for (int i = 0; i < recSize; i++)
    {
         tb.InsRecord(i, to_string(i));
    }
    ASSERT_NO_THROW(tb.DelRecord(2));
    EXPECT_EQ(tb.GetDataCount(), recSize-1);
    EXPECT_FALSE(tb.FindRecord(2));
}

/*--------------------------------------------------------------*/

TEST(TArrayHashTable, can_create_table)
{
    ASSERT_NO_THROW(TArrayHashTable tb(35));
}

TEST(TArrayHashTable, can_insert)
{
    TArrayHashTable tb(35);
    ASSERT_NO_THROW(tb.InsRecord(2, "new"));
    EXPECT_EQ(tb.GetKey(), 2);
    EXPECT_EQ(tb.GetValue(), "new");
    EXPECT_EQ(tb.GetDataCount(), 1);
}

TEST(TArrayHashTable, can_find)
{
    TArrayHashTable tb(size);
    for (int i = 0; i < recSize; i++)
    {
         ASSERT_NO_THROW(tb.InsRecord(i, to_string(i)));
    }
    EXPECT_TRUE(tb.FindRecord(2));
    EXPECT_EQ(tb.GetKey(), 2);
    EXPECT_EQ(tb.GetValue(), to_string(2));
    EXPECT_EQ(tb.GetDataCount(), recSize);
    EXPECT_FALSE(tb.FindRecord(150));
}

TEST(TArrayHashTable, can_delete)
{
    TArrayHashTable tb(size);
    for (int i = 0; i < recSize; i++)
    {
         tb.InsRecord(i, to_string(i));
    }
    ASSERT_NO_THROW(tb.DelRecord(2));
    EXPECT_EQ(tb.GetDataCount(), recSize-1);
    EXPECT_FALSE(tb.FindRecord(2));
}

/*--------------------------------------------------------------*/

TEST(TListHAshTable, can_create_table)
{
    ASSERT_NO_THROW(TListHashTable tb(35));
}

TEST(TListHashTable, can_insert)
{
    TListHashTable tb(10);
    ASSERT_NO_THROW(tb.InsRecord(2, "new"));
    EXPECT_EQ(tb.GetKey(), 2);
    EXPECT_EQ(tb.GetValue(), "new");
    EXPECT_EQ(tb.GetDataCount(), 1);
}

TEST(TListHashTable, can_find)
{
    TListHashTable tb(10);
    for (int i = 0; i < recSize; i++)
    {
         ASSERT_NO_THROW(tb.InsRecord(i, to_string(i)));
    }
    EXPECT_TRUE(tb.FindRecord(2));
    EXPECT_EQ(tb.GetKey(), 2);
    EXPECT_EQ(tb.GetValue(), to_string(2));
    EXPECT_EQ(tb.GetDataCount(), recSize);
    EXPECT_FALSE(tb.FindRecord(150));
}

TEST(TListHashTable, can_delete)
{
    TListHashTable tb(10);
    for (int i = 0; i < recSize; i++)
    {
         tb.InsRecord(i, to_string(i));
    }
    ASSERT_NO_THROW(tb.DelRecord(2));
    EXPECT_EQ(tb.GetDataCount(), recSize-1);
    EXPECT_FALSE(tb.FindRecord(2));
}

/*--------------------------------------------------------------*/

TEST(TTreeTable, can_create_table)
{
    ASSERT_NO_THROW(TTreeTable tb);
}

TEST(TTreeTable, can_insert)
{
    TTreeTable tb;
    ASSERT_NO_THROW(tb.InsRecord(2, "new"));
    EXPECT_EQ(tb.GetKey(), 2);
    EXPECT_EQ(tb.GetValue(), "new");
    EXPECT_EQ(tb.GetDataCount(), 1);
    
    ASSERT_NO_THROW(tb.InsRecord(3, "new3"));
    EXPECT_EQ(tb.GetKey(), 3);
    EXPECT_EQ(tb.GetValue(), "new3");
    EXPECT_EQ(tb.GetDataCount(), 2);
    
    ASSERT_NO_THROW(tb.InsRecord(1, "new1"));
    EXPECT_EQ(tb.GetKey(), 1);
    EXPECT_EQ(tb.GetValue(), "new1");
    EXPECT_EQ(tb.GetDataCount(), 3);
}

TEST(TTreeTable, can_find)
{
    TTreeTable tb;
    for (int i = 0; i < recSize; i++)
    {
         ASSERT_NO_THROW(tb.InsRecord(i, to_string(i)));
    }
    EXPECT_TRUE(tb.FindRecord(2));
    EXPECT_EQ(tb.GetKey(), 2);
    EXPECT_EQ(tb.GetValue(), to_string(2));
    EXPECT_EQ(tb.GetDataCount(), recSize);
    EXPECT_FALSE(tb.FindRecord(150));
}

TEST(TTreeTable, can_delete)
{
    TTreeTable tb;
    for (int i = 0; i < recSize; i++)
    {
         tb.InsRecord(i, to_string(i));
    }
    ASSERT_NO_THROW(tb.DelRecord(2));
    EXPECT_EQ(tb.GetDataCount(), recSize-1);
    EXPECT_FALSE(tb.FindRecord(2));
}

/*--------------------------------------------------------------*/
