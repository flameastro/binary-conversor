int binary_to_decimal(char *binary, int size) {
    // 1000 -> 8
    // Verify if input is correctly typed
    for (int i = 0; i < size; i++) {
        if ((binary[i] != '0') && (binary[i] != '1')) {
            printf("The input is incorrectly. Only 0's and 1's\n");
            exit(1);
        }
    }

    int decimal = 0;
    int exp = 1;

    for (int i = size - 1; i > -1; i--) {
        int binary_int = binary[i] - '0'; // converts char to int
        decimal += exp * binary_int;

        exp *= 2;
    }

    return decimal;
}
