// #include <stdio.h>

// int main() {
//     int N, K;
//     scanf("%d %d", &N, &K);
//     for (int i = 0; i < N; i++) {
//         for (int j = 1; j <= K; j++) {
//             printf("%d ", j);
//         }
//         printf("\n");
//     }
//     return 0;
// }

#include <stdio.h>
int main()
{
    int n,k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) {
        for(int j=1; j<=k; j++){
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}