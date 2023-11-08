// #include <stdio.h>
// int main() {
//     int N, X, V;
//     scanf("%d", &N);
//     int A[N];
//     for (int i = 0; i < N; i++) {
//         scanf("%d", &A[i]);
//     }
//     scanf("%d %d", &X, &V);
//     // Update the value at X'th index
//     A[X] = V;
//     // Print the array in reverse order
//     for (int i = N - 1; i >= 0; i--) {
//         printf("%d", A[i]);
//         if (i > 0) {
//             printf(" ");
//         }
//     }
//     return 0;
// }

#include <stdio.h>
int main()
{
    int n, x, v;
    scanf("%d", &n);
    int ar[n];
    for(int i=0; i<n; i++){
        scanf("%d", &ar[i]);
    }
    scanf("%d %d", &x, &v);
    ar[x] = v;
    for(int i=n-1; i>=0; i--){
        printf("%d", ar[i]);
        if(i>0){
            printf(" ");
        }
    }
    return 0;
}
