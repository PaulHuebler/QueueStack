#ifndef STACK_H_
#define STACK_H_

typedef struct {
    struct SNode* next;
    char data;
} SNode;

struct SNode* newSNode(char);

int isStackEmpty(struct SNode*);

void push(struct SNode**, char);

char pop(struct SNode**);

char top(struct SNode*);

#endif