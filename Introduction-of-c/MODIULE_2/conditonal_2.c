#include <stdio.h>
int main()
{
    int tk;
    scanf("%d", &tk);
    if (tk >= 5000){
        printf("cox bazar jabo\n");
        if(tk >= 10000){
            printf("saint martin jabo\n");
        }else{
            printf("ferot chole asbo\n");
        }
    }else{
        printf("jabona bazar");
    }
    return 0;
}