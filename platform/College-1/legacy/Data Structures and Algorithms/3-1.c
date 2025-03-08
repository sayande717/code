#include<stdio.h>
#include<stdbool.h>
// Update with the value of N
#define N 5

struct linearQueue {
    int arr[N];
    int front;
    int rear;
};

void initQueue(struct linearQueue *queue) {
    queue->front=-1;
    queue->rear=-1;
}

bool isEmpty(struct linearQueue *queue) {
    if(queue->front==-1 && queue->rear==-1) {
        return true;
    }
    return false;
}

bool isFull(struct linearQueue *queue) {
    if(queue->rear == (sizeof(queue->arr)/sizeof(queue->arr[0])-1)) {
        return true;
    }
    return false;
}

void enQueue(struct linearQueue *queue, int data) {
    if(isFull(queue)) {
        printf("\nQueue Overflow");
        return;
    } else if(isEmpty(queue)) {
        ++queue->front;
    }
    
    queue->arr[++queue->rear]=data;
}

void deQueue(struct linearQueue *queue) {
    if(isEmpty(queue)) {
        return;
    }
    ++queue->front;
}

// ERR: -1
int peek(struct linearQueue *queue) {
    if(!isEmpty(queue)) {
        return queue->arr[queue->rear];
    }
    return -1;
}

void traverse(struct linearQueue *queue) {
    if(isEmpty(queue)) {
        printf("Queue Underflow");
        return;
    }
    
    for(int index=queue->front;index<=queue->rear;index++) {
        printf("%d ",queue->arr[index]);
    }
}

int main() {
   struct linearQueue heightQueue;
   initQueue(&heightQueue);
   
   // INPUT: Student's height
   printf("Enter student's height: \n");
   for(int iter=0;iter<N;iter++) {
       int height;
       printf("%d. ",(iter+1));
       scanf("%d",&height);
       enQueue(&heightQueue,height);
   }
   
   // DISPLAY
   printf("\n Heights in queue: ");
   traverse(&heightQueue);
   
   // Dequeue twice and display
   deQueue(&heightQueue);
   deQueue(&heightQueue);
   printf("\n After dequeueing 2 times, heights in queue: ");
   traverse(&heightQueue);
   printf("\n");
   return 0;
}
