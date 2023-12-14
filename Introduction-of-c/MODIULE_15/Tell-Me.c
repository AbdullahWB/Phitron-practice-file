// #include <stdio.h>
// int main() {
//     int T;
//     scanf("%d", &T);
//     while (T--) {
//         int N;
//         scanf("%d", &N);
//         int A[N];
//         for (int i = 0; i < N; i++) {
//             scanf("%d", &A[i]);
//         }
//         int X;
//         scanf("%d", &X);
//         int isXPresent = 0;
//         for (int i = 0; i < N; i++) {
//             if (A[i] == X) {
//                 isXPresent = 1;
//                 break;
//             }
//         }
//         if (isXPresent) {
//             printf("YES\n");
//         } else {
//             printf("NO\n");
//         }
//     }
//     return 0;
// }
#include <stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    while(a--){
        int n;
        scanf("%d", &n);
        int a[n];
        for(int i=0; i<n; i++){
            scanf( "%d", &a[i]);
        }
        int x;
        scanf("%d", &x);
        int present = 0;
        for(int i=0; i<n;i++){
            if(a[i]==x){
                present=1;
                break;
            }
        }
        if(present){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
