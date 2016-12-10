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
Node *insert_at_tail(Node *head, int data) {
    if (head == NULL)
        return head;

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = malloc(sizeof(Node *));
    temp->next->data = data;
    temp->next->next = NULL;
    return head;
}

Node *insert_at_head(Node *head, int data) {
    Node *new_head = malloc(sizeof(Node *));
    new_head->data = data;
    new_head->next = head;
    return new_head;
}

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

Node *filter_to_every_nth(Node *head, int nth) {

    // return immediately if we were passed a NULL pointer
    if (head == NULL)
        return head;

    // Create a new list and a temp for that list, as well
    // as a temp to iterate through the original list
    Node *temp = head, *f_head = malloc(sizeof(Node *));
    f_head->data = head->data;
    f_head->next = NULL;
    Node *f_temp = f_head;

    int i;
    for (i = 0; temp != NULL; i++) {
        // If the current node qualifies, add it to the new list
        if (i % nth == 0 && i != 0) {
            f_temp->next = malloc(sizeof(Node *));
            f_temp->next->data = temp->data;
            f_temp->next->next = NULL;
            f_temp = f_temp->next;
        }
        temp = temp->next;
    }
    return f_head;
}

// Returns a new list with all values below a specified value,
// contained in the original array in their respective order
// that were contained in the original array that were below
Node *filter_below_value(Node *head, int value) {
    Node *f_head = malloc(sizeof(Node *));
    Node *f_temp = f_head, *temp = head;

    // Scan through to init f_head value
    while (temp != NULL) {
        if (temp->data < value) {
            f_head->data = temp->data;
            f_head->next = NULL;
            break;
        }
    }

    // Fill in remaining items
    while (temp != NULL) {
        if (temp->data < value) {
            f_temp->next = malloc(sizeof(Node *));
            f_temp->next->data = temp->data;
            f_temp = f_temp->next;
        }
        temp = temp->next;
    }
    return f_head;
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

Node *reverse_list(Node *head) {
    Node *temp = head, *cur = head, *last = NULL;
    while (temp->next != NULL) {
        temp = temp->next;
        cur->next = last;
        last = cur;
        cur = temp;
    }
    temp->next = last;
    return temp;
}