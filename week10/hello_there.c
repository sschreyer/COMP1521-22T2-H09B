#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

void *thread_run(void *argument) {
    char *message = (char *) argument;
    while (true) {
        printf("%s", message);
    }
    return NULL;
}

int main(void) {
    char *message = "Hello\n";
    pthread_t thread;
    pthread_create(&thread, NULL, thread_run, message);

    while(true) {
        printf("there\n");
    }
}