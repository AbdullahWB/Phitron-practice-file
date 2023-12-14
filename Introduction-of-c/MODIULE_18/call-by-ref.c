#include <stdio.h>

int fun(int *p){
    printf("x er value = %p\n", p);
    printf("main x er value = %d\n", *p);
    *p=500;
    printf("main x er value = %d\n", *p);
}

int main()
{
    int x=100;
    printf("x er address = %p\n", &x);
    fun(&x);
    printf("x er main value = %d\n", x);
    return 0;
}