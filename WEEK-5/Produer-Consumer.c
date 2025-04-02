#include <stdio.h>

#define BUFFER_SIZE 3  // Size of the buffer

int buffer[BUFFER_SIZE];  // Shared buffer
int in = 0, out = 0;  // Indices for producer and consumer
int mutex = 1;  // Lock for synchronization
int empty = BUFFER_SIZE;  // Number of empty slots in buffer
int full = 0;  // Number of full slots in buffer

void wait(int *value) {
    (*value)--;  // Decrease value directly
}

void signal(int *value) {
    (*value)++;  // Increase value directly
}

void producer(int item) {
    if (empty == 0) {
        printf("Buffer is FULL! Producer cannot add item \n");
        return;
    }

    wait(&empty);  // Check if buffer has space
    wait(&mutex);  // Lock critical section

    buffer[in] = item;  // Add item to buffer
    printf("Producer added item %d\n", item);
    in = (in + 1) % BUFFER_SIZE;  // Move to next position

    signal(&mutex);  // Unlock critical section
    signal(&full);  // Increase full slot count
}

void consumer() {
    if (full == 0) {
        printf("Buffer is EMPTY! Consumer cannot remove items.\n");
        return;
    }

    wait(&full);  // Check if buffer has items
    wait(&mutex);  // Lock critical section

    int item = buffer[out];  // Remove item from buffer
    printf("Consumer consumed item %d\n", item);
    out = (out + 1) % BUFFER_SIZE;  // Move to next position

    signal(&mutex);  // Unlock critical section
    signal(&empty);  // Increase empty slot count
}

int main() {
    int choice, item = 1;

    printf("Producer-Consumer Simulation\n\n");

    while (1) {
        printf("\nChoose an action:\n");
        printf("1. Produce \t 2. Consume\t 3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                producer(item);
                item++;
                break;

            case 2:
                consumer();
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
