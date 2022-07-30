// read 32-byte hexadecimal numbers from a file
// and print low (least significant) byte
// as a signed decimal number (-128..127)

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen("test.txt", "w");
    if (f == NULL) {
        printf("Error: File can't be opened\n");
        exit(1);
    }

    for (int i = 0; i <= 64; i += 4) {
        fprintf(f, "%x\n", i);
    }

    for (int i = -64; i <= 0; i += 4) {
        fprintf(f, "%x\n", i);
    }
}