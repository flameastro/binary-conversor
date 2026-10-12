#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define menu                                                                   \
    printf("[0] -> Exit program\n");                                           \
    printf("[1] -> Binary to decimal (eg. 1000 -> 8)\n");                      \
    printf("[2] -> Decimal to binary (eg. 8 -> 1000)\n");                      \
    printf("Please choose a number between 0 and 2\n");

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

int main() {
    int choose;

    menu;
    scanf("%d", &choose);

    while ((choose != 0) && (choose != 1) && (choose != 2)) {
        menu;
        scanf("%d", &choose);
    }

    if (choose == 0) {
        return 0;
    } else if (choose == 1) {
        char binary[50];

        printf("Binary: ");
        getchar();
        fgets(binary, sizeof(binary), stdin);

        binary[strcspn(binary, "\n")] = '\0';

        int size = strlen(binary);
        printf("%d  ", size);

        int result = binary_to_decimal(binary, size);
        printf("Result: %d", result);
    } else if (choose == 2) {
        int decimal;

        printf("Decimal: ");

        scanf("%d", &decimal);

        char *result = decimal_to_binary(decimal);
        printf("Result: %s", result);
    }

    return 0;
}
