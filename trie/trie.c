// Foundation Exam Sample Problems
// Jake Ferrante

// Trie

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode {
    struct TrieNode *children[26];
    int count;
} TrieNode;

int main();
TrieNode *insert(TrieNode *, char *);
void printTrie(TrieNode *, int, char *);

// Inserts a string into a trie
TrieNode *insert(TrieNode *root, char *str) {
    int i;
    if (root == NULL) {
        root = malloc(sizeof(TrieNode));
        for (i = 0; i < 26; i++)
            root->children[i] = NULL;
        root->count = 0;
    }

    int depth = 0, length = sizeof(str);
    struct TrieNode *cur = root;

    for (; depth < (int)strlen(str); depth++) {
        int loc = tolower(str[depth]) - 'a';

        // If the current node has a child at the location of
        // the int value of the current character in the string
        if (cur->children[loc] == NULL) {
            struct TrieNode *temp = malloc(sizeof(TrieNode));
            for (i = 0; i < 26; i++)
                temp->children[i] = NULL;
            temp->count = 0;
            cur->children[loc] = temp;
        }
        cur = cur->children[loc];
    }

    // If we make it here, then we have made it to the end of
    // the string we were trying to insert, update the count
    // at the current node accordingly to reflect the insertion
    cur->count += 1;

    // Return the root of the Trie
    return root;
}

// Prints all words listen in a Trie
void printTrie(TrieNode *root, int level, char *buffer) {
    // indicates first iteration
    if (level == 0)
        printf("words in trie:\n");

    int c;
    for (c = 0; c < 26; c++) {
        if (root->children[c] != NULL) {
            buffer[level] = (char)(c + 97);
            printTrie(root->children[c], level + 1, buffer);
        }
    }
    if (root->count == 1)
        printf("> %s\n", buffer);
    buffer[level] = '\0';
    return;
}

int main() {
    char buffer[20];
    struct TrieNode *root;
    int i = 0;

    // set up buffer
    while (i < 20)
        buffer[i++] = '\0';

    // insert items
    root = insert(NULL, "hummus");
    insert(root, "Perseus");
    insert(root, "computerscience");

    printTrie(root, 0, buffer);
    return 1;
}