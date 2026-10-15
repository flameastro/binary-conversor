#include <math.h>
#include <stdlib.h>

char *decimal_to_binary(int number) {
    // 8 -> 1000
    int size = log2(number) + 1;
    int half = (int)(size / 2);

    char *binary = (char *)calloc(size, sizeof(char));

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
