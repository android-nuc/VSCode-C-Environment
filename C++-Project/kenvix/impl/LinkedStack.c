#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#ifndef __IncludeGuard_LinkedStackElement
#define __IncludeGuard_LinkedStackElement
#include "../AnyType.h"

typedef struct LinkedStackElement {
    GenericType data;
    struct LinkedStackElement* prev;
} LinkedStackElement;

typedef struct {
    LinkedStackElement* top;
    int length;
    int unitSize;
} LinkedStack;

LinkedStack* LinkedStack_NewSized(int unitSize) {
    LinkedStack* stack = malloc(sizeof(LinkedStack));
    stack->top = NULL;
    stack->length = 0;
    stack->unitSize = unitSize;
    return stack;
}

LinkedStack* LinkedStack_New() {
    return LinkedStack_NewSized(sizeof(GenericType));
}

LinkedStackElement* LinkedStack_Push(LinkedStack* stack, GenericType data) {
    LinkedStackElement* element = malloc(sizeof(LinkedStackElement*) + stack->unitSize);
    element->prev = stack->top;
    element->data = data;
    stack->top = element;
    stack->length++;
    return element;
}

bool LinkedStack_IsEmpty(LinkedStack* stack) {
    return stack->length == 0;
}

GenericType LinkedStack_GetTopData(LinkedStack* stack) {
    return stack->top->data;
}

void LinkedStack_SetTopData(LinkedStack* stack, GenericType data) {
    stack->top->data = data;
}

GenericType LinkedStack_Pop(LinkedStack* stack) {
    LinkedStackElement* element = stack->top;
    GenericType data = element->data;
    stack->top = stack->top->prev;
    stack->length--;

    free(element);
    return data;
}

void LinkedStack_TraversalElements(LinkedStack* stack, void (*callback)(LinkedStackElement* data)) {
    LinkedStackElement* element = stack->top;
    
    while (element != NULL) {
        element = stack->top->prev;
        callback(element);
    }
}

void LinkedStack_Traversal(LinkedStack* stack, void (*callback)(GenericType data)) {
    LinkedStackElement* element = stack->top;
    
    while (element != NULL) {
        element = stack->top->prev;
        callback(element->data);
    }
}

void LinkedStack_Destroy(LinkedStack* stack) {
    LinkedStackElement* last = NULL;
    LinkedStackElement* current = stack->top;
    
    while (current != NULL) {
        last = current;
        current = last->prev;
        free(last);
    }
    
    free(stack);
}
#endif