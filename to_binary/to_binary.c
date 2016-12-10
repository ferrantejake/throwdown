#include <stdio.h>
#include <stdlib.h>

int to_binary(int);

int main() {
    int decimal;
    printf("enter a decimal number: ");
    scanf("%d", &decimal);
    printf("%d => %d\n", decimal, to_binary(decimal));
}

int to_binary(int decimalNo) {
    if (decimalNo < 2)
        return decimalNo;

    return to_binary(decimalNo / 2) * 10 + (decimalNo % 2);
}