#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_to_decimal.h"
#include "decimal_to_binary.h"

#define menu                                                                   \
    printf("[0] -> Exit program\n");                                           \
    printf("[1] -> Binary to decimal (eg. 1000 -> 8)\n");                      \
    printf("[2] -> Decimal to binary (eg. 8 -> 1000)\n");                      \
    printf("Please choose a number between 0 and 2\n");

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
        char binary[33]; // 32 bits (4 bytes) + 1 for '\0'

        printf("Binary: ");

        getchar(); // get \n from scanf

        fgets(binary, sizeof(binary), stdin);
        binary[strcspn(binary, "\n")] = '\0';

        int size = strlen(binary);
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
