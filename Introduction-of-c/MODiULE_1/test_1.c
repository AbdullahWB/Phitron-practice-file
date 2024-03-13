// #include <stdio.h>
// int main()
// {
//     float a,b,c;
//     a=1;
//     b=2;
//     c=(a/b);
//     float i,h,s;
//     i=1;
//     h=2;
//     s=c*i*h;
//     printf("%f\n",s);
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     float a,b,h,c;
//     a=1;
//     b=2;
//     h=3;
//     c=(a/b)*a*h;
//     printf("%.2f\n",c);
//     return 0;
// }

#include <stdio.h>
int main()
{
    float a, b, h;
    scanf("%f,%f,%f", &a, &b, &h);
    float ans = (1.0 / 2) * (a + b) * h;
    printf("%.2f\n", ans);
    return 0;
}