#include "sorts.h"
#include <stdio.h>
#include <stdlib.h>

// Sorts an array by reference
int *merge_sort_recursive(int *arr, int low, int high) {

    // print_array_substr(arr, low, high);
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

    //      +---+---+---+---+---+---+---+
    //      | 0 | 1 | 2 | 3 | 4 | 6 | 7 |
    //      +---+---+---+---+---+---+---+
    //                    ^ midpoint

    int mid = (high + low) / 2 + (high + low) % 2, i, j = low, k = mid;
    int *temp_arr = malloc(sizeof(int) * (high - low));

    // Now we call merge sort on the following sections
    // of the array
    merge_sort_recursive(arr, low, mid - 1);
    merge_sort_recursive(arr, mid, high);

    // Increment through arrays and select the value which is
    // the lowest of the two options at each location in the
    // of the array sections. Copy these values in order (as
    // they were already sorted beforehand) into a new temporary
    // array which will contain these sections merged, in order.
    for (i = 0; i < high - low + 1; i++) {

        // If the index of the second section is too high, just
        // fill the temp array with the remaining values from
        // the lower section. Or, if the lower count does not
        // exceed the section boundary and the value in the lower
        // section is less than the value in the upper section,
        // then place it in the temp array.
        if (k > high || (j <= (mid - 1) && arr[j] < arr[k]))
            temp_arr[i] = arr[j++];
        // In all other cases add the next upper section value
        // to the temp array.
        else
            temp_arr[i] = arr[k++];
    }

    // Copy values from temp array to arr
    for (i = 0; i + low <= high; i++)
        arr[i + low] = temp_arr[i];

    // Free temp array memory
    return arr;
}