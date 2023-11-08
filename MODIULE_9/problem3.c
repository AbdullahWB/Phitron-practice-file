// #include <stdio.h>

// int main() {
//     int N;
//     scanf("%d", &N);

//     int A[N];
//     for (int i = 0; i < N; i++) {
//         scanf("%d", &A[i]);
//     }

//     for (int i = N - 1; i >= 0; i--) {
//         if (i % 2 == 1) {
//             printf("%d ", A[i]);
//         }
//     }

//     return 0;
// }

#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int ar[n];
    for(int i=0; i<n; i++){
        scanf("%d", &ar[i]);
    }
    for(int i=n-1; i>=0; i--){
        if(i%2==1){
            printf("%d ", ar[i]);
        }
    }
    return 0;
}
