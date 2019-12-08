#ifndef __IncludeGuard_LinkedList
#define __IncludeGuard_LinkedList

#include <stddef.h>
#include <stdlib.h>
#include "../AnyType.h"
#define $(rt,fb) ({ \
	rt this fb;	\
	this;	\
})

#define Type(t) typeof(({t _t;_t;}))
#define FType(rt,fp) typeof(({rt (*_this)fp;_this;}))
#define Consumer(t) FType(void,(t))

typedef struct LinkedListUnit {
    struct LinkedListUnit* next;
    GenericType data;
} LinkedListUnit;


typedef struct LinkedList {
    LinkedListUnit* head;
    LinkedListUnit* foot;
    size count;
} LinkedList;

LinkedList* LinkedList_New() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->count = 0;
    list->head = NULL;
    list->foot = NULL;
    return list;
}

LinkedListUnit* LinkedList_NewUnit(GenericType data) {
    LinkedListUnit* unit = (LinkedListUnit*) malloc(sizeof(LinkedListUnit));
    unit->data = data;
    unit->next = NULL;
    return unit;
}

LinkedListUnit* LinkedList_Add(LinkedList* list, GenericType data) {
    LinkedListUnit* unit = LinkedList_NewUnit(data);

    if (list->head == NULL || list->foot == NULL) {
        list->head = unit;
        list->foot = unit;
    } else {
        list->foot->next = unit;
        list->foot = unit;
    }

    list->count++;
}

LinkedListUnit* LinkedList_GetUnit(LinkedList* list, size offset) {
    LinkedListUnit* position = list->head;

    for (size i = 0; i < offset; i++)
        position = position->next;

    return position;
}

LinkedListUnit* LinkedList_InsertAfter(LinkedList* list, GenericType data, size offset) {
    if (offset >= list->count) {
        LinkedList_Add(list, data);
    } else {
        LinkedListUnit* unit = LinkedList_NewUnit(data);
        LinkedListUnit* position = LinkedList_GetUnit(list, offset);

        unit->next = position->next;
        position->next = unit;

        list->count++;
    }
}

void LinkedList_Remove(LinkedList* list, size offset) {
    if (list->count > 0) {
        if (offset <= 0) {
            list->head = list->head->next;
            free(list->head);
        } else {
            LinkedListUnit* prevUnit = LinkedList_GetUnit(list, offset - 1);
            LinkedListUnit* targetUnit = prevUnit->next;
            prevUnit->next = targetUnit->next;
            
            if (targetUnit == list->foot)
                list->foot = prevUnit;

            free(targetUnit);
        }
    } else {
        free(list->head);
        list->head = NULL;
        list->foot = NULL;
    }

    list->count--;
}

void LinkedList_TraversalUnits(LinkedList* list, void (*callback)(LinkedListUnit* unit, size order, GenericType env), GenericType env) {
    LinkedListUnit* unit = list->head;
    size order = 0;

    while (unit != NULL) {
        callback(unit, order, env);
        unit = unit->next;
        order++;
    }
}

void LinkedList_Traversal(LinkedList* list, void (*callback)(GenericType data, size order, GenericType env), GenericType env) {
    LinkedListUnit* unit = list->head;
    size order = 0;

    while (unit != NULL) {
        callback(unit->data, order, env);
        unit = unit->next;
        order++;
    }
}

void LinkedList_Destroy(LinkedList* list) {
    LinkedList_TraversalUnits(list, free, getNull());
    free(list);
}

GenericType LinkedList_Get(LinkedList* list, size offset) {
    return LinkedList_GetUnit(list, offset)->data;
}

bool LinkedList_IsEmpty(LinkedList* list) {
    return list->count == 0;
}

size LinkedList_GetCount(LinkedList* list) {
    return list->count;
}

#endif