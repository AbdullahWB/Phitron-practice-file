#include <stdio.h>
void fun(int x){
    x=200;
}
int main()
{
    int x=10;
    fun(x);
    printf("x er value: %d\n", x);
    return 0;
}