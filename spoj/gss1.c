#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

int max(int a, int b, int c)
{
    a = (a > b) ? a : b;
    return (a > c) ? a : c;
}

inline int gint()
{
    int n = 0;
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
void pint(int a)
{
    register char c;
    char num[20];
    int i = 0;
    if(a < 0){
        putchar_unlocked('-');
        a *= -1;
    }
    do
    {
        num[i++] = a%10 + 48;
        a /= 10;
    }  while (a != 0);
    i--;
    while (i >= 0)
        putchar_unlocked(num[i--]);
    putchar_unlocked('\n');
}

int getsum(int* segt, int beg, int end, int qbeg, int qend, int ind)
{
    if((beg >= qbeg) && (end <= qend))
        return segt[ind];
    if(((beg < qbeg) && (end <= qbeg)) || ((beg >= qend) && (end > qend)))
        return -15008;
    int mid = beg + ((end - beg) / 2);
    int a = getsum(segt, beg, mid, qbeg, qend, 2*ind + 1);
    int b = getsum(segt, mid, end, qbeg, qend, 2*ind + 2);
    return max(a, b, a + b);
}

int getsegt(int* arr, int lo, int hi, int ind, int* segt)
{
    if(hi - lo == 1)
    {
        segt[ind] = arr[lo];
        return segt[ind];
    }
    if(lo >= hi)
        return -15008;
    int mid = lo + ((hi - lo) / 2);
    int a = getsegt(arr, lo, mid, ind*2 + 1, segt);
    int b = getsegt(arr, mid, hi, ind*2 + 2, segt);
    segt[ind] = max(a, b, a + b);
    return segt[ind];
}
int main(int argc, char *argv[])
{
    int n, arr[50010], i, m, segt[150000], x, y;
    n = gint();
    for (i = 0; i < n; ++i)
    {
        arr[i] = gint();
    }
    m = gint();
    getsegt(arr, 0, n, 0, segt);
    for (i = 0; i < m; ++i)
    {
        x = gint();
        y = gint();
        pint(getsum(segt, 0, n, x - 1, y, 0));
    }
    return 0;
}
