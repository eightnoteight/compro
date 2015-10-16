#include <stdio.h>

int main(int argc, const char *argv[])
{
    long long int tests, i, k, l, s, n, d, a, t, j;
    scanf("%lld", &tests);
    for (i = 0; i < tests; i++)
    {
        scanf("%lld%lld%lld", &k,&l,&s);
        n = (2 * s) / (l + k);
        d = (l - k) / (n - 5);
        a = k - 2*d;
        printf("%lld\n", n);
        t = a;
        for (j = 0; j < n; j++)
        {
            printf("%lld ", t);
            t += d;
        }
        printf("\n");
    }
    return 0;
}
