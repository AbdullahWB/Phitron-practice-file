#include <stdio.h>
#include <string.h>
int main()
{
    char a[100], b[100];
    scanf("%s %s", a, b);
    // int i = 0;
    int v= strcmp(a, b);
    printf("%d", v);
    return 0;
}