// remove public write from specified as command line arguments if needed

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void chmod_if_needed(char *pathname);

int main(int argc, char *argv[]) {
    
    for (int i = 1; i < argc; i++) {
        chmod_if_needed(argv[i]);
    }

    return 0;
}

// chmod a file if publically-writeable

void chmod_if_needed(char *pathname) {
    struct stat file_info;
    if (stat(pathname, &file_info) != 0) {
        perror(pathname);
        exit(1);
    }

    mode_t mode = file_info.st_mode; 
    if (!(mode & S_IWOTH)) {
        fprintf(stderr, "File [%s] already isn't publicly writeable!", pathname);
        return; 
    }

    printf("Removing public write from %s", pathname);

    mode_t new_mode = mode & ~(S_IWOTH);
    
    if (chmod(pathname, new_mode) != 0) {
        perror(pathname);
        exit(1);
    }


}