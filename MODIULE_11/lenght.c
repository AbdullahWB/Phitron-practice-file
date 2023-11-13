#include <stdio.h>
int main()
{
    char a[100];
    scanf("%s", a);
    int count = 0;
    // for(int i=0; a[i]!='\0'; i++){
    //     count++;
    // }

    int i=0;
    while(a[i]!='\0'){
        count++;
        i++;
    }

    printf("%d\n", count);
    return 0;
}