//Implementierung des Datentyps Stack mittels eines Arrays.

#include <stdlib.h>
#include <limits.h>

#include "stack.h"


struct Stack {
    int* array;             //Das Array, in dem die Daten gespeichert werden
    unsigned int max;       //Die Größe des Arrays
    int top;
};

//Erstellt einen neuen Stack.
struct Stack* createStack(unsigned int max) {

    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->array = (int*)malloc(s->max * sizeof(int));                  //Reservieren der Memory
    s->max = max;
    s->top = -1;

    return s;
}

//Prüft, ob der Stack leer ist.
int isStackEmpty(struct Stack* s) {

    return s->top == -1;
}

//Prüft, ob der Stack voll ist.
int isStackFull(struct Stack* s) {

    return s->top == s->max - 1;
}

//Hinzufügen eines Elements zum Stack an oberster Stelle.
int push(struct Stack* s, int element) {

    if (isStackFull(s)) {

        return INT_MIN;
    }

    s->top++;
    s->array[s->top] = element;

    return 0;
}
 
//Entfernen und Zurückgeben des Elements an oberster Stelle im Stack.
int pop(struct Stack* s) {

    if (isStackEmpty(s)) {

        return INT_MIN;
    }

    return s->array[s->top--];
}
 
//Zurückgeben des Elements an oberster Stelle im Stack.
int top(struct Stack* s) {

    if (isStackEmpty(s)) {

        return INT_MIN;
    }
    
    return s->array[s->top];
}
