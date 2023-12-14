#include <stdio.h>

long long int fun(long long int m,long long int a, long long int b,long long int c)
{
    if (a == 0 || b == 0 || c == 0)
    {
        if (a == 0)
            return b * c;
        if (b == 0)
            return a * c;
        if (c == 0)
            return a * b;
    }

    long long int mull = (a * b * c);

    if (m % mull == 0)
    {
        return (m / mull);
    }
    else
    {
        return -1;
    }
}

int main()
{
    long long int t;
    scanf("%lld", &t);
    for (int i = 0; i < t; i++)
    {
        long long int m, a, b, c;
        scanf("%lld %lld %lld %lld", &m, &a, &b, &c);

        long long int result = fun(m, a, b, c);
        printf("%lld\n", result);
    }
    return 0;
}