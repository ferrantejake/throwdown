#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int, char **);
void print_array(int *, int);
int read_from_file(char *filename, int *);
void print_menu();
void modify(int, Node *);
int request_input();

// Local declarations to abstract from linked_list.h
void _insert_at_head(Node *);
void _insert_at_tail(Node *);
void _insert_at_loc(Node *);
void _reverse_list(Node *);
void _display_length(Node *);

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

    // Print original array
    printf("original array: \n");
    print_array(arr, length);

    // Create a new linked list
    Node *head = create_list_from_array(arr, length);

    // Print new linked list
    printf("linked list: \n");
    print_linked_list(head);
    printf("\n");

    while (1) {
        print_menu();
        int opt = request_input();
        modify(opt, head);
    }

    // Remove element at specified location and print

    // // Filter elements and show new linked list
    // Node *below_value = filter_below_value(head, 15);
    // printf("filtered list (below: %d): \n", 15);
    // print_linked_list(below_value);

    // // Filter elements and show new linked list
    // Node *every_third = filter_to_every_nth(head, 3);
    // printf("filtered list (every 3rd node): \n");
    // print_linked_list(every_third);

    return 0;
}
int request_input() {
    int opt;
    printf("enter an option: ");
    scanf("%d", &opt);
    return opt;
}
void modify(int opt, Node *head) {
    switch (opt) {
    case 1:
        _insert_at_tail(head);
        break;
    case 2:
        _insert_at_head(head);
        break;
    case 3:
        _insert_at_loc(head);
        break;
    case 4:
        _insert_at_tail(head);
        break;
    case 5:
        _insert_at_tail(head);
        break;
    case 6:
        _display_length(head);
        break;
    case 7:
        _reverse_list(head);
        break;
    default:
        break;
    }
    printf("> updated list\n");
    print_linked_list(head);
    printf("\n");
}

// Add new element to the list
void _insert_at_tail(Node *head) {
    int data;
    printf("enter a value to be inserted: ");
    scanf("%d", &data);
    insert_at_tail(head, data);
}

// Add new element to head of the list
void _insert_at_head(Node *head) {
    int data;
    printf("enter a value to be inserted: ");
    scanf("%d", &data);
    head = insert_at_head(head, data);
}

// Add new element to location in list
void _insert_at_loc(Node *head) {
    int data, loc;
    printf("enter a value and location of data insertion: ");
    scanf("%d %d", &data, &loc);
    insert_at_loc(head, data, loc);
}

// Reverse and print array
void _reverse_list(Node *head) { head = reverse_list(head); }

void _contains(Node *head) {
    int data;
    printf("what value are we looking for: ");
    scanf("%d", &data);
    // Show that the linked list contains/does not contain an element
    int elem = 12;
    printf("Does this list contain [%d]? \t%s\n", elem, contains(head, elem) >= 0 ? "yes" : "no");
    elem = 5;
    printf("Does this list contain [%d]? \t%s\n", elem, contains(head, elem) >= 0 ? "yes" : "no");
}

// Display the size of the linked list
void _display_length(Node *head) { printf("length: \t\t\t%d\n", size(head)); }

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

void print_menu() {
    printf("Options:\n");
    printf("1. Insert data at tail\n");
    printf("2. Insert data at head\n");
    printf("3. Insert data at location\n");
    printf("4. Remove data\n");
    printf("5. Remove data (at location)\n");
    printf("6. Display length\n");
    printf("7. Reverse list\n");
}
