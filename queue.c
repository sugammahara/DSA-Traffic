// queue.c
#include "queue.h"

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

bool isFull(Queue *q) {
    return q->count == MAX_QUEUE_SIZE;
}

bool isEmpty(Queue *q) {
    return q->count == 0;
}

void enqueue(Queue *q, Vehicle v) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->vehicles[q->rear] = v;
    q->count++;
}

Vehicle dequeue(Queue *q) {
    Vehicle empty = {"", ' '};
    if (isEmpty(q)) return empty;

    Vehicle v = q->vehicles[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->count--;
    return v;
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    int i, index = q->front;
    printf("Queue: ");
    for (i = 0; i < q->count; i++) {
        printf("[%s -> %c] ", q->vehicles[index].vehicleNumber, q->vehicles[index].lane);
        index = (index + 1) % MAX_QUEUE_SIZE;
    }
    printf("\n");
}
