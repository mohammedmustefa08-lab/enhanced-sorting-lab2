#include <gtest/gtest.h>
#include "shaker_sort.h"

TEST(ShakerSort, AlreadySorted) {
    int a[] = { 1, 2, 3, 4, 5 };
    shaker_sort(a, 5);
    for (int i = 0; i < 5; i++) EXPECT_EQ(a[i], i + 1);
}

TEST(ShakerSort, ReverseSorted) {
    int a[] = { 5, 4, 3, 2, 1 };
    shaker_sort(a, 5);
    for (int i = 0; i < 5; i++) EXPECT_EQ(a[i], i + 1);
}

TEST(ShakerSort, EmptyArray) {
    int a[1] = { 0 };
    shaker_sort(a, 0);
    SUCCEED();
}

TEST(ShakerSort, SingleElement) {
    int a[] = { 42 };
    shaker_sort(a, 1);
    EXPECT_EQ(a[0], 42);
}

TEST(ShakerSort, Duplicates) {
    int a[] = { 3, 1, 3, 2, 1, 3 };
    shaker_sort(a, 6);
    int expected[] = { 1, 1, 2, 3, 3, 3 };
    for (int i = 0; i < 6; i++) EXPECT_EQ(a[i], expected[i]);
}

TEST(ShakerSort, Variant9) {
    int a[] = { 7, 17, 9, 3, 13, 1, 16, 10 };
    shaker_sort(a, 8);
    int expected[] = { 1, 3, 7, 9, 10, 13, 16, 17 };
    for (int i = 0; i < 8; i++) EXPECT_EQ(a[i], expected[i]);
}