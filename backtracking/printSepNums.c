#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void printSepNums(int, int, int, int);

int main() {
    int n, s, curNum = 0, k = 0;
    printf("> pro tip: larger difference between [n] and [s] means longer runtimes.\n");
    printf("enter [n] and [s] (separated by a space): ");
    scanf("%d %d", &n, &s);
    printSepNums(n, s, curNum, k);
}

// Prints all numbers with n number of digits, where each digit
// has a difference of at least s with the immediately adjacent digit
void printSepNums(int n, int s, int curNum, int k) {
    if (n == k) {
        printf("%d\n", curNum);
        return;
    }

    int i;
    for (i = 0; i <= 9; i++)
        if (abs(curNum % 10 - i) >= s && curNum * 10 + i < INT_MAX)
            printSepNums(n, s, curNum * 10 + i, k + 1);
}
