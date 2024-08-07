#include<stdio.h>
#include <sys/types.h> 
#include <unistd.h> 

void childProcess() {
    // fork() returns Child process ID in the forked process, and `0` in the parent process.
    int forkOutput = fork();
    
    // fork() is used as a conditional check to determine where the code is running.
    if(forkOutput==0) {
        printf("\n Parent process, PID: %d",getppid());
    } else {
        printf("\n Child process, PID: %d",forkOutput);
    }
}

int main() {
    childProcess();
}