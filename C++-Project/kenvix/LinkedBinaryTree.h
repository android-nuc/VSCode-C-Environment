#ifndef __IncludeGuard_LinkedBinaryTree
#include "impl/LinkedBinaryTree.c"
#endif

LinkedBinaryTree* LinkedBinaryTree_New(GenericType data, LinkedBinaryTree* left, LinkedBinaryTree* right);
LinkedBinaryTree* LinkedBinaryTree_Destroy(LinkedBinaryTree* tree);
void LinkedBinaryTree_PreOrderTraversal(LinkedBinaryTree* tree, void (*callback)(GenericType data));
void LinkedBinaryTree_MiddleOrderTraversal(LinkedBinaryTree* tree, void (*callback)(GenericType data));
void LinkedBinaryTree_LastOrderTraversal(LinkedBinaryTree* tree, void (*callback)(GenericType data));
LinkedBinaryTree* LinkedBinaryTree_GetDemoTree();
LinkedBinaryTree* LinkedBinaryTree_CreateByPreAndMiddleOrder(GenericType preOrderArray, GenericType middleOrderArray, int length, int unitSize);
LinkedBinaryTree* LinkedBinaryTree_CreateByLastAndMiddleOrder(GenericType lastOrderArray, GenericType middleOrderArray, int length, int unitSize);
LinkedBinaryTree* LinkedBinaryTree_CreateByPreOrderCharSequence(char* preOrderArray, size length, char emptyChar);
LinkedBinaryTree* LinkedBinaryTree_CreateByLastAndMiddleOrderCharSequence(char* lastOrderArray, char* middleOrderArray, int length);