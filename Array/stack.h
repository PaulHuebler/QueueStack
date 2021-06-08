#ifndef STACK_H_
#define STACK_H_

typedef struct {
    int* array;
    unsigned int max;
    int top;
} Stack;

struct Stack* createStack(unsigned int);

int isStackEmpty(struct Stack*);

int isStackFull(struct Stack*);

int push(struct Stack*, int);

int pop(struct Stack*);

int top(struct Stack*);

#endif