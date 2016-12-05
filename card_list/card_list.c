// Foundation Exam Practice
// Dynamic Memory Allocation
// Jake Ferrante

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char color[20];
    int number;
} UnoCard;
UnoCard *getCardList(char myColor[], int quantity);
UnoCard **getCardListAsRefs(char myColor[], int quantity);

// #1
// Write a function that takes in a single string, mycolor, and a single positive integer, quantity, and
// returns a pointer to an array of quantity UnoCard structs. Each of these structs should be assigned
// to have the color mycolor and each should be assigned the units digit of the index in which it's stored.
// (Thus, the card stored at index 27 should store the number 7, for example.) You may assume that
// string.h is included.
UnoCard *getCardList(char myColor[], int quantity) {
    UnoCard *cards = malloc(sizeof(UnoCard) * quantity);
    int x;
    for (x = 0; x < quantity; x++) {
        UnoCard card;
        card.number = x % 10;
        strcpy(card.color, myColor);
        cards[x] = card;
    }
    return cards;
}

// #2
// Solve a similar question to #1, but this time have the function return a pointer to an array of pointers to
// type UnoCard, where each of these pointers points to a single UnoCard struct. Store the same
// information as delineated in question 1 in each actual struct.
UnoCard **getCardListAsRefs(char myColor[], int quantity) {
    UnoCard **cards = malloc(sizeof(UnoCard *) * quantity);
    int x;
    for (x = 0; x < quantity; x++) {
        UnoCard card;
        card.number = x % 10;
        strcpy(card.color, myColor);
        cards[x] = malloc(sizeof(UnoCard));
        *cards[x] = card;
    }
    return cards;
}

void print_cards(UnoCard *cards, int quantity) {
    printf("Print Cards: \n");
    int x;
    for (x = 0; x < quantity; x++)
        printf("[%02d] \"%s\" %02d\n", x, cards[x].color, cards[x].number);
    printf("\n");
    return;
}

void print_ref_cards(UnoCard **cards, int quantity) {
    printf("Print Card Refs: \n");
    int x;
    for (x = 0; x < quantity; x++)
        printf("[%02d] \"%s\" %02d\n", x, cards[x]->color, cards[x]->number);
    printf("\n");
    return;
}

int main(void) {
    char *myColor = "green";
    int quantity = 23;
    UnoCard *cards = getCardList(myColor, quantity);
    print_cards(cards, quantity);
    UnoCard **card_refs = getCardListAsRefs(myColor, quantity);
    print_ref_cards(card_refs, quantity);
    return 0;
}