#include <stdio.h>

int fun(int m, int a, int b, int c){
    if(a==0|| b==0|| c==0){
        if(a==0) return b*c;
        if(b==0) return a*c;
        if(c==0) return a*b;
    }
    if(m%a==0 && m%b==0 && m%c==0){
        return m/(a*b*c);
    }
    return -1;
}
     
int main()
{
    int n;
    scanf("%d", &n);

    while(n--){
        int m,a,b,c;
        scanf("%d %d %d %d", &m, &a, &b, &c);
        int miss=fun(m,a,b,c);
        printf("%d\n", miss);
    }

    return 0;
}