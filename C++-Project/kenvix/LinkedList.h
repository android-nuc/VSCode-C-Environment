#ifndef __IncludeGuard_LinkedList
#include "impl/LinkedList.c"
#include <stdbool.h>
#endif

LinkedList* LinkedList_New();
void LinkedList_Traversal(LinkedList* list, void (*callback)(GenericType data, size order, GenericType env), GenericType env);
void LinkedList_TraversalUnits(LinkedList* list, void (*callback)(LinkedListUnit* unit, size order, GenericType env), GenericType env);
void LinkedList_Destroy(LinkedList* list);
LinkedListUnit* LinkedList_NewUnit(GenericType data);
LinkedListUnit* LinkedList_Add(LinkedList* list, GenericType data);
LinkedListUnit* LinkedList_InsertAfter(LinkedList* list, GenericType data, size offset);
//LinkedListUnit* LinkedList_InsertHead(LinkedList* list, GenericType data);
void LinkedList_Remove(LinkedList* list, size offset);
bool LinkedList_IsEmpty(LinkedList* list);
size LinkedList_GetCount(LinkedList* list);
GenericType LinkedList_Get(LinkedList* list, size offset);
LinkedListUnit* LinkedList_GetUnit(LinkedList* list, size offset);