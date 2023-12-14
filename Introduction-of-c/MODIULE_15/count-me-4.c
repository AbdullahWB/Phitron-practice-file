// #include <stdio.h>

// int main() {
//     char S[10001];
//     scanf("%s", S);
//     int count[26] = {0};
//     for (int i = 0; S[i] != '\0'; i++) {
//         count[S[i] - 'a']++;
//     }
//     for (int i = 0; i < 26; i++) {
//         if (count[i] > 0) {
//             printf("%c - %d\n", 'a' + i, count[i]);
//         }
//     }
//     return 0;
// }
#include <stdio.h>
int main()
{
    char s[10001];
    scanf("%s", s);
    int count[26]={0};
    for(int i=0; s[i]!='\0'; i++) {
        count[s[i] - 'a']++;
    }
    for(int i=0; i<26; i++){
        if(count[i] > 0) {
            printf("%c - %d\n", 'a'+i,count[i]);
        }
    }
    return 0;
}