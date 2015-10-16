#include <stdio.h>

/*
    un tested code:
        if tested remove this comment using UltiSnipEdit
*/
inline long long int glong()
{
    long long int n = 0;
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

int longlongintcmp(const void *a, const void *b){
    if(*(long long int*)b > *(long long int*)a)
        return 1;
    else if(*(long long int*)b < *(long long int*)a)
        return -1;
    else
        return 0;
}
int msb(long long int n){
    int i = 0;
    while(n >> i)
        i++;
    return i;
}
int main(int argc, char *argv[])
{
    long long int n = glong(), i, maxbit, j, k, tmp;
    long long int a[100005], t, ans = 0;
    for (i = 0; i < n; ++i)
    {
        a[i] = glong();
    }
    qsort((void*)a, n, sizeof(long long int), longlongintcmp);
    i = 0;
    while ((i < n) && (msb(a[i])))
    {
        j = i + 1;
        t = msb(a[i]);
        while((j < n) && (t == msb(a[j])))
        {
            a[j] ^= a[i];
            j++;
        }
        qsort((void*)a, n, sizeof(long long int), longlongintcmp);
        i++;
    }
    for(i = 0; i < n; ++i)
        if((ans ^ a[i]) > ans)
            ans = ans ^ a[i];
    printf("%lld\n", ans);
    return 0;
}
