#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

// Merge Sort
// - Runtime:
// Best Case:       O(nlogn)
// Average Case:    O(nlogn)
// Worst Case:      O(nlogn)
// - Space Complexity
// Best Case:       O(nlogn)
// Average Case:    O(nlogn)
// Worst Case:      O(n)
int *merge_sort(int *arr, int low, int high) {

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
    merge_sort(arr, low, mid - 1);
    merge_sort(arr, mid, high);

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

// Bubble Sort
// Sorts an array by reference
// - Runtime
// Best Case:       O(n^2)
// Average Case:    O(n^2)
// Worst Case:      O(n^2)
int *bubble_sort(int *arr, int length) {

    // In the case that our array is empty or size 1, then we can
    // simply return the array without making any changes.
    if (length < 2)
        return arr;

    int i, j;

    // Starting at the end of the array, we set a limit to how far
    // we are allowed to look out. This is because once we've bubbled
    // an element to the top, there is no need to compare it again, it
    // is the correct position.
    for (i = length - 1; i > 0; i--) {

        // We iterate through each element and compare it to the next.
        for (j = 0; j < i; j++) {
            // If we find that the current element's value is greater
            // than the next element's we switch the elements
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort
// Sorts an array by reference
// - Runtime:
// Best Case:       O(n)   when everything is already sorted
// Average Case:    O(n^2) average disarray
// Worst Case:      O(n^2) when the array is in descending order
// - Space Complexity:
// Best/Average/Worst Case: O(n) for any array where n > 0
int *insertion_sort(int *arr, int size) {

    // Return array if the array is null
    if (arr == NULL)
        return arr;

    int i, j, temp;

    // Iterate through all evlements in the array
    for (i = 0; i < size; i++) {

        // Get the current element and store is aside
        temp = arr[i];

        // Check all elements below the current index to see if they
        // are greater than the temp index. If the element to the immediate
        // left of the current index is less than the temp value, then copy
        // the value to the current index. Otherwise set the current index
        // to the current index in the array, as we've found the appropriate
        // location for the temp value
        for (j = i; j > 0; j++) {
            if (arr[i - 1] > temp)
                arr[i] = arr[i - 1];
            else {
                arr[i] = temp;
                break;
            }
        }
    }

    return arr;
}

// Selection Sort
// Sorts an array by reference
// - Runtime:
// Best/Average/Worst Case: O(n^2) for any array wher n > 0
// This is because we are still cpomparing the values of all
// of the elements at locations greater than the current index
// to the value of at the current index, thus we still compare
// all values on average to 1/2n other elements. Thus our runtime
// is O(n^2)
// - Space Complexity:
// Best/Average/Worst Case: O(n) for any array where n > 0
int *selection_sort(int *arr, int size) {

    // Return array if the array is null
    if (arr == NULL)
        return arr;

    int i, j, min, temp;

    for (i = 0; i < size; i++) {

        // Select the current element's index as the smallest
        // seen for this iteration (will swap with itself if
        // we can't find anything smaller).
        min = i;

        // Check all of the elements to the right of the
        // current index for a smaller value.
        for (j = i + 1; j < size; j++)
            if (arr[j] < min)
                min = j;

        // Switch the value at the current index with the value
        // where we found a smaller value.
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = arr[i];
    }
}