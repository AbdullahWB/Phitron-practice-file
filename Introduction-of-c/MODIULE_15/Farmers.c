#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int m1, m2, d;
        scanf("%d %d %d", &m1, &m2, &d);
        int manAndDay= m1*d;
        int totalMan= m1+m2;
        int count= manAndDay/totalMan;
        int extraDay= d-count;
        printf("%d\n", extraDay);
    }
    
    return 0;
}