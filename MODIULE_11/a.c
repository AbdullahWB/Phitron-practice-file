#include <stdio.h>
#include <string.h>
int main()
{
    char s[1001],t[1001];
    scanf("%s %s", s,t);
    int ss = strlen(s);
    int st = strlen(t);
    printf("%d %d\n",ss,st);
    printf("%s %s\n",s,t);
    return 0;
}