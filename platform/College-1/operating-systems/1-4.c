#include<stdio.h>

// Process template
struct process {
    int PID;
    int burstTime;
    int arrivalTime;
    int priority;
    float avgTurnaroundTime;
    float avgWaitingTime;
};

// TODO: Init Algorithms
void FCFS(struct process* proc, int maxProcesses, int ID) {

}
// void SJFNP(struct process* proc, int ID);
// void SJFP(struct process* proc, int ID);
// void Priority(struct process* proc, int ID);

// INPUT
// void fillProcessInfo(struct process* stack, int iter) {
//     stack->burstTime[iter]=-1;
//     stack->arrivalTime[iter]=-1;
//     stack->priority[iter]=-1;
// }

int main() {
    int maxProcesses;
    printf("Enter the number of processes: ");
    scanf("%d",&maxProcesses);

    // Structure array of processes
    struct process* procArr[maxProcesses];

    // INPUT: Process info
    for(int iter=0;iter<maxProcesses;iter++) {
        printf("\nProcess %d: ",iter);
        printf("\nBurst Time: "); scanf("%d",&procArr[iter]->burstTime);
        printf("Arrival Time: "); scanf("%d",&procArr[iter]->arrivalTime);
        printf("Priority: "); scanf("%d",&procArr[iter]->priority);

        free(procArr[iter]);
    }

    // INPUT: Algorithm Selection
    // choice0 = {FCFS,SJF,Priority,Round Robin}
    // choice1 = {0: Non-Preemptive, 1: Preemptive}, only for SJF, Priority.
    int choice0,choice1;
    printf("\nChoose: ");
    printf("\n1. FCFS (First Come First Serve): ");
    printf("\n2. SJF (Shortest Job First): ");
    printf("\n3. Priority: ");
    printf("\n4. Round Robin: ");
    printf("\n");
    scanf("%d",&choice0);

    switch(choice0) {
        // FCFS (First Come First Serve)
        case 1:
            // INPUT: choice 1
            choice1=0;
            break;

        // SJF (Shortest Job First)
        case 2:
            // INPUT: choice 1
            printf("Input 1 for Preemptive, 2 for Non-Preemptive");
            scanf("%d",&choice1);

            break;

        // Priority
        case 3:
            // INPUT: choice 1
            printf("Input 1 for Preemptive, 2 for Non-Preemptive");
            scanf("%d",&choice1);

            break;

        // Round Robin
        case 4:
            choice1=1;
            break;
    }


    return 0;
}