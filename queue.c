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
    if (isFull(q)) return;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->vehicles[q->rear] = v;
    q->count++;
}

Vehicle dequeue(Queue *q) {
    Vehicle emptyVehicle = {"", ' '};
    if (isEmpty(q)) return emptyVehicle;
    Vehicle v = q->vehicles[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->count--;
    return v;
}
