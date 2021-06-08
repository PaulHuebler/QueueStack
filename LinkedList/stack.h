#ifndef STACK_H_
#define STACK_H_

typedef struct {
    struct SNode* next;
    int data;
} SNode;

struct SNode* newSNode(int);

int isStackEmpty(struct SNode*);

void push(struct SNode**, int);

int pop(struct SNode**);

int top(struct SNode*);

#endif