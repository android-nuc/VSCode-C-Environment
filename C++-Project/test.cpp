#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    int number = 100;
    string test = "hello world!";
    cout << test << endl;
    cout << number;
    MessageBox(NULL,TEXT("消息"),TEXT("Title标题"),0);
}