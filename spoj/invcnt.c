#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
long long int temp_array[200005];


unsigned long long int
_mergedinv(
        void* arr,
        void* tmp,
        size_t nmemb,
        size_t size,
        int (*comp)(
            const void *,
            const void *))
{
    unsigned long long int lo = 0;
    unsigned long long int hi = nmemb*size;
    unsigned long long int mid = (((size_t)(nmemb / 2))*size);
    unsigned long long int i = lo;
    unsigned long long int k = lo;
    unsigned long long int j = mid;
    unsigned long long int invcnt = 0;
    while((i < mid) && (j < hi))
    {
        if ((comp(arr + i, arr + j)) <= 0)
        {
            memcpy(tmp + k, arr + i, size);
            i += size;
        }
        else
        {
            memcpy(tmp + k, arr + j, size);
            invcnt += (mid - i) / size;
            j += size;
        }
        k += size;
    }
    while(i < mid)
    {
        memcpy(tmp + k, arr + i, size);
        k += size;
        i += size;
    }
    while(j < hi)
    {
        memcpy(tmp + k, arr + j, size);
        k += size;
        j += size;
    }
    memcpy(arr + lo, tmp + lo, hi);
    return invcnt;
}

unsigned long long int
_inversions(
        void* arr,
        void* tmp,
        size_t nmemb,
        size_t size,
        int (*comp)(
            const void *,
            const void *))
{
    if(nmemb <= 1)
        return 0;
    unsigned long long int inv = 0;
    inv += _inversions(arr, tmp, nmemb / 2, size, comp);
    inv += _inversions(
            arr + (((size_t)(nmemb / 2)) * size),
            tmp + (((size_t)(nmemb / 2)) * size),
            nmemb - ((size_t)(nmemb / 2)), size, comp);
    inv += _mergedinv(arr, tmp, nmemb, size, comp);
    return inv;
}

unsigned long long int
inversions(
        void* arr,
        size_t nmemb,
        size_t size,
        int (*comp)(
            const void *,
            const void *))
{
    /*
    void* tmp = malloc(size*nmemb);
    */
    void* tmp = (void*)temp_array;
    memset(tmp, 0, size*nmemb);
    return _inversions(arr, tmp, nmemb, size, comp);
}

int int_comp(const void* a, const void* b)
{
    return (int)(*(int*)a - *(int*)b);
}

inline long long int glong()
{
    long long int n = 0;
    int sign=1;
    register char c=0;
    while(c<33)
        c=getchar_unlocked();
    if (c=='-')
    {
        sign=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9')
    {
        n=(n<<3)+(n<<1)+(c-'0');
        c=getchar_unlocked();
    }
return n*sign;
}

int main(int argc, const char *argv[])
{
    long long int tests, n, i, a[200005];
    tests = glong();
    while (tests--)
    {
        n = glong();
        for (i = 0; i < n; i++)
            a[i] = glong();
        printf("%lld\n", inversions((void*)a, n, sizeof(long long int), int_comp));
    }
    return 0;
}
