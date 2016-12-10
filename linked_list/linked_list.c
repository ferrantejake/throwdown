#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// Create linked list from array
Node *create_list_from_array(int *arr, int length) {
    Node *head = malloc(sizeof(Node *));
    head->data = arr[0];
    Node *temp = head;
    int i;
    for (i = 1; i < length; i++) {
        Node *new = malloc(sizeof(Node *));
        new->data = arr[i];
        temp->next = new;
        temp = new;
    }
    return head;
}

// Insert a new node to the end of the linked list
Node *insert(Node *head, int data) { return head; }

// Insert a new node at a specificed location
Node *insert_at_loc(Node *head, int loc, int data) {
    Node *temp = head;
    int i = 0;

    // Look for as long as the list has another item in the list
    // to compare indexes against.
    while (temp != NULL) {

        // If the current index is the location we are looking for,
        // then create a new node and insert it between the current
        // node and the next node.
        if (loc == i++) {
            Node *new = malloc(sizeof(Node *));
            new->data = data;
            new->next = temp->next;
            temp->next = new;
            return head;
        }

        // Otherwise keep looking.
        temp = temp->next;
    }
    return head;
}

// Remove node from linked list
Node *remove_node(Node *head, int data) { return head; }

// Remove node based on location from linked list
Node *remove_at_loc(Node *head, int loc) { return head; }

// Returns the index of the data if it exists,
// otherwise returns -1
int contains(Node *head, int data) {
    Node *temp = head;
    int loc;
    while (temp != NULL) {
        if (data == temp->data)
            return loc;
        temp = temp->next;
        loc++;
    }
    return -1;
}

// Returns the size of the linked list
int size(Node *head) {
    Node *temp = head;
    int size = 0;
    while (temp != NULL) {
        temp = temp->next;
        size++;
    }
    return size;
}

// Prints the linked list
void print_linked_list(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" => ");
        temp = temp->next;
    }
    printf("\n");
}