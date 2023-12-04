#include <stdio.h>

int count_before_one(int a[], int n){
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(a[i] == 1){
            break;
        }else{
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 1; i <=n; i++)
    {
        scanf("%d", &a[i]);
    }
    int count = count_before_one(a, n);
    printf("%d\n", count);
    return 0;
}