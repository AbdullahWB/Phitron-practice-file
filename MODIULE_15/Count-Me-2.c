// #include <stdio.h>

// int main() {
//     char S[100001];
//     scanf("%s", S);
//     int countConsonants = 0;
//     for (int i = 0; S[i] != '\0'; i++) {
//         switch(S[i]) {
//             case 'a':
//             case 'e':
//             case 'i':
//             case 'o':
//             case 'u':
//                 break;
//             default:
//                 countConsonants++;
//         }
//     }
//     printf("%d\n", countConsonants);
//     return 0;
// }

#include <stdio.h>
int main()
{
    char s[100001];
    scanf("%s", s);
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            // nothing
        }else{
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}