//Verwendung von Queue und Stack. (LL)

#include <stdio.h>

#include "stack.h"
#include "queue.h"

int main()
{
    struct SNode* root = NULL;
 
    push(&root, 1);
    push(&root, 2);
    push(&root, 3);

    printf("Oberstes Element im Stack : %d\n", top(root));
    
    push(&root, 4);

    printf("Vom Stack entfernt: %d\n", pop(&root));
 
    printf("---------------------------------\n");
 
    struct Queue* q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printf("Vorderes Element in der Queue: %d\n", front(q));
    printf("Hinteres Element in der Queue: %d\n", rear(q));

    printf("Aus Queue entfernt: %d\n", dequeue(q));

    return 0;
}
