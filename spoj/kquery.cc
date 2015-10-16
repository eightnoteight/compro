#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>


int min(int a, int b) {
    return (a<b)?a:b;
}

int arr[30001];
int tree[65536];
int Q;


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

int construct_tree(int lo, int hi, int ind)
{
    int mid;
    if((hi - lo) == 1)
    {
        tree[ind] = arr[lo];
    }
    else if((hi - lo) < 1)
        return INT_MAX;
    else
    {
        mid = lo + ((hi - lo) / 2);
        tree[ind] = min(
                construct_tree(lo, mid, 2*ind + 1),
                construct_tree(mid, hi, 2*ind + 2));
    }
    return tree[ind];
}

int count(int lo, int hi, int qlo, int qhi, int ind)
{
    if(((hi - lo) < 1) || ((qhi - qlo) < 1) || (hi <= qlo) || (lo >= qhi))
        return 0;
    if((hi - lo) == 1)
        return (tree[ind] > Q)?1:0;
    int mid = lo + ((hi - lo) / 2);
    if(qhi <= mid)
        return count(lo, mid, qlo, qhi, 2*ind + 1);
    if(mid <= qlo)
        return count(mid, hi, qlo, qhi, 2*ind + 2);
    if(tree[ind] > Q)
        return qhi - qlo;
    return count(lo, mid, qlo, mid, 2*ind + 1) + count(mid, hi, mid, qhi, 2*ind + 2);
}
int main(int argc, char *argv[])
{
    int n = gint();
    int i, j;
    unsigned x;
    int q;
    for (x = 0; x < n; ++x)
    {
        arr[x] = gint();
    }
    construct_tree(0, n, 0);
    q = gint();
    while(q--)
    {
        i = gint() - 1;
        j = gint();
        Q = gint();
        pint(count(0, n, i, j, 0));
    }
    return 0;
}
