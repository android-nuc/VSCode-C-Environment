#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("%s%s\n", "中文字符串，这段话", "没有乱码");
    printf("%s\n", "注意你不能用中文文件名，这是 GCC 的 Bug，解决方法是换用其他编译器，比如 Clang");
    printf("%s\n", "C++-Projects 具有两个编译(调试)选项。 Launch C++ 为使用 C++ 编译器编译，Launch C 为使用 C 编译器编译");
    return 0;
}