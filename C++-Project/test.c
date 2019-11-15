#include <stdio.h>
#include <stdlib.h>


int main() {
    #ifdef __MINGW_GCC_VERSION
    printf("GNU Mingw GCC version is : %d\n", __MINGW_GCC_VERSION);
    #endif

    #ifdef __clang__
    printf("LLVM and Clang version is : %d %d\n", __llvm__, __clang__ );
    #endif
    
    int number = 666;
    char* string = "ads8f4sdfg15fsdg15re1g5sdf1";

    printf("hello world: %d %s\n", number, string);
    printf("Pointer size is %d, Double size is %d, Long size is %d, Long long size is %d\n", sizeof(void*), sizeof(double), sizeof(long), sizeof(long long));

    int input = -1;
    scanf("%d", &input);
    printf("%d", input);
    return 0;

}