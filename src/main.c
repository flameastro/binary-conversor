#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decimal_to_binary(int number) {
    char *binary;
    int size = log2(number) + 1;
    int half = (int)(size / 2);

    binary = calloc(size, sizeof(char));

    // getting the rests
    int i = 0;
    while (number != 0) {
        int rest = number % 2;
        binary[i] = rest + '0'; // converts int into str

        number /= 2;

        i += 1;
    }

    // reversing string
    int limit = size - 1;
    for (int i = 0; i < half; i++) {
        int aux = binary[i];
        binary[i] = binary[limit - i];
        binary[limit - i] = aux;
    }

    return binary;
}

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
    printf("resultado: %d", result);

    return 0;
}
