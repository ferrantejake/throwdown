#include "sorts.h"
#include <stdio.h>
#include <stdlib.h>

void print_array_substr(int *, int, int);
// Sorts an array by reference
int *merge_sort_recursive(int *arr, int low, int high) {

    print_array_substr(arr, low, high);
    // If the difference between high and low locations
    // is less than two, then we are lookingt at adjacent
    // or identical locations, switch as necessary and
    // return. This is our base case.
    if (high - low < 2) {
        if (arr[high] < arr[low]) {
            int temp = arr[high];
            arr[high] = arr[low];
            arr[low] = temp;
        }
        return arr;
    }

    // We find our mid point which will always be the
    // exact middle (in the case of an oddly-sized array)
    // or the higher of two middle candidates (for evenly-
    // sized arrays).

    //      +---+---+---+---+---+---+
    //      | 0 | 1 | 2 | 3 | 4 | 6 |
    //      +---+---+---+---+---+---+
    //                    ^ midpoint
    //      (0 + 7) / 2 + ((7 + 0) % 2) = 4;

    //      +---+---+---+---+---+---+---+
    //      | 0 | 1 | 2 | 3 | 4 | 6 | 7 |
    //      +---+---+---+---+---+---+---+
    //                    ^ midpoint
    //      (0 + 8) / 2 + ((8 + 0) % 2) = 4;

    int mid = (high + low) / 2 + (high + low) % 2, i, j = low, k = mid;
    int *temp_arr = malloc(sizeof(int) * (high - low));

    // Now we call merge sort on the following sections
    // of the array
    merge_sort_recursive(arr, low, mid - 1);
    merge_sort_recursive(arr, mid, high);

    // merge
    for (i = 0; i < high - low + 1; i++) {
        if (k == high || (arr[j] < arr[k] && j <= mid - 1)) {
            printf("temp[%d] = arr[%d] {%d}\n", i, j, arr[j]);
            temp_arr[i] = arr[j++];
        } else {
            printf("temp[%d] = arr[%d] {%d}\n", i, k, arr[k]);
            temp_arr[i] = arr[k++];
        }
    }

    // copy values from temp_arr to arr
    for (i = 0; i + low < high; i++)
        arr[i + low] = temp_arr[i];

    return arr;

}

void print_array_substr(int *arr, int low, int high) {
    int i = low;
    printf("[");
    while (i <= high) {
        printf("%d", arr[i]);
        if (i++ != high)
            printf(", ");
    }
    printf("]\n");
}