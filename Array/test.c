//Verwendung von Queue und Stack. (Array)

#include <stdio.h>
#include "stack.h"
#include "queue.h"

int main()
{
    struct Stack* stack = createStack(10);
 
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Oberstes Element im Stack : %d\n", top(stack));

    push(stack, 4);
 
    printf("Vom Stack entfernt: %d\n", pop(stack));

    printf("---------------------------------\n");

    struct Queue* queue = createQueue(10);
 
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Vorderes Element in der Queue: %d\n", front(queue));

    printf("Hinteres Element in der Queue: %d\n", rear(queue));
 
    printf("Aus Queue entfernt: %d\n", dequeue(queue));
 
    return 0;
}