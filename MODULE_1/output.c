#include <stdio.h>
int main()
{
    int i = 10, j = 20;
    char c = 'a';
    float f = 1.0;
    scanf("%d %d %c %f", &i, &j, &c, &f);
    printf("%d %d %c %0.2f", i, j, c, f);
    return 0;
}