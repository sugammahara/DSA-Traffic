// queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 50

// Vehicle structure
typedef struct {
    char vehicleNumber[9]; // e.g., "AB1CD123"
    char lane;             // A, B, C, or D
} Vehicle;

// Queue structure
typedef struct {
    Vehicle vehicles[MAX_QUEUE_SIZE];
    int front, rear, count;
} Queue;

// Queue function declarations
void initQueue(Queue *q);
bool isFull(Queue *q);
bool isEmpty(Queue *q);
void enqueue(Queue *q, Vehicle v);
Vehicle dequeue(Queue *q);
void displayQueue(Queue *q);

#endif
