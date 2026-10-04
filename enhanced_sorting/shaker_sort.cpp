#include "shaker_sort.h"

template <typename T>
void shaker_sort(T arr[], int n) {
    int left = 0;
    int right = n - 1;
    bool swapped = true;

    while (swapped) {
        swapped = false;

        // Left -> Right pass: bubble the largest to the right
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                T tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = true;
            }
        }
        right--;

        if (!swapped) break;

        swapped = false;

        // Right -> Left pass: bubble the smallest to the left
        for (int i = right; i > left; i--) {
            if (arr[i - 1] > arr[i]) {
                T tmp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = tmp;
                swapped = true;
            }
        }
        left++;
    }
}

template void shaker_sort<int>(int[], int);
template void shaker_sort<double>(double[], int);