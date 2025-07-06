// C code to count cores

#include <unistd.h>
#include <stdio.h>

int main() {
    long num_cores = sysconf(_SC_NPROCESSORS_ONLN);
    if (num_cores == -1) {
        perror("sysconf");
        return 1;
    }
    printf("Number of online CPU cores: %ld\n", num_cores);
    return 0;
}