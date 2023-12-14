#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    scanf("%s", &s);
    int cnt[26]={0};
    for(int i=0; i<strlen(s); i++){
        // printf("%c", s[i]);
        int value = s[i]-'a';
        // printf("%d ", value);
        cnt[value]++;
    }
    // printf("%d", cnt[0]);
    // for(int i=0; i<26; i++){
    //     if(cnt[i]!=0){
    //         printf("%c - %d\n", i+'a', cnt[i]);
    //     }
    // }

    for(int i=0; i<strlen(s); i++){
        int value = s[i]-'a';
        if(cnt[value]!=0){
            printf("%c - %d\n", value+'a', cnt[value]);
        }
        cnt[value]=0;
    }

    return 0;
}