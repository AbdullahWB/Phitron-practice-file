#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int zero=0, one=0, two=0, three=0;
    for(int i=0; i<n; i++){
        // printf("%d", a[i]);
        if(a[i]==0){
            zero++;
        }
        if(a[i]==1){
            one++;
        }
        if(a[i]==2){
            two++;
        }
        if(a[i]==3){
            three++;
        }
    }
    printf("0-%d\n 1-%d\n 2-%d\n 3-%d\n", zero, one, two, three);
    return 0;
}