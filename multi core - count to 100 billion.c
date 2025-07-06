#include <pthread.h>
#include <stdatomic.h>
#include <stdio.h> // For printing output
#include <stdlib.h> // For exiting on error

void *count_function(void *arg) {
    long thread_limit = (long)arg;
    for (long i = 0; i < thread_limit; ++i);
    pthread_exit(NULL);
}

int main() {
    int num_threads = 8;
    pthread_t threads[num_threads];
    long total_count = 100000000000LL;
    long count_per_thread = total_count / num_threads;

    for (int i = 0; i < num_threads; ++i) {
        int rc = pthread_create(&threads[i], NULL, count_function, (void*)count_per_thread);
        if (rc) {
            fprintf(stderr, "Error creating thread %d: %d\n", i, rc);
            exit(-1);
        }
    }

    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("Final count: %lu\n", count_per_thread * num_threads);

    return 0;
}
