#ifndef __IncludeGuard_ArrayUtils
#define __IncludeGuard_ArrayUtils
#include <stdbool.h>
//#include "../AnyType.h"
typedef short int ErrorCode;

void IntArraySort_ShellSort(int* array, int length) {
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
}

void _IntArrayUtil_ArrangeHeap(int* array, int beginPosition, int endPosition) {
    int temp = 0;
    int root = beginPosition;
    
    while (root <= endPosition / 2) {
        if (root == 0) break;
        int leftChild = 2 * root;
        
        //Left child key is $leftChild - 1
        if (array[leftChild - 1] > array[root - 1]) {
            temp = array[root - 1];
            array[root - 1] = array[leftChild - 1];
            array[leftChild - 1] = temp;
        }

        //Right child key is $leftChild
        if (array[leftChild] > array[root - 1]) {
            temp = array[root - 1];
            array[root - 1] = array[leftChild];
            array[leftChild] = temp;
        }

        root *= 2;
    }
}

void IntArrayUtil_ConvertToHeap(int* array, int beginPosition, int endPosition) {
    beginPosition++;

    for (int i = endPosition / 2; i >= beginPosition; i--) {
        _IntArrayUtil_ArrangeHeap(array, i, endPosition);
    }
}

void IntArraySort_HeapSort(int* array, int length) {
    int temp = 0;
    IntArrayUtil_ConvertToHeap(array, 0, length);
    
    for (int i = length - 1; i > 0; i--) {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        _IntArrayUtil_ArrangeHeap(array, 1, i - 1);
    }
    
}

#endif

int main() {
    int array[] = {9,5,1,6,1,4,3,888,85,6,44,5,151,5,15};
    IntArraySort_ShellSort(array, sizeof(array) / sizeof(int));

    int array2[] = {312,126,272,226,28,165,123,8,12};
    IntArraySort_HeapSort(array2, sizeof(array2) / sizeof(int));
    return 0;
}