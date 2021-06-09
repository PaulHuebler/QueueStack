//Testen eines arithmetischen Ausdrucks auf ausbalancierte Klammern

#include <stdio.h>

#include "stack.h"

// Prüft zwei chars, ob diese ein Klammerpaar bilden - () [] {}
int checkMatch(char c1, char c2) {

    if (c1 == '(' && c2 == ')') {

        return 1;
    }
    else if (c1 == '[' && c2 == ']') {

        return 1;
    }
    else if (c1 == '{' && c2 == '}') {

        return 1;
    }
    else {

        return 0;
    }
}

// Nimmt einen Ausdruck (String) und prüft diesen, ob er ausbalancierte Klammern enthält
int checkBalance(char eingabe[]) {
    
    struct SNode* stack = NULL;
 
    // String wird durchlaufen
    int i = 0;
    while (eingabe[i]) {

        // Wenn der char eine geöffnete Klammer ist: push()
        if (eingabe[i] == '(' || eingabe[i] == '[' || eingabe[i] == '{') {

            push(&stack, eingabe[i]);
        }
 
        if (eingabe[i] == ')' || eingabe[i] == ']' || eingabe[i] == '}') {
 
            // Wenn der char eine geschlossene Klammer ist und der Stack leer: Ausdruck nicht ausbalanciert
            if (isStackEmpty(stack)) {

                return 2;
            }

            // Wenn der char eine geschlossene Klammer ist: pop() und checken, ob gepopptes Element und aktueller char ein Paar bilden
            // Falls nicht: Ausdruck nicht ausbalanciert
            else if (!checkMatch(pop(&stack), eingabe[i])) {

                return 3;
            }
        }

        i++;
    }
 
    // Wenn der Stack am Ende nicht leer ist (geöffnete Klammern übrig): Ausdruck nicht ausbalanciert
    if (isStackEmpty(stack)) {

        return 1;
    }

    else {

        return 4;
    }
}

// Eingabe des Ausdrucks (In Anführungszeichen)
int main(int argc, char *argv[]) {

    if (argc == 2) {
        
        // Aufruf der Funktion und Auswertung des Rückgabewertes.
        switch (checkBalance(argv[1])) {

            case 1:

                printf("Der Ausdruck '%s' ist ausbalanciert. \n", argv[1]);
                break;

            case 2:

                printf("Der Ausdruck '%s' ist nicht ausbalanciert. Es gibt mehr geschlossene Klammern als geöffnete. \n", argv[1]);
                break;

            case 3:

                printf("Der Ausdruck '%s' ist nicht ausbalanciert. Es gibt Überschneidungen verschiedener Arten von Klammern. \n", argv[1]);
                break;

            case 4:

                printf("Der Ausdruck '%s' ist nicht ausbalanciert. Es gibt mehr geöffnete Klammern als geschlossene. \n", argv[1]);
                break;
        }
            
    }
    else {

        printf("Bitte genau ein Argument als zu prüfenden Ausdruck angeben.\n");
    }
    
    return 0;
}