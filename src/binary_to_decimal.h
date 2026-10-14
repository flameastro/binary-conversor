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
