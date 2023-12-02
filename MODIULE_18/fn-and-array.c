#include <stdio.h>

int main()
{
    int ar[5]={1,2,3,4,5};
    int sz=sizeof(ar)/sizeof(int);
    printf("%d",sz);
    return 0;
}