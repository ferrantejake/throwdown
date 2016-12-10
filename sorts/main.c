#include "sorts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int, char **);
void print_array(int *, int);
int read_from_file(char *filename, int *);

int main(int argc, char **argv) {
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
    print_array(arr, length);
    arr = merge_sort_recursive(arr, 0, length - 1);
    print_array(arr, length);
    free(arr);
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