#ifndef __IncludeGuard_ArrayUtils
#define __IncludeGuard_ArrayUtils
#include <stdbool.h>
//#include "../AnyType.h"
typedef short int ErrorCode;

ErrorCode IntArraySort_ShellSort(int* array, int length) {
    int temp = 0;

    for (int d = length / 2; d >= 1; d = d / 2) {
        for (int i = d - 1; i < length; i += d) {
            if (array[i] < array[i - d]) {
                temp = array[i];

                for (int j = i - d; j >= 0 && array[j] > array[j + d]; j -= d) {
                    int temp2 = array[j + d];
                    array[j + d] = array[j];
                    array[j] = temp;
                }
            }
        }
    }

    return 0;
}

void __IntArrayUtil_ArrangeHeap(int* array, int beginPosition, int endPosition) {
    int temp = 0;
    int root = beginPosition;
    
    while (root <= endPosition / 2) {
        int leftChild = root + 1;
        
        if (array[leftChild] > array[root]) {
            temp = array[root];
            array[root] = array[leftChild];
            array[leftChild] = root;
        }

        root *= 2;
    }
}

ErrorCode IntArrayUtil_ConvertToHeap(int* array, int beginPosition, int endPosition) {
    for (int i = 0; i < count; i++) {
        
    }
    return 0;
}

ErrorCode IntArraySort_HeapSort(int* array, int length) {
    return 0; 
}

#endif

int main() {
    int array[] = {9,5,1,6,1,4,3,888,85,6,44,5,151,5,15};
    IntArraySort_ShellSort(array, sizeof(array) / sizeof(int));
    return 0;
}