#include <stdio.h>
int main()
{
    int tk;
    scanf("%d", &tk);
    if(tk >= 100)
    {
        printf("Burger Khabo");
    }else if(tk >= 50)
    {
        printf("Fuchka Khabo");
    }else if(tk >= 20)
    {
        printf("ice cream khabo");
    }else
    {
        printf("khabo na");
    }
    return 0;
}
