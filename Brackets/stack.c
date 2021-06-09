//Implementierung des Datentyps Stack mittels einer LinkedList.

#include <stdlib.h>
#include <limits.h>

#include "stack.h"

//Struktur zum Speichern der Elemente des Stacks in der LL.
struct SNode {
    struct SNode* next;
    char data;
};

 //Erstellt eine neue Node des Stacks / der LL.
struct SNode* newSNode(char data) {

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
void push(struct SNode** top, char data) {

    struct SNode* s = newSNode(data);

    s->next = *top;
    *top = s;
}

//Entfernen und Zurückgeben des Elements an oberster Stelle im Stack.
char pop(struct SNode** top) {

    if (isStackEmpty(*top)) {

        return CHAR_MIN;
    }

    struct SNode* sN = *top;
    *top = (*top)->next;
    char data = sN->data;

    free(sN);
 
    return data;
}

//Zurückgeben des Elements an oberster Stelle im Stack.
char top(struct SNode* top) {

    if (isStackEmpty(top)) {
        
        return CHAR_MIN;
    }

    return top->data;
}
