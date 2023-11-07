#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueue {
    int front, rear, size;
    int *array;
} CircularQueue;

CircularQueue* createQueue(int size) {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->size = size;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(size * sizeof(int));
    return queue;
}

void enqueue(CircularQueue* queue, int value) {
    if ((queue->rear + 1) % queue->size == queue->front) {
        printf("OVERFLOW\n");
    } else {
        if (queue->rear == -1) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % queue->size;
        queue->array[queue->rear] = value;
        printf("%d ", value);
    }
}

void dequeue(CircularQueue* queue) {
    if (queue->rear == -1) {
        printf("UNDERFLOW\n");
    } else {
        if (queue->front == queue->rear) {
            queue->front = queue;
        }