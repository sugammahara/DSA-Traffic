#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 50

typedef struct {
    char vehicleNumber[9];
    char lane;
} Vehicle;

typedef struct {
    Vehicle vehicles[MAX_QUEUE_SIZE];
    int front, rear, count;
} Queue;

void initQueue(Queue *q);
bool isFull(Queue *q);
bool isEmpty(Queue *q);
void enqueue(Queue *q, Vehicle v);
Vehicle dequeue(Queue *q);

#endif
