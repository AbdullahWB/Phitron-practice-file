#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int M1, M2, D;
        scanf("%d %d %d", &M1, &M2, &D);

        // Calculate the time required for the original and increased number of farmers
        int timeOriginal = (D + M1 - 1) / M1;  // Ceiling division
        int timeIncreased = (D + M1 + M2 - 1) / (M1 + M2);  // Ceiling division

        // Find the difference in days
        int daysDifference = timeOriginal - timeIncreased;

        // Output the result for the current test case
        printf("%d\n", daysDifference);
    }

    return 0;
}
