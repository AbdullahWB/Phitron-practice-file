#include <stdio.h>

void fun(){
    printf("fun");
    fun();
}

int main()
{
    fun();
    return 0;
}