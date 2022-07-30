// print $HOME/.diary to stdout

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    
    char *home_path = getenv("HOME");
    char *diary = ".diary";

    int path_length = strlen(home_path) + strlen(diary) + 2;
    char *diary_pathname = malloc(path_length * sizeof(char));
    snprintf(diary_pathname, path_length, "%s/%s", home_path, diary);

    FILE *f = fopen(diary_pathname, "r");
    if (f == NULL) {
        perror(diary_pathname);
        return 1;
    }

    int byte;
    while ((byte = fgetc(f)) != EOF) {
        fputc(byte, stdout);
    }

    fclose(f);


    return 0;
}