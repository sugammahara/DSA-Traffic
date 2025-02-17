#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include "queue.h"

#define SHM_KEY 1234

void generateVehicleNumber(char *buffer) {
    sprintf(buffer, "%c%c%d%c%c%d%d%d",
            'A' + rand() % 26, 'A' + rand() % 26, rand() % 10,
            'A' + rand() % 26, 'A' + rand() % 26, rand() % 10,
            rand() % 10, rand() % 10);
}

char generateLane() {
    char lanes[] = {'A', 'B', 'C', 'D'};
    return lanes[rand() % 4];
}

int main() {
    int shmid = shmget(SHM_KEY, sizeof(Queue), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("Shared memory creation failed");
        exit(1);
    }

    Queue *queue = (Queue *)shmat(shmid, NULL, 0);
    if (queue == (void *)-1) {
        perror("Shared memory attachment failed");
        exit(1);
    }

    srand(time(NULL));
    initQueue(queue);

    while (1) {
        if (!isFull(queue)) {
            Vehicle v;
            generateVehicleNumber(v.vehicleNumber);
            v.lane = generateLane();
            enqueue(queue, v);
            printf("Generated: %s on Lane %c\n", v.vehicleNumber, v.lane);
        }
        sleep(1);
    }

    shmdt(queue);
    return 0;
}
