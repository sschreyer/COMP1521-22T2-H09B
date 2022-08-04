#include <stdio.h>
#include <pthread.h>

int global_total = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *add_5000_to_counter(void *data) {
    for (int i = 0; i < 5000; i++) {
        // sleep for 1 nanosecond
        nanosleep (&(struct timespec){.tv_nsec = 1}, NULL);
        
        // increment the global total by 1
        pthread_mutex_lock(&lock);
        global_total++;
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main(void) {
    pthread_t thread1;
    pthread_create(&thread1, NULL, add_5000_to_counter, NULL);

    pthread_t thread2;
    pthread_create(&thread2, NULL, add_5000_to_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // if program works correctly, should print 10000
    printf("Final total: %d\n", global_total);
}



pthread_mutex_t lock_a = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_b = PTHREAD_MUTEX_INITIALIZER;

int global_total_a = 0;
int global_total_b = 0;

void *thread_one(void *data) {
    
    pthread_mutex_lock(&lock_a);
    pthread_mutex_lock(&lock_b);
    global_total++;
    pthread_mutex_unlock(&lock_a);
    pthread_mutex_unlock(&lock_b);

    return NULL;
}

void *thread_two(void *data) {
    
    pthread_mutex_lock(&lock_b);
    pthread_mutex_lock(&lock_a);
    global_total++;
    pthread_mutex_unlock(&lock_b);
    pthread_mutex_unlock(&lock_a);

    return NULL;
}