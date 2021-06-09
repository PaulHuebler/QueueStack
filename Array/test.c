//Verwendung von Queue und Stack. (Array)

#include <stdio.h>
#include <time.h>

#include "stack.h"
#include "queue.h"

int main()
{
    struct Stack* stack = createStack(10);
    
    clock_t start_time1 = clock();

    for(int i = 0; i < 50000; i++) {

        push(stack, i);
        push(stack, i+1);
        top(stack);
        pop(stack);
        pop(stack);
    }

    double elapsed_time1 = (double)(clock() - start_time1) / CLOCKS_PER_SEC;

    printf("---------------------------------\n");

    struct Queue* queue = createQueue(10);
    
    clock_t start_time2 = clock();
    
    for(int i = 0; i < 50000; i++) {

        enqueue(queue, i);
        enqueue(queue, i+1);
        front(queue);
        dequeue(queue);
        dequeue(queue);
    }
    
    double elapsed_time2 = (double)(clock() - start_time2) / CLOCKS_PER_SEC;

    printf("Stack hat %f Sekunden gebraucht.\n", elapsed_time1);
    printf("Queue hat %f Sekunden gebraucht.\n", elapsed_time2);
 
    return 0;
}