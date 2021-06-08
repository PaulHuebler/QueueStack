//Implementierung des Datentyps Stack mittels einer LinkedList.

#include <stdlib.h>
#include <limits.h>

#include "stack.h"

//Struktur zum Speichern der Elemente des Stacks in der LL.
struct SNode {
    struct SNode* next;
    int data;
};

 //Erstellt eine neue Node des Stacks / der LL.
struct SNode* newSNode(int data) {

    struct SNode* sN = (struct SNode*)malloc(sizeof(struct SNode));
    sN->data = data;
    sN->next = NULL;

    return sN;
}

//Prüft, ob der Stack leer ist. top = oberstes Element / oberste SNode.
int isStackEmpty(struct SNode* top) {

    return !top;
}

//Hinzufügen eines Elements zum Stack an oberster Stelle.
void push(struct SNode** top, int data) {

    struct SNode* s = newSNode(data);

    s->next = *top;
    *top = s;
}

//Entfernen und Zurückgeben des Elements an oberster Stelle im Stack.
int pop(struct SNode** top) {

    if (isStackEmpty(*top)) {

        return INT_MIN;
    }

    struct SNode* sN = *top;
    *top = (*top)->next;
    int data = sN->data;

    free(sN);
 
    return data;
}

//Zurückgeben des Elements an oberster Stelle im Stack.
int top(struct SNode* top) {

    if (isStackEmpty(top)) {
        
        return INT_MIN;
    }

    return top->data;
}
