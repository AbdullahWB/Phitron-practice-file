#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];

    // Fix: Change the condition to i < n
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int minIndex = 0, maxIndex = 0;
    int minValue = a[0], maxValue = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < minValue) {
            minValue = a[i];
            minIndex = i;
        }
        if (a[i] > maxValue) {
            maxValue = a[i];
            maxIndex = i;
        }
    }

    int temp = a[minIndex];
    a[minIndex] = a[maxIndex];
    a[maxIndex] = temp;

    for (int i = 0; i < n; i++) {
        // Fix: Add a space after each number
        printf("%d ", a[i]);
    }

    return 0;
}
