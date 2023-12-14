#include <stdio.h>

int main() {
    char S[100001];
    scanf("%s", S);
    int countConsonants = 0;
    for (int i = 0; S[i] != '\0'; i++) {
        switch(S[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                break;
            default:
                countConsonants++;
        }
    }
    printf("%d\n", countConsonants);
    return 0;
}