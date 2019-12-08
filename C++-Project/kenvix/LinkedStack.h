#ifndef __IncludeGuard_LinkedStackElement
#include "impl/LinkedStack.c"
#endif

LinkedStack* LinkedStack_New();
void LinkedStack_Destroy(LinkedStack* stack);
LinkedStackElement* LinkedStack_Push(LinkedStack* stack, GenericType data);
GenericType LinkedStack_Pop(LinkedStack* stack);
GenericType LinkedStack_GetTopData(LinkedStack* stack);
void LinkedStack_SetTopData(LinkedStack* stack, GenericType data);
void LinkedStack_Traversal(LinkedStack* stack, void (*callback)(GenericType data));
void LinkedStack_TraversalElements(LinkedStack* stack, void (*callback)(LinkedStackElement* data));