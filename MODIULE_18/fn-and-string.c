#include <stdio.h>
#include <string.h>

void fun(char ar[]){
    printf("%d", strlen(ar));
    return ar;
}

int main()
{
    char ar[20]="hello world";
    fun(ar);
    return 0;
}