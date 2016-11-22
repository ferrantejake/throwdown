#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main();
void printData(int *, int);
// int binary_search_recursive(int *, int, int);
// int binary_search_iterative(int *, int, int);

int main() {

    int data[20] = {0, 4, 8, 9, 14, 21, 24, 36, 37, 38, 39, 42, 48, 58, 61, 63, 67, 78, 99, 120};
    int data_length = sizeof(data) / sizeof(int);
    int key = 4;
    printf("%lu %lu %lu\n", sizeof(data) / sizeof(int), sizeof(*data), sizeof(&data));
    printData(data, data_length);

    printf("Binary Search: \n");
    int bin_search_recusive_result = binary_search_recursive(data, 0, data_length - 1, key);
    printf("[recusrive]: looking for [%d]: %d %s\n", key, bin_search_recusive_result,
           bin_search_recusive_result == 1 ? "exists" : "DNE");

    return 0;
}

void printData(int *data, int size) {
    int x;
    printf("============== DATA ==============\n");
    for (x = 0; x < size - 1; x++)
        printf("%d%c", data[x], ((x + 1) % 15 == 0) ? '\n' : ' ');
    printf("\n==================================\n");
}

int binary_search_recursive(int *array, int low, int high, int key) {
    // if the high is the low, since this is an order array, then
    // we know that this array is either of size 1 or contains
    // elements which are all the same. If that is the case, then
    //  the key is either the high/low key or it is not in the array
    printf("array[%d]: %d\tarray[%d]: %d \n", low, array[low], high, array[high]);
    int mid = (low + high) / 2 + (low + high) % 2;

    if ((high - mid) == low) {
        printf("low == high | %d == %d\n", low, high);
        printf("key: %d \tarray[high]: %d\n", key, array[high]);
        if (key == array[high])
            return 1;
        return 0;
    }
    sleep(1);

    // if the key is less than the mid, then it is in the lower half of the array
    // we replace the high key with the mid
    if (key < array[mid]) {
        printf("%d < %d @%d \n", key, array[mid], mid);
        return binary_search_recursive(array, low, mid, key);
    }
    // if the key is greater than the mid, then if it exists, then it exists in
    // the upper half of the grap. We replace the low with the mid
    if (key > array[mid]) {
        printf("%d > %d @%d\n", key, array[mid], mid);
        return binary_search_recursive(array, mid, high, key);
    }
    // if the key is the mid, then we have found the key
    if (key == array[mid]) {
        printf("%d == %d @%d\n", key, array[mid], mid);
        return 1;
    }

    return 0;
}
int binary_search_iterative(int *array, int low, int high, int key) { return 0; }