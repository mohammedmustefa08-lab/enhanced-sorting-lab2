#include "binary_insertion_sort.h"

// Binary search: find the index where 'key' should be inserted
// into the sorted prefix arr[0..end] (inclusive).
template <typename T>
static int binary_search_position(T arr[], int start, int end, T key) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)      return mid + 1;   // insert after equal
        else if (arr[mid] < key)  start = mid + 1;
        else                      end = mid - 1;
    }
    return start;
}

template <typename T>
void binary_insertion_sort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int pos = binary_search_position(arr, 0, i - 1, key);

        // Shift elements right to make room
        for (int j = i; j > pos; j--) {
            arr[j] = arr[j - 1];
        }
        arr[pos] = key;
    }
}

template void binary_insertion_sort<int>(int[], int);
template void binary_insertion_sort<double>(double[], int);