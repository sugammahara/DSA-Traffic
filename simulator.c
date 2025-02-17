#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include "queue.h"

#define SHM_KEY 1234

void processTraffic(Queue *queue) {
    while (!isEmpty(queue)) {
        Vehicle v = dequeue(queue);
        printf("Processing: %s from Lane %c\n", v.vehicleNumber, v.lane);
        sleep(1);
    }
}

int main() {
    int shmid = shmget(SHM_KEY, sizeof(Queue), 0666);
    if (shmid == -1) {
        perror("Shared memory access failed");
        exit(1);
    }

    Queue *queue = (Queue *)shmat(shmid, NULL, 0);
    if (queue == (void *)-1) {
        perror("Shared memory attachment failed");
        exit(1);
    }

    while (1) {
        if (!isEmpty(queue)) {
            processTraffic(queue);
        } else {
            printf("Waiting for vehicles...\n");
        }
        sleep(1);
    }

    shmdt(queue);
    return 0;
}
