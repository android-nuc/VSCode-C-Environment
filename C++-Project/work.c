#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    puts("\nDestroy tree\n");
    LinkedBinaryTree_Destroy(tree);
    // printf("\n %s \n", "Now Create a tree by using PreOrder ABCDEF and MidOrder CBAEDF");
    // char createTreeDemo1PreInput[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    // char createTreeDemo1MiddleInput[] = {'C', 'B', 'A', 'E', 'D', 'F'};
    
    char* testPreCreate = "124##57##8##3#6##";
    printf("\n Now Create a tree by using Preorder: %s", testPreCreate);
    LinkedBinaryTree* createTreeDemo1 = LinkedBinaryTree_CreateByPreOrderCharSequence(testPreCreate, strlen(testPreCreate), '#');
    printf("\n %s ", "Created tree Pre order traversal test: ");
    LinkedBinaryTree_PreOrderTraversal(createTreeDemo1, printChar);
    printf("\n %s ", "Created tree Last order traversal test: ");
    LinkedBinaryTree_LastOrderTraversal(createTreeDemo1, printChar);
    return 0;
}
