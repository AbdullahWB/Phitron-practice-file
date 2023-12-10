#include <stdio.h>
#include <string.h>

int main()
{
    char a[1001];
    scanf("%s", &a);
    int i=0, j=strlen(a)-1;
    int flags = 1;
    while (i<j)
    {
        if(a[i]!=a[j]){
            flags=0;
        }
        i++;
        j--;
    }

    if(flags==1){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    
    return 0;
}