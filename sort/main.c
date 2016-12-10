#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int, char **);
void print_array(int *, int);
int read_from_file(char *filename, int *);
void copy_array(int *, int *, int);

int main(int argc, char **argv) {

    // Generate array from input file
    int *arr = malloc(sizeof(int) * 100);
    char *filename;
    if (argc < 2) {
        filename = malloc(sizeof(char) * strlen("input.txt") + 1);
        strcpy(filename, "input.txt");
    } else {
        filename = malloc(sizeof(char) * strlen(argv[1] + 1));
        strcpy(filename, argv[1]);
    }
    int length = read_from_file(filename, arr);

    // Create new arrays for each sort
    int *bubble_arr = malloc(sizeof(int) * length);
    int *merge_arr = malloc(sizeof(int) * length);

    // Copy array values
    copy_array(arr, merge_arr, length);
    copy_array(arr, bubble_arr, length);

    // Show original array
    printf("original:\t");
    print_array(arr, length);

    // Sort arrays
    merge_sort(merge_arr, 0, length - 1);
    bubble_sort(bubble_arr, length);

    // Show sorted arrays
    printf("merge sort: \t");
    print_array(merge_arr, length);
    printf("bubble sort: \t");
    print_array(bubble_arr, length);

    // Free pointers
    free(arr);
    free(merge_arr);
    free(bubble_arr);
    return 0;
}

// Reads all integers from a file and returns
// the size of the array
int read_from_file(char *filename, int *arr) {
    int length = 0, i;

    FILE *in;
    in = fopen(filename, "r");
    fscanf(in, "%d", &length);

    int temp;
    for (i = 0; i < length && !feof(in); i++)
        fscanf(in, "%d", &arr[i]);

    return length;
}

void print_array(int *arr, int length) {
    int i = 0;
    printf("[");
    while (i < length) {
        printf("%d", arr[i]);
        if (i++ != length - 1)
            printf(", ");
    }
    printf("]\n");
}

void copy_array(int *original, int *new, int length) {
    int i;
    for (i = 0; i < length; i++)
        new[i] = original[i];
}