#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <sys/types.h> 
#include <unistd.h>

void fileOperations() {
    FILE *file;
    char data[100];

    // Open the file, "r" = READ_ONLY mode
    file = fopen("file.txt", "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    // Read 1 line from the file
    fgets(data, sizeof(data), file);

    // Print the data
    printf("\nData from file: %s\n", data);

    // Close the file
    fclose(file);
}

void createChildProcess() {
    // fork() returns Child process ID in the forked process, and `0` in the parent process.
    int forkOutput = fork();
    
    // fork() is used as a conditional check to determine where the code is running.
    if(forkOutput==0) {
        printf("\n Parent process, PID: %d",getppid());
    } else {
        printf("\n Child process, PID: %d",forkOutput);
    }
    printf("\n");
}

void memoryManagement() {
    int *intArr = (int *)malloc(sizeof(int)*10);
    if(intArr==NULL) {
        fprintf(stderr,"Memory allocation failed.");
        exit(EXIT_FAILURE);
    }

    // Generate 10 random integers, put into array.
    srand(time(NULL));
    for(int iter=0;iter<10;iter++) {
        intArr[iter] = rand()%10;
    }

    printf("\n Array elements: ");
    for(int iter=0; iter<10; iter++) {
        printf("%d ", intArr[iter]);
    }

    // De-allocate memory
    free(intArr);
    printf("\n Memory deallocated successfully.");
    printf("\n");
    exit(EXIT_SUCCESS);
}

int main() {
    int choice;
    
    printf("\n Options: ");
    printf("\n 1. Create a child process");
    printf("\n 2. File operations");
    printf("\n 3. Memory management");
    printf("\n Enter your choice: "); scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            createChildProcess();
            break;
        case 2:
            fileOperations();
            break;
        case 3:
            memoryManagement();
            break;
        default:
            printf("\n Invalid choice.");
    }
    
    return EXIT_SUCCESS;
}
