// #include <stdio.h>

// int main() {
//     int T;
//     scanf("%d", &T);
//     while (T--) {
//         char S[10001];
//         scanf("%s", S);
//         int countCapital = 0;
//         int countSmall = 0;
//         int countDigits = 0;
//         for (int i = 0; S[i] != '\0'; i++) {
//             if (S[i] >= 'A' && S[i] <= 'Z') {
//                 countCapital++;
//             } else if (S[i] >= 'a' && S[i] <= 'z') {
//                 countSmall++;
//             } else if (S[i] >= '0' && S[i] <= '9') {
//                 countDigits++;
//             }
//         }
//         printf("%d %d %d\n", countCapital, countSmall, countDigits);
//     }
//     return 0;
// }


#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char s[10001];
        scanf("%s", s);
        int capital =0;
        int small =0;
        int digit =0;
        for(int i=0; s[i] != '\0'; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                capital++;
            }else if(s[i] >= 'a' && s[i] <= 'z'){
                small++;
            }else if (s[i]>='0' && s[i]<='9'){
                digit++;
            }
        }
        printf("%d %d %d\n", capital, small, digit);
    }
    
    return 0;
}
