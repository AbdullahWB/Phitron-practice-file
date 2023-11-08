// #include <stdio.h>

// int main() {
//     int N;
//     scanf("%d", &N);
//     int positiveSum = 0;
//     int negativeSum = 0;
//     int num;
//     for (int i = 0; i < N; i++) {
//         scanf("%d", &num);
//         if (num > 0) {
//             positiveSum += num;
//         } else {
//             negativeSum += num;
//         }
//     }
//     printf("%d %d\n", positiveSum, negativeSum);
//     return 0;
// }


#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int posSum = 0;
    int negSum = 0;
    int num;
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        if(num>0){
            posSum += num;
        }else{
            negSum += num;
        }
    }
    printf("%d %d\n", posSum, negSum);
    return 0;
}