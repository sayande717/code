#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void createNormalProcess() {
    pid_t pid = fork();
    if(pid > 0) {
        printf("\n Parent PID: %d", getpid());
    } else if(pid == 0) {
        printf("\n Child PID: %d", getpid());
    } else {
        fprintf(stderr, "fork() failed.");
        exit(EXIT_FAILURE);
    }
    printf("\n");
}

void createZombieProcess() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent process
        printf("\n Parent process PID: %d", getpid());
        printf("\n Child process PID: %d", pid);
        sleep(10); // Sleep to keep the parent process alive
        // Parent does not call wait(), so the child becomes a zombie
    } else if (pid == 0) {
        // Child process
        printf("\n Child process PID: %d", getpid());
        printf("\n Child process exiting...");
        exit(0); // Child exits
    } else {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    printf("\n");
}

void createOrphanProcess() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent process
        printf("\n Parent process PID: %d", getpid());
        printf("\n Child process PID: %d", pid);
        sleep(2); // Sleep to allow the child to run
        printf("\n Parent process exiting...\n");
        exit(0); // Parent exits, making the child an orphan
    } else if (pid == 0) {
        // Child process
        sleep(5); // Sleep to keep the child process alive
        printf("\n Orphaned child process PID: %d, Parent PID: %d", getpid(), getppid());
        // The parent PID will be 1 (init process)
    } else {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    printf("\n");
}

int main() {
    int choice;

    printf("Options: ");
    printf("\n 1. Create a normal process: ");
    printf("\n 2. Create a zombie process: ");
    printf("\n 3. Create an orphaned process: ");
    printf("\n Enter a choice: "); scanf("%d", &choice);

    switch(choice) {
        case 1:
            createNormalProcess();
            break;
        case 2:
            createZombieProcess();
            break;
        case 3:
            createOrphanProcess();
            break;
        default:
            printf("\n Wrong input.");
    }
    
    exit(EXIT_SUCCESS);
    // return 0;
}
