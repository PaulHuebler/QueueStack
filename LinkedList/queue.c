//Implementierung des Datentyps Queue mittels einer LinkedList.

#include <stdlib.h>
#include <limits.h>

#include "queue.h"
  
//Struktur zum Speichern der Elemente der Queue in der LL.
struct QNode {
    struct QNode* next;
    int data;
};
  
//Struktur zum Speichern der eigentlichen Queue.
struct Queue {
    struct QNode *front, *rear;
};
  
 //Erstellt eine neue Node der Queue / der LL.
struct QNode* newQNode(int data) {

    struct QNode* qN = (struct QNode*)malloc(sizeof(struct QNode));

    qN->next = NULL;
    qN->data = data;

    return qN;
}
  
//Erstellt eine neue Queue.
struct Queue* createQueue() {

    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));

    q->front = NULL;
    q->rear = NULL;

    return q;
}
  
//Hinzufügen eines Elements zur Queue an hinterster Stelle.
void enqueue(struct Queue* q, int data) {

    struct QNode* qN = newQNode(data);
  
    //Falls die Queue leer ist, wird die neue Node sowohl front als auch rear.
    if (q->rear == NULL) {

        q->front = q->rear = qN;
        return;
    }
    
    //Anhängen der neuen QNode an die Queue
    q->rear->next = qN;
    q->rear = qN;
}
  
//Entfernen und Zurückgeben des Elements an vorderster Stelle in der Queue.
int dequeue(struct Queue* q) {

    if (q->front == NULL)
        return INT_MIN;
  
    //Zwischenspeichern des vorderen Elements zur Zurückgabe.
    struct QNode* qN = q->front;
    
    //"Nachrücken" der nächsten Node
    q->front = q->front->next;
  
    //Sollte front NULL werden, dann wird auch rear auf NULL gesetzt, weil die Queue dann leer ist.
    if (q->front == NULL) {

        q->rear = NULL;
    }

    int data = qN->data;

    free(qN);

    return data;
}

//Zurückgeben des Elements an vorderster Stelle in der Queue.
int front(struct Queue* q) {

    return q->front->data;
}

//Zurückgeben des Elements an hinterster Stelle in der Queue.
int rear(struct Queue* q) {

    return q->rear->data;
}
