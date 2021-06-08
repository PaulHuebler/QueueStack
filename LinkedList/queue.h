#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct {
    struct QNode* next;
    int data;
} QNode;

typedef struct {
    struct QNode *front, *rear;
} Queue;

struct QNode* newQNode(int);

struct Queue* createQueue();

void enqueue(struct Queue*, int);

int dequeue(struct Queue*);

int front(struct Queue*);

int rear(struct Queue*);

#endif