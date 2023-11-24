#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char S[10001];
        scanf("%s", S);
        int countCapital = 0;
        int countSmall = 0;
        int countDigits = 0;
        for (int i = 0; S[i] != '\0'; i++) {
            if (S[i] >= 'A' && S[i] <= 'Z') {
                countCapital++;
            } else if (S[i] >= 'a' && S[i] <= 'z') {
                countSmall++;
            } else if (S[i] >= '0' && S[i] <= '9') {
                countDigits++;
            }
        }
        printf("%d %d %d\n", countCapital, countSmall, countDigits);
    }
    return 0;
}
