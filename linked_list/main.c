#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int, char **);
void print_array(int *, int);
int read_from_file(char *filename, int *);

int main(int argc, char **argv) {

    // Create a new array from our input files
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

    // Create a new linked list
    Node *head = create_list_from_array(arr, length);

    // Print original array
    printf("original array: \n");
    print_array(arr, length);

    // Print new linked list
    printf("linked list: \n");
    print_linked_list(head);

    // Display the size of the linked list
    printf("length: \t\t\t%d\n", size(head));
    // size(linkedList)

    // Show that the linked list contains/does not contain an element
    int elem = 12;
    printf("Does this list contain [%d]? \t%s\n", elem, contains(head, elem) >= 0 ? "yes" : "no");
    elem = 5;
    printf("Does this list contain [%d]? \t%s\n", elem, contains(head, elem) >= 0 ? "yes" : "no");

    // Insert a new element in the list and print

    // Remove element at specified location and print

    // Reverse and print array

    // Filter elements and show new linked list

    // Print original linked list

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