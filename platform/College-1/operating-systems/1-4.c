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

void printProcDetails(struct process *proc, int maxProcesses) {
    printf("\nAverage Turnaround Time: %.2f",proc[maxProcesses-1].avgTurnaroundTime);
    printf("\nAverage Waiting Time: %.2f",proc[maxProcesses-1].avgWaitingTime);
    printf("\n");
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

void SRTFNP(struct process *proc, int maxProcesses) {
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
    int maxProcesses, timeQuantum;
    printf("Enter the number of processes: ");
    scanf("%d",&maxProcesses);

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
    int choice1;

    printf("\n Options: ");
    printf("\n 1. FCFS (First Come First Serve): ");
    printf("\n 2. SRTF (Shortest Remaining Time First) / SJF (Shortest Job First): ");
    printf("\n 3. Priority: ");
    printf("\n 4. Round Robin: ");
    printf("\n Enter an Input: "); scanf("%d",&choice1);

    switch(choice1) {
        // FCFS
        case 1:
            FCFSNP(procArr,maxProcesses);
            break;

        // SRTF / SJF 
        case 2:
            printf("\n SRTF (Non-Preemptive): "); SRTFNP(procArr,maxProcesses);
            printf("\n SJF (Preemptive: )"); SJFP(procArr,maxProcesses);
            break;

        // Priority
        case 3:
            printf("\n Priority (Preemptive): "); PriorityP(procArr, maxProcesses);
            printf("\n Priority (Non-Preemptive): "); PriorityNP(procArr, maxProcesses);
            break;

        // Round Robin
        case 4:
            printf("Enter the time quantum: ");
            scanf("%d",&timeQuantum);
            RoundRobinP(procArr,maxProcesses,timeQuantum);
            break;
        }
    return 0;
}
