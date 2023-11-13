#include <stdio.h>
int main()
{
    int a[5];
    int sz = sizeof(a)/sizeof(char);
    // int sz=sizeof(a)/sizeof(int);
    printf("%d",sizeof(a));
    // printf("%d",sizeof(long long int));
    return 0;
}