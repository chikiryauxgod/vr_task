#include <gtest/gtest.h>
#include "sorts.h"
#include <vector>
#include <thread>

// Test merge_sort
TEST(SortTest, MergeSort) 
{
    vector v = {5, 2, 9, 1, 5, 6};
    merge_sort(v, 0, v.size() - 1, 0);
    vector expected = {1, 2, 5, 5, 6, 9};
    EXPECT_EQ(v, expected);
}

// Test fast_sort
TEST(SortTest, FastSort)
 {
    vector v = {5, 2, 9, 1, 5, 6};
    vector sorted = fast_sort(v);
    vector expected = {1, 2, 5, 5, 6, 9};
    EXPECT_EQ(sorted, expected);
}

// Test bubble_sort
TEST(SortTest, BubbleSort) 
{
    vector v = {5, 2, 9, 1, 5, 6};
    vector sorted = bubble_sort(v);
    vector expected = {1, 2, 5, 5, 6, 9};
    EXPECT_EQ(sorted, expected);
}

// Test empty vector for merge_sort
TEST(SortTest, EmptyMergeSort) 
{
    vector v = {};
    merge_sort(v, 0, v.size() - 1, 0);
    vector expected = {};
    EXPECT_EQ(v, expected);
}

// Test single element vector for merge_sort
TEST(SortTest, SingleElementMergeSort) 
{
    vector v = {42};
    merge_sort(v, 0, v.size() - 1, 0);
    vector expected = {42};
    EXPECT_EQ(v, expected);
}

// Test empty vector for fast_sort
TEST(SortTest, EmptyFastSort) 
{
    vector v = {};
    vector sorted = fast_sort(v);
    vector expected = {};
    EXPECT_EQ(sorted, expected);
}

// Test single element vector for fast_sort
TEST(SortTest, SingleElementFastSort) 
{
    vector v = {42};
    vector sorted = fast_sort(v);
    vector expected = {42};
    EXPECT_EQ(sorted, expected);
}

// Test empty vector for bubble_sort
TEST(SortTest, EmptyBubbleSort) 
{
    vector v = {};
    vector sorted = bubble_sort(v);
    vector expected = {};
    EXPECT_EQ(sorted, expected);
}

// Test single element vector for bubble_sort
TEST(SortTest, SingleElementBubbleSort) 
{
    vector v = {42};
    vector sorted = bubble_sort(v);
    vector expected = {42};
    EXPECT_EQ(sorted, expected);
}

// Test parallel sort 
TEST(SortTest, ParallelSort) 
{
    vector v = {5, 2, 9, 1, 5, 6};
    vector expected = {1, 2, 5, 5, 6, 9};
    
    vector bub_v(0), fast_v(0);

    vector merge_v = v;

    std::thread t1([&](){bub_v = bubble_sort(v);});
    std::thread t2([&](){fast_v = fast_sort(v);});
    std::thread t3([&](){merge_sort(merge_v, 0, v.size() - 1, 0);});

    t1.join();
    t2.join();
    t3.join();
    
    EXPECT_EQ(bub_v, expected);
    EXPECT_EQ(fast_v, expected);
    EXPECT_EQ(merge_v, expected);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

