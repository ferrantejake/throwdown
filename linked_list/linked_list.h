#ifndef SORTS_H_
#define SORTS_H_
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create_list_from_array(int *, int);
Node *insert(Node *head, int data);
Node *insert_at_loc(Node *head, int loc, int data);
Node *remove_data(Node *head, int data);
Node *remove_at_location(Node *head, int loc);
Node *reverse(Node *head);
Node *filter_to_every_nth(Node *, int nth);
Node *filter_above_value(Node *, int value);
Node *filter_below_value(Node *, int value);
int contains(Node *head, int data);
int size(Node *head);
void print_linked_list(Node *);
#endif