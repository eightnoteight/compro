#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <algorithm>


long long int temp_array[200005];

long long int split_inversions(long long int a[], long long int lo, long long int hi)
{
    if(hi - lo <= 1)
        return 0;
    long long int mid = lo + (hi - lo) / 2;
    long long int i = lo;
    long long int j = mid;
    long long int inv = 0;
    long long int k = lo;
    while(i < mid and j < hi)
    {
        if (a[i] > a[j])
        {
            inv += mid - i;
            temp_array[k++] = a[j++];
        }
        else
        {
            temp_array[k++] = a[i++];
        }
    }
    while(i < mid)
    {
        temp_array[k++] = a[i++];
    }
    while(j < hi)
    {
        temp_array[k++] = a[j++];
    }
    for(i = lo; i < hi; i++)
        a[i] = temp_array[i];
    return inv;
}
long long int inversions(long long int a[], long long int lo, long long int hi)
{
    if (hi - lo <= 1)
        return 0;
    long long int inv;
    inv = inversions(a, lo, lo + (hi - lo) / 2);
    inv += inversions(a, lo + (hi - lo) / 2, hi);
    inv += split_inversions(a, lo, hi);
    return inv;
}

inline long long int get_int(long long int n=0)
{   
    int sign=1;
    char c=0;
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
    long long int tests, n, i;
    tests = get_int();
    while (tests--)
    {
        n = get_int();
        long long int a[n];
        for (i = 0; i < n; i++)
            a[i] = get_int();
        printf("%lld\n", inversions(a, 0, n));
    }
    return 0;
}
