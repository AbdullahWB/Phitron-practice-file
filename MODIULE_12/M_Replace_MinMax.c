#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int A[N];

    // Input array elements
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    // Find the minimum and maximum elements and their positions
    int minIndex = 0, maxIndex = 0;
    int minValue = A[0], maxValue = A[0];

    for (int i = 1; i < N; i++)
    {
        if (A[i] < minValue)
        {
            minValue = A[i];
            minIndex = i;
        }

        if (A[i] > maxValue)
        {
            maxValue = A[i];
            maxIndex = i;
        }
    }

    // Swap the minimum and maximum elements
    int temp = A[minIndex];
    A[minIndex] = A[maxIndex];
    A[maxIndex] = temp;

    // Print the modified array
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}
