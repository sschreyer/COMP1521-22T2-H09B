#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 65500

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr,  "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "w");
    if (f == NULL) {
        perror(argv[1]);
        return 1;
    }

    char buffer[MAX_SIZE]; 
    fgets(buffer, MAX_SIZE, stdin);
    
    int i = 0;
    while(buffer[i] != '\0' ) {
        fputc(buffer[i], f);
        i++;
    }

    // remember to close your files!
    fclose(f);

    return 0;
}