#include <stdio.h>
#include <stdlib.h>


int main() {
    printf("GNU version is : %d\n", __MINGW_GCC_VERSION);
    
    int number = 666;
    char* string = "ads8f4sdfg15fsdg15re1g5sdf1";

    printf("hello world: %d %s\n", number, string);

    int input = -1;
    scanf("%d", &input);
    printf("%d", input);
    return 0;

}