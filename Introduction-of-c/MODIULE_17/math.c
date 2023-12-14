#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    double x, y;
    int i;
    scanf("%lf %lf %d", &x, &y, &i);
    int ans1=floor(x);
    int ans2=ceil(x);
    int ans3=round(x);
    int ans4=sqrt(x);
    int ans5=pow(x,y);
    int ans6=abs(i);
    printf("%d\n%d\n%d\n%d\n%d\n%d", ans1, ans2, ans3, ans4, ans5, ans6);
    return 0;
}