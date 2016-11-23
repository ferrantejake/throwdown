#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_data(int *, int);
void generate_data(int *, int);
void generateInorderData(int *, int);
void merge_sort(int *, int, int);

int main() {

    // Generate data off of a time seed
    int seed = time(NULL), data_length = seed % 100, data[data_length], key;

    generate_data(data, data_length);
    print_data(data, data_length);
    merge_sort(data, 0, data_length - 1);
    print_data(data, data_length);
    // print data

    while (1) {

        printf("Enter an int to look for: ");
        scanf("%d", &key);
        int bin_search_recusive_result = binary_search_recursive(data, 0, data_length - 1, key);
        int bin_search_iterative_result = binary_search_iterative(data, 0, data_length - 1, key);
        printf("[recusrive]: %s\n", bin_search_recusive_result == 1 ? "found" : "not found");
        printf("[iterative]: %s\n", bin_search_iterative_result == 1 ? "found" : "not found");
    }
    return 0;
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

void print_data(int *data, int size) {
    int x;
    printf("\n================== DATA ==================\n");
    for (x = 0; x < size; x++)
        printf("%d%c", data[x], ((x + 1) % 15 == 0) ? '\n' : ' ');
    printf("\n==========================================\n");
}

void generate_data(int *data, int length) {
    int count = 0;
    while (count < length) {
        srand(time(NULL) + rand());
        data[count++] = rand() % 100;
        ;
    }
}

void merge_sort(int *array, int low, int high) {
    printf("[%d]=%d \t[%d]=%d\n", low, array[low], high, array[high]);
    sleep(1);
    if (high - low < 2 && array[high] < array[low]) {
        int temp = array[high];
        array[high] = array[low];
        array[low] = array[high];
        return;
    }
    if (high < low) {
        int mid = (high + low) / 2 + (high + low) % 2;
        merge_sort(array, low, mid);
        merge_sort(array, mid + 1, high);

        // then
        int this = low, that = mid + 1;
        while ()
        if (array[this] > array[that])
            int temp = array[that];
            array[this] = array[that];
            array[this] = array[that];
            this++;
    }
}
