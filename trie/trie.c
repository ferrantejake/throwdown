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
void printWordsNotContainingChar(TrieNode *, char);
void _printWordsNotContainingChar(TrieNode *, char, char *, int, int);
void printWordsContainingChar(TrieNode *, char);
void _printWordsContainingChar(TrieNode *, char, char *, int, int);
void printStringsContaningSubstring(TrieNode *, char *);
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

void printWordsContainingChar(TrieNode *root, char c) {
    // Note that we indicate a max length of 20 for input strings.
    // Exceeding this length will likely cause a segmentation fault.
    printf("print strings containing: %c\n", c);

    // Return immediately if root is null.
    if (root == NULL)
        return;

    char *buffer = malloc(sizeof(char) * 20);
    _printWordsContainingChar(root, c, buffer, 0, 0);
    return;
};

void _printWordsContainingChar(TrieNode *root, char c, char *buffer, int containsC, int depth) {
    // printf("print_strings_cont: %c %s %d %d > %d\n", c, buffer, containsC, depth, root->count);

    // If we found a string, the print the string if that string
    // contains the character we are looking for.
    if (root->count > 0)
        if (containsC)
            printf("> %s\n", buffer);

    int i;
    // Check all of the child nodes if they exist and check containsC
    // if we call a child are looking for.
    for (i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            // Update the buffer to the current character.
            buffer[depth] = i + 'a';
            // Call down with the current child, buffer, next depth level, and update containsC if available.
            _printWordsContainingChar(root->children[i], c, buffer, containsC | (i + 'a' == c ? 1 : 0), depth + 1);
            // Reset character.
            buffer[depth] = '\0';
        }
    }
    return;
}

void printWordsNotContainingChar(TrieNode *root, char c) {
    printf("print strings not containing: %c\n", c);

    if (root == NULL)
        return;

    char *buffer = malloc(sizeof(char) * 20);
    _printWordsNotContainingChar(root, c, buffer, 0, 0);
    return;
}
void _printWordsNotContainingChar(TrieNode *root, char c, char *buffer, int containsC, int depth) {

    if (root->count > 0)
        if (!containsC)
            printf("> %s\n", buffer);

    int i;
    for (i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            buffer[depth] = i + 'a';
            _printWordsNotContainingChar(root->children[i], c, buffer, containsC | (i + 'a' == c ? 1 : 0), depth + 1);
            buffer[depth] = '\0';
        }
    }
    return;
}

// void printStringsContainingSubstring(char *c) { return; }

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

    char c = 'h';
    printWordsContainingChar(root, c);
    printWordsNotContainingChar(root, c);
    printWordsNotContainingChar(root, 'i');
    printTrie(root, 0, buffer);
    printTrie(root, 0, buffer);
    return 1;
}