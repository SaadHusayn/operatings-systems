#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    // Create a shared memory region of size 4 bytes (sizeof(int))
    int *shared_int = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
                           MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    if (shared_int == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    *shared_int = 42;  // Initial value

    pid_t pid = fork();

    if (pid == 0) {  // Child process
        printf("Child sees value: %d\n", *shared_int);
        *shared_int = 99;  // Modify shared memory
        printf("Child changed value to: %d\n", *shared_int);
    } else {  // Parent process
        sleep(1);  // Ensure child runs first
        printf("Parent sees value: %d\n", *shared_int);
    }

    // Cleanup
    munmap(shared_int, sizeof(int));

    return 0;
}
