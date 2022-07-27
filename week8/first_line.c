#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr,  "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        perror(argv[1]);
        return 1;
    }

    int c = 0;
    while((c = fgetc(f)) != EOF) {
        fputc(c, stdout);
        if (c == '\n') {
            break;
        }
    }

    // remember to close your files!
    fclose(f);

    return 0;
}