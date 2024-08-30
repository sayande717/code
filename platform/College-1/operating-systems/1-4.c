#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct process {
    int PID;
    int burstTime;
    int arrivalTime;
    int priority;
    float avgTurnaroundTime;
    float avgWaitingTime;
};

void sort(struct process *proc, int maxProcesses) {
    for (int i = 0; i < maxProcesses - 1; i++) {
        for (int j = 0; j < maxProcesses - i - 1; j++) {
            if (proc[j].arrivalTime > proc[j + 1].arrivalTime) {
                struct process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
}

void fillProcessInfo(struct process *stack, int iter) {
    stack[iter].burstTime=-1;
    stack[iter].arrivalTime=-1;
    stack[iter].priority=-1;
}

void printProcDetails(struct process *proc, int maxProcesses) {
    printf("\nProcess ID\tBurst Time\tArrival Time");
    for (int i = 0; i < maxProcesses; i++) {
        printf("\n%d\t\t%d\t\t%d", proc[i].PID, proc[i].burstTime, proc[i].arrivalTime);
    }

    printf("\nAverage Turnaround Time: %.2f",proc[maxProcesses-1].avgTurnaroundTime);
    printf("\nAverage Waiting Time: %.2f",proc[maxProcesses-1].avgWaitingTime);
}

void FCFSNP(struct process *proc, int maxProcesses) {
    sort(proc, maxProcesses);
    int completionTime = proc[0].arrivalTime + proc[0].burstTime;
    proc[0].avgTurnaroundTime = completionTime - proc[0].arrivalTime;
    proc[0].avgWaitingTime = proc[0].avgTurnaroundTime - proc[0].burstTime;

    for (int i = 1; i < maxProcesses; i++) {
        if (proc[i].arrivalTime > completionTime) {
            completionTime = proc[i].arrivalTime;
        }
        completionTime += proc[i].burstTime;
        proc[i].avgTurnaroundTime = completionTime - proc[i].arrivalTime;
        proc[i].avgWaitingTime = proc[i].avgTurnaroundTime - proc[i].burstTime;
    }

    printProcDetails(proc, maxProcesses);
}

void SJFNP(struct process *proc, int maxProcesses) {
    sort(proc, maxProcesses);

    // Calculate completion time, turnaround time, and waiting time
    int completionTime = proc[0].arrivalTime + proc[0].burstTime;
    proc[0].avgTurnaroundTime = completionTime - proc[0].arrivalTime;
    proc[0].avgWaitingTime = proc[0].avgTurnaroundTime - proc[0].burstTime;

    for (int i = 1; i < maxProcesses; i++) {
        if (proc[i].arrivalTime > completionTime) {
            completionTime = proc[i].arrivalTime;
        }
        completionTime += proc[i].burstTime;
        proc[i].avgTurnaroundTime = completionTime - proc[i].arrivalTime;
        proc[i].avgWaitingTime = proc[i].avgTurnaroundTime - proc[i].burstTime;
    }

    printProcDetails(proc, maxProcesses);
}

void SJFP(struct process *proc, int maxProcesses) {
    sort(proc, maxProcesses);

    int currentTime = proc[0].arrivalTime;
    int remainingProcesses = maxProcesses;

    while (remainingProcesses > 0) {
        int shortestJobIndex = -1;
        int shortestJobBurstTime = INT_MAX;

        for (int i = 0; i < maxProcesses; i++) {
            if (proc[i].arrivalTime <= currentTime && proc[i].burstTime < shortestJobBurstTime && proc[i].burstTime > 0) {
                shortestJobIndex = i;
                shortestJobBurstTime = proc[i].burstTime;
            }
        }

        if (shortestJobIndex == -1) {
            currentTime++;
            continue;
        }

        proc[shortestJobIndex].burstTime--;
        currentTime++;

        if (proc[shortestJobIndex].burstTime == 0) {
            remainingProcesses--;
            proc[shortestJobIndex].avgTurnaroundTime = currentTime - proc[shortestJobIndex].arrivalTime;
            proc[shortestJobIndex].avgWaitingTime = proc[shortestJobIndex].avgTurnaroundTime - proc[shortestJobIndex].burstTime;
        }
    }

    printProcDetails(proc, maxProcesses);
}

void PriorityNP(struct process *proc, int maxProcesses) {
    sort(proc, maxProcesses);

    // Calculate completion time, turnaround time, and waiting time
    int completionTime = proc[0].arrivalTime + proc[0].burstTime;
    proc[0].avgTurnaroundTime = completionTime - proc[0].arrivalTime;
    proc[0].avgWaitingTime = proc[0].avgTurnaroundTime - proc[0].burstTime;

    for (int i = 1; i < maxProcesses; i++) {
        if (proc[i].arrivalTime > completionTime) {
            completionTime = proc[i].arrivalTime;
        }
        completionTime += proc[i].burstTime;
        proc[i].avgTurnaroundTime = completionTime - proc[i].arrivalTime;
        proc[i].avgWaitingTime = proc[i].avgTurnaroundTime - proc[i].burstTime;
    }

    printProcDetails(proc, maxProcesses);
}

void PriorityP(struct process *proc, int maxProcesses) {
    sort(proc, maxProcesses);

    int currentTime = proc[0].arrivalTime;
    int remainingProcesses = maxProcesses;

    while (remainingProcesses > 0) {
        int highestPriorityIndex = -1;
        int highestPriority = INT_MAX;

        for (int i = 0; i < maxProcesses; i++) {
            if (proc[i].arrivalTime <= currentTime && proc[i].priority < highestPriority && proc[i].burstTime > 0) {
                highestPriorityIndex = i;
                highestPriority = proc[i].priority;
            }
        }

        if (highestPriorityIndex == -1) {
            currentTime++;
            continue;
        }

        proc[highestPriorityIndex].burstTime--;
        currentTime++;

        if (proc[highestPriorityIndex].burstTime == 0) {
            remainingProcesses--;
            proc[highestPriorityIndex].avgTurnaroundTime = currentTime - proc[highestPriorityIndex].arrivalTime;
            proc[highestPriorityIndex].avgWaitingTime = proc[highestPriorityIndex].avgTurnaroundTime - proc[highestPriorityIndex].burstTime;
        }
    }

    printProcDetails(proc, maxProcesses);
}

void RoundRobinP(struct process *proc, int maxProcesses, int timeQuantum) {
    int remainingProcesses = maxProcesses;
    int currentTime = 0;

    while (remainingProcesses > 0) {
        for (int i = 0; i < maxProcesses; i++) {
            if (proc[i].burstTime > 0) {
                if (proc[i].burstTime <= timeQuantum) {
                    currentTime += proc[i].burstTime;
                    proc[i].burstTime = 0;
                    proc[i].avgTurnaroundTime = currentTime - proc[i].arrivalTime;
                    proc[i].avgWaitingTime = proc[i].avgTurnaroundTime - proc[i].burstTime;
                    remainingProcesses--;
                } else {
                    currentTime += timeQuantum;
                    proc[i].burstTime -= timeQuantum;
                }
            }
        }
    }

    printProcDetails(proc, maxProcesses);
}

int main() {
    int maxProcesses;
    printf("Enter the number of processes: ");
    scanf("%d",&maxProcesses);

    // Structure array of processes
    struct process procArr[maxProcesses];

    // INPUT: Process info
    for(int iter=0;iter<maxProcesses;iter++) {
        printf("\nProcess %d: ",iter);
        procArr[iter].PID=iter;
        printf("\nBurst Time: "); scanf("%d",&(procArr[iter].burstTime));
        printf("Arrival Time: "); scanf("%d",&(procArr[iter].arrivalTime));
        printf("Priority: "); scanf("%d",&(procArr[iter].priority));
    }

    // INPUT: Algorithm Selection
    // choice0 = {FCFS,SJF,Priority,Round Robin}
    // choice1 = {1: Non-Preemptive, 2: Preemptive}, only for SJF, Priority.
    int choice0,choice1;
    printf("\nOptions: ");
    printf("\n1. FCFS (First Come First Serve): ");
    printf("\n2. SJF (Shortest Job First): ");
    printf("\n3. Priority: ");
    printf("\n4. Round Robin: ");
    printf("\nEnter an Input: ");
    scanf("%d",&choice0);

    switch(choice0) {
        // FCFS (First Come First Serve)
        case 1:
            choice1=1;
            FCFSNP(procArr,maxProcesses);
            break;

        // SJF (Shortest Job First)
        case 2:
            // INPUT: choice 1
            printf("Input 1 for Preemptive, 2 for Non-Preemptive: ");
            scanf("%d",&choice1);
            if(choice1==1) {
                SJFP(procArr,maxProcesses);
            } else {
                SJFNP(procArr,maxProcesses);
            }
            break;

        // Priority
        case 3:
            // INPUT: choice 1
            printf("Input 1 for Preemptive, 2 for Non-Preemptive: ");
            scanf("%d",&choice1);
            if(choice1==1) {
                PriorityP(procArr,maxProcesses);
            } else {
                PriorityNP(procArr,maxProcesses);
            }
            break;

        // Round Robin
        case 4:
            int timeQuantum;
            printf("Enter the time quantum: ");
            scanf("%d",&timeQuantum);
            choice1=1;
            RoundRobinP(procArr,maxProcesses,timeQuantum);
            break;
    }
    return 0;
}