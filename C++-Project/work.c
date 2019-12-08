#include <stdio.h>
#include <stdlib.h>
#include "kenvix/containers.h"

typedef int DataType;

void printInt(GenericType data) {
    printf("%d ", data);
}

void printChar(GenericType data) {
    printf("%c ", data);
}

int main(int argc, char const *argv[]) {
    LinkedBinaryTree* tree = LinkedBinaryTree_GetDemoTree();
    printf("\n %s \n", "DemoTree Middle order traversal: ");
    LinkedBinaryTree_MiddleOrderTraversal(tree, printChar);
    printf("\n %s \n", "DemoTree Pre order traversal: ");
    LinkedBinaryTree_PreOrderTraversal(tree, printChar);
    printf("\n %s \n", "DemoTree Last order traversal: ");
    LinkedBinaryTree_LastOrderTraversal(tree, printChar);
    printf("\n %s \n", "Now Create a tree by using PreOrder ABCDEF and MidOrder CBAEDF");
    char createTreeDemo1PreInput[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    char createTreeDemo1MiddleInput[] = {'C', 'B', 'A', 'E', 'D', 'F'};
    LinkedBinaryTree* createTreeDemo1 = LinkedBinaryTree_CreateByPreAndMiddleOrder(castPointerToGenericType(createTreeDemo1PreInput),
             castPointerToGenericType(createTreeDemo1MiddleInput), sizeof(createTreeDemo1MiddleInput) / sizeof(char), sizeof(char));

    printf("\n %s \n", "Now Create a tree by using MidOrder ABCEFGHD and LastOrder ABFHGEDC");
    return 0;
}
