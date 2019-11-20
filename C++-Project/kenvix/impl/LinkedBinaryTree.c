#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#ifndef __IncludeGuard_LinkedBinaryTree
#define __IncludeGuard_LinkedBinaryTree
#include "../LinkedStack.h"

typedef struct LinkedBinaryTree {
    GenericType data;
    struct LinkedBinaryTree* left;
    struct LinkedBinaryTree* right;
} LinkedBinaryTree;

LinkedBinaryTree* LinkedBinaryTree_New(GenericType data, LinkedBinaryTree* left, LinkedBinaryTree* right) {
    LinkedBinaryTree* tree = malloc(sizeof(LinkedBinaryTree) + sizeof(data));
    tree->data = data;
    tree->left = left;
    tree->right = right;
}

void LinkedBinaryTree_PreOrderTraversal(LinkedBinaryTree* tree, void (*callback)(GenericType data)) {
    LinkedStack* stack = LinkedStack_New();
    LinkedBinaryTree* element = tree;

    while (!LinkedStack_IsEmpty(stack) || element != NULL) {
        if (element != NULL) {
            callback(element->data);
            LinkedStack_Push(stack, castPointerToGenericType(element)); //set rollback point
            element = element->left; //view left node
        } else {
            element = ((LinkedBinaryTree*) LinkedStack_Pop(stack).pointer)->right;
        }
    }

    LinkedStack_Destroy(stack);
}

void LinkedBinaryTree_MiddleOrderTraversal(LinkedBinaryTree* tree, void (*callback)(GenericType data)) {
    LinkedStack* stack = LinkedStack_New();
    LinkedBinaryTree* element = tree;

    do {
        if (element != NULL) {
            LinkedStack_Push(stack, castPointerToGenericType(element)); //set rollback point
            element = element->left; //view left node
        } else {
            LinkedBinaryTree* lastElement = LinkedStack_Pop(stack).pointer;
            callback(lastElement->data);
            element = lastElement->right;
        }
    } while (!LinkedStack_IsEmpty(stack) || element != NULL);

    LinkedStack_Destroy(stack);
}

void LinkedBinaryTree_LastOrderTraversal(LinkedBinaryTree* tree, void (*callback)(GenericType data)) {
    LinkedStack* stack = LinkedStack_New();
    LinkedStack* flagStack = LinkedStack_New();
    LinkedBinaryTree* element = tree;

     do {
        if (element != NULL) {
            LinkedStack_Push(stack, castPointerToGenericType(element)); //set rollback point
            LinkedStack_Push(flagStack, castBoolToGenericType(false));
            element = element->left; //view left node
        } else {
            LinkedBinaryTree* lastElement = LinkedStack_GetTopData(stack).pointer;
            int lastElementFlag = LinkedStack_GetTopData(flagStack).integer;
            
            if (lastElementFlag == true) {
                callback(lastElement->data);
                LinkedStack_Pop(stack);
                LinkedStack_Pop(flagStack);
            } else {
                LinkedStack_SetTopData(flagStack, (GenericType) true);
                element = lastElement->right;
            }
        }
    } while (!LinkedStack_IsEmpty(stack) || element != NULL);

    LinkedStack_Destroy(stack);
    LinkedStack_Destroy(flagStack);
}

LinkedBinaryTree* LinkedBinaryTree_CreateByPreAndMiddleOrder(GenericType preOrderArray, GenericType middleOrderArray, int length, int unitSize) {
    
}

LinkedBinaryTree* LinkedBinaryTree_CreateByLastAndMiddleOrder(GenericType lastOrderArrayIn, GenericType middleOrderArrayIn, int length, int unitSize) {
    void* lastOrderArray = lastOrderArrayIn.pointer;
    void* middleOrderArray = middleOrderArrayIn.pointer;
    int num = length / unitSize;
    LinkedBinaryTree* tree = LinkedBinaryTree_New(dataAt(lastOrderArray, unitSize, num-1), NULL, NULL);

    
}

