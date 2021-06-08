#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct {
    int front, rear, size;
    unsigned int capacity;
    int* array;
} Queue;

struct Queue* createQueue(unsigned int);

int isQueueEmpty(struct Queue*);

int isQueueFull(struct Queue*);

int enqueue(struct Queue*, int);

int dequeue(struct Queue*);

int front(struct Queue*);

int rear(struct Queue*);

#endif