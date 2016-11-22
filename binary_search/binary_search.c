#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main();
void printData(int *, int);
#define ARRAY_SIZE 19

int main() {
    int data[ARRAY_SIZE] = {0, 4, 8, 9, 14, 21, 24, 36, 37, 38, 39, 42, 48, 58, 61, 63, 67, 78, 99};
    int data_length = sizeof(data) / sizeof(int);
    int key;

    while (1) {
        printData(data, data_length);

        printf("Enter an int to look for: ");
        scanf("%d", &key);
        int bin_search_recusive_result = binary_search_recursive(data, 0, data_length - 1, key);
        int bin_search_iterative_result = binary_search_iterative(data, 0, data_length - 1, key);
        printf("[recusrive]: %s\n", bin_search_recusive_result == 1 ? "found" : "not found");
        printf("[iterative]: %s\n", bin_search_iterative_result == 1 ? "found" : "not found");
    }
    return 0;
}

void printData(int *data, int size) {
    int x;
    printf("\n============== DATA ==============\n");
    for (x = 0; x < size - 1; x++)
        printf("%d%c", data[x], ((x + 1) % 15 == 0) ? '\n' : ' ');
    printf("\n==================================\n");
}

int binary_search_recursive(int *array, int low, int high, int key) {
    // If the data is out of bounds of the highest and lowest
    // data points, then return 0
    if (key > array[high] || key < array[low])
        return 0;
    // Otherwise we may have that data, perform a search on it.
    return _binary_search_recursive(array, low, high, key);
}
int _binary_search_recursive(int *array, int low, int high, int key) {
    int mid = (low + high) / 2 + (low + high) % 2;

    // if the mid point equiv to the index of the top of the array
    // or to the bottom, then we have
    if (mid == high || mid == low)
        return (key == array[low] || key == array[high]) ? 1 : 0;

    // if the key is less than the mid, then it is in the lower half of the array
    // we replace the high key with the mid
    if (key < array[mid])
        return binary_search_recursive(array, low, mid, key);

    // if the key is greater than the mid, then if it exists, then it exists in
    // the upper half of the grap. We replace the low with the mid
    if (key > array[mid])
        return binary_search_recursive(array, mid, high, key);

    // if we make it here, then the key is not greater than array[mid] nor is it
    // less thank array[mid], and we have yet to come to the end of our search,
    // meaning that we have found what we are looking for.
    return 1;
}
int binary_search_iterative(int *array, int low, int high, int key) {
    // If the data is out of bounds of the highest and lowest
    // data points, then return 0
    if (key > array[high] || key < array[low])
        return 0;
    // Otherwise we may have that data, perform a search on it.
    return _binary_search_iterative(array, low, high, key);
}
int _binary_search_iterative(int *array, int low, int high, int key) {

    // initalize the mid point
    int mid = (low + high) / 2 + (low + high) % 2, i;

    // While we have not come to the end of our search
    while (mid != low && mid != high) {

        // Keep looking if key < mid
        if (key < array[mid])
            high = mid;

        // Keep looking if key > mid
        else if (key > array[mid])
            low = mid;

        // Otherwise we have found our key at mid
        else
            return 1;

        // Recalculate mid
        mid = (low + high) / 2 + (low + high) % 2, i;
    }

    // If we make it here, then we have come to the end
    // of and we evaluate the values at both the low and
    // high index to see if we have found our key. Return
    // 1 if we found our key, else return 0
    return (key == array[low] || key == array[high]) ? 1 : 0;
}