LinkedBinaryTree* LinkedBinaryTree_CreateByPreOrderCharSequence(char* preOrderArray, size length, char emptyChar) {
    char state = 'l'; //f l r
    LinkedBinaryTree* rootTree = LinkedBinaryTree_New(castCharToGenericType(preOrderArray[0]), NULL, NULL);
    LinkedBinaryTree* currentTree = rootTree;
    LinkedStack* stack = LinkedStack_New();
    size i = 1;

    while (i < length) {
        char data = preOrderArray[i];
        
        switch (state) {
            case 'l':
                if (data != emptyChar) {
                    LinkedBinaryTree* newTree = LinkedBinaryTree_New(castCharToGenericType(data), NULL, NULL);
                    currentTree->left = newTree;
                    currentTree = newTree;
                    LinkedStack_Push(stack, castPointerToGenericType(currentTree));
                    i++;
                    //putc(data, stderr);
                } else {
                    state = 'r';
                }
                break;

            case 'r':
                if (data != emptyChar) {
                    currentTree = LinkedStack_Pop(stack).pointer;
                    LinkedBinaryTree* newTree = LinkedBinaryTree_New(castCharToGenericType(data), NULL, NULL);
                    currentTree->right = newTree;
                    i++;
                    state = 'l';
                    //putc(data, stderr);
                } else {
                    state = 'l';
                    i++;
                }
                break;
        }
    }

    LinkedStack_Destroy(stack);
    return rootTree;
}

LinkedBinaryTree* LinkedBinaryTree_CreateByLastAndMiddleOrderCharSequence(char* lastOrderArray, char* middleOrderArray, int length) {
    
}

LinkedBinaryTree* LinkedBinaryTree_Destroy(LinkedBinaryTree* tree) {
    LinkedStack* stack = LinkedStack_New();
    LinkedStack* flagStack = LinkedStack_New();
    LinkedBinaryTree* element = tree;

     do {
        if (element != NULL) {
            LinkedStack_Push(stack, castPointerToGenericType(element)); //set rollback point
            LinkedStack_Push(flagStack, castBoolToGenericType(false));
            element = element->left; //view left node
        } else {
            LinkedBinaryTree* lastElement = LinkedStack_GetTopData(stack).pointer;
            int lastElementFlag = LinkedStack_GetTopData(flagStack).integer;
            
            if (lastElementFlag == true) {
                LinkedStack_Pop(stack);
                LinkedStack_Pop(flagStack);
                free(lastElement);
            } else {
                LinkedStack_SetTopData(flagStack, (GenericType) true);
                element = lastElement->right;
            }
        }
    } while (!LinkedStack_IsEmpty(stack) || element != NULL);

    LinkedStack_Destroy(stack);
    LinkedStack_Destroy(flagStack);
}

LinkedBinaryTree* LinkedBinaryTree_GetDemoTree() {
    return LinkedBinaryTree_New(castCharToGenericType('A'), 
        LinkedBinaryTree_New(castCharToGenericType('B'), 
            LinkedBinaryTree_New(castCharToGenericType('D'),
                LinkedBinaryTree_New(castCharToGenericType('H'),
                    LinkedBinaryTree_New(castCharToGenericType('K'), NULL, NULL),
                    NULL
                ),
                NULL
            ),
            LinkedBinaryTree_New(castCharToGenericType('E'),
                NULL,
                LinkedBinaryTree_New(castCharToGenericType('I'), NULL, NULL)
            )
        ), 
        LinkedBinaryTree_New(castCharToGenericType('C'), 
            LinkedBinaryTree_New(castCharToGenericType('F'), NULL, NULL),
            LinkedBinaryTree_New(castCharToGenericType('G'),
                LinkedBinaryTree_New(castCharToGenericType('J'), NULL, NULL),
                NULL
            )
        )
    );
}

#endif