// read 32-byte hexadecimal numbers from a file
// and print low (least significant) byte
// as a signed decimal number (-128..127)

#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error, just give a filename as command line args");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    int32_t number; 
    while (fscanf(f, "%x", &number) == 1) {
        int32_t low_byte = number & 0xff;
        if (low_byte & (1 << 7)) {
            // we have a negative 8 bit number
            low_byte = -(1 << 8) + low_byte;
        }

        printf("%d\n", low_byte);
        // not defined by C standard
        // int8_t lowest_byte_as_signed = low_byte;
    }


}