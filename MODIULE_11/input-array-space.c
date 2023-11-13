#include <stdio.h>
#include <string.h>
int main()
{
    char a[100];
    // gets(a);
    fgets(a, 18, stdin);
    a[10] = '\0';
    printf("%s", a);
    return 0;
}