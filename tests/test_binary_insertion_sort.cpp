#include <gtest/gtest.h>
#include "binary_insertion_sort.h"

TEST(BinaryInsertionSort, AlreadySorted) {
    int a[] = { 1, 2, 3, 4, 5 };
    binary_insertion_sort(a, 5);
    for (int i = 0; i < 5; i++) EXPECT_EQ(a[i], i + 1);
}

TEST(BinaryInsertionSort, ReverseSorted) {
    int a[] = { 5, 4, 3, 2, 1 };
    binary_insertion_sort(a, 5);
    for (int i = 0; i < 5; i++) EXPECT_EQ(a[i], i + 1);
}

TEST(BinaryInsertionSort, EmptyArray) {
    int a[1] = { 0 };
    binary_insertion_sort(a, 0);
    SUCCEED();
}

TEST(BinaryInsertionSort, SingleElement) {
    int a[] = { 42 };
    binary_insertion_sort(a, 1);
    EXPECT_EQ(a[0], 42);
}

TEST(BinaryInsertionSort, Duplicates) {
    int a[] = { 3, 1, 3, 2, 1, 3 };
    binary_insertion_sort(a, 6);
    int expected[] = { 1, 1, 2, 3, 3, 3 };
    for (int i = 0; i < 6; i++) EXPECT_EQ(a[i], expected[i]);
}

TEST(BinaryInsertionSort, Variant9) {
    int a[] = { 7, 17, 9, 3, 13, 1, 16, 10 };
    binary_insertion_sort(a, 8);
    int expected[] = { 1, 3, 7, 9, 10, 13, 16, 17 };
    for (int i = 0; i < 8; i++) EXPECT_EQ(a[i], expected[i]);
}