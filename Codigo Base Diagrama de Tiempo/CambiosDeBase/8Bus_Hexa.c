void bus8_to_hex(int a7[], int a6[], int a5[], int a4[],int a3[], int a2[], int a1[], int a0[],
    int index,char out[3]){
    unsigned char value =
        ((a7[index] & 1) << 7) |
        ((a6[index] & 1) << 6) |
        ((a5[index] & 1) << 5) |
        ((a4[index] & 1) << 4) |
        ((a3[index] & 1) << 3) |
        ((a2[index] & 1) << 2) |
        ((a1[index] & 1) << 1) |
        (a0[index] & 1);

    const char hex[] = "0123456789ABCDEF";

    out[0] = hex[(value >> 4) & 0x0F];
    out[1] = hex[value & 0x0F];
    out[2] = '\0';
}