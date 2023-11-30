#include <stdio.h>
int main()
{
    double x=5.25;
    double * ptr = &x;
    double * ptr2 = ptr;
    *ptr2 = 10.20;
    printf("x er value: %0.2lf\n", x);
    printf("x er value: %0.2lf\n", *ptr) ;
    return 0;
}