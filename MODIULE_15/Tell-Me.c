#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        int X;
        scanf("%d", &X);

        int isXPresent = 0; // Flag to track if X is present

        for (int i = 0; i < N; i++) {
            int element;
            scanf("%d", &element);

            if (element == X) {
                isXPresent = 1;
                break; // Exit the loop early if X is found
            }
        }

        // Output the result for the current test case
        if (isXPresent) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
