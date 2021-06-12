//Implementierung des Datentyps Queue mittels eines Arrays.

#include <stdlib.h>
#include <limits.h>

#include "queue.h"
 

struct Queue {
    int* array;             //Das Array, in dem die Daten gespeichert werden
    unsigned int max;       //Die Größe des Arrays
    int size, front, rear;  
};
 
//Erstellt eine neue Queue.
struct Queue* createQueue(unsigned int max) {

    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->max = max;
    q->array = (int*)malloc(q->max * sizeof(int));                  //Reservieren der Memory
    q->size = 0;
    q->front = 0;
    q->rear = max - 1;                                              //Das Ende der Queue ist das Element mit dem höchsten Index

    return q;
}

//Prüft, ob die Queue leer ist.
int isQueueEmpty(struct Queue* q) {

    return (q->size == 0);
}

//Prüft, ob die Queue voll ist.
int isQueueFull(struct Queue* q) {

    return (q->size == q->max);
}
 
//Hinzufügen eines Elements zur Queue an hinterster Stelle.
int enqueue(struct Queue* q, int element) {

    if (isQueueFull(q)) {

        return INT_MIN;
    }

    q->rear = (q->rear + 1) % q->max;                           //Circular Queue: Wenn ein Ende des Arrays erreicht wird, setzt am anderen Ende fort.
    q->array[q->rear] = element;
    q->size++;

    return 0;
}
 
//Entfernen und Zurückgeben des Elements an vorderster Stelle in der Queue.
int dequeue(struct Queue* q) {

    if (isQueueEmpty(q)) {

        return INT_MIN;
    }

    int element = q->array[q->front];
    q->front = (q->front + 1) % q->max;     //Circular Queue: Wenn ein Ende des Arrays erreicht wird, setzt am anderen Ende fort.
    q->size--;

    return element;
}

//Zurückgeben des Elements an vorderster Stelle in der Queue.
int front(struct Queue* q) {

    if (isQueueEmpty(q)) {

        return INT_MIN;
    }

    return q->array[q->front];
}
 
//Zurückgeben des Elements an hinterster Stelle in der Queue.
int rear(struct Queue* q) {

    if (isQueueEmpty(q)) {

        return INT_MIN;
    }

    return q->array[q->rear];
}