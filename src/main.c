#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binary_to_decimal(char *binary, int size) {
    // 1000 -> 8
    int decimal = 0;
    int exp = 1;

    for (int i = size - 1; i > -1; i--) {
        int binary_int = binary[i] - '0'; // converts char to int

        decimal += exp * binary_int;

        exp *= 2;
    }

    return decimal;
}

int main() {
    char *binary = "11011";
    int size = strlen(binary);

    int result = binary_to_decimal(binary, size);
    printf("Result: %d", result);

    return 0;
}
