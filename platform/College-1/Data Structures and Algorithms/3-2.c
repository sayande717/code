#include<stdio.h>
#include<stdbool.h>
// Update with the value of N
#define N 20

struct circularQueue {
    int arr[N];
    int front;
    int rear;
};

void initQueue(struct circularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// for isEmpty(), we simply check if both front & rear are -1.
bool isEmpty(struct circularQueue *queue) {
    if (queue->front == -1 && queue->rear == -1) {
        return true;
    }
    return false;
}

// In a circular queue, rear can be at any position, due to which we cannot check for the condition rear==(queue.length-1). Instead, we check if front is right next to rear.
bool isFull(struct circularQueue *queue) {
    // (rear+1)%n calculates the next position after rear.
    if ((queue->rear + 1) % N == queue->front) {
        return true;
    }
    return false;
}

void enQueue(struct circularQueue *queue, int data) {
    if (isFull(queue)) {
        printf("\nQueue Overflow");
        return;
    } else if (isEmpty(queue)) {
        queue->front = 0;
    }
    
    queue->rear = (queue->rear + 1) % N;
    queue->arr[queue->rear] = data;
}

void deQueue(struct circularQueue *queue) {
    if (isEmpty(queue)) {
        return;
    }
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % N;
    }
}

// ERR: -1
int peek(struct circularQueue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    return queue->arr[queue->front];
}

void traverse(struct circularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow");
        return;
    }
    
    int index = queue->front;
    while (index != queue->rear) {
        printf("%d ", queue->arr[index]);
        index = (index + 1) % N;
    }
    printf("%d", queue->arr[index]);
}

int main() {
   struct circularQueue patientQueue;
   initQueue(&patientQueue);
   
   // INPUT: Patient ID
   printf("Enter Patient ID: \n");
   for (int iter = 0; iter < N; iter++) {
       int patientID;
       printf("%d. ", (iter + 1));
       scanf("%d", &patientID);
       enQueue(&patientQueue, patientID);
   }
   
   // DISPLAY
   printf("\n Patient IDs: ");
   traverse(&patientQueue);
   
   // Dequeue twice and display
   deQueue(&patientQueue);
   deQueue(&patientQueue);
   printf("\n After dequeueing 2 times, Patient IDs: ");
   traverse(&patientQueue);
   printf("\n");
   return 0;
}
