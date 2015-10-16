#include <stdio.h>
#include <string.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

inline int get_int()
{
    int n = 0;
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
    int t = get_int(), k, i, j, nlen;
    char n[500], m[500];
    char apb[20];
    long long int ans;
    while(t--){
        scanf("%s%s%d", n, m, &k);
        nlen = strlen(n);
        sprintf(apb, "%s", n + MAX(0,nlen-17));
        sscanf(apb, "%lld", &ans);
        while (ans % (1 << k))
            k--;
        ans = 1 << k;
        printf("%lld\n", ans);
    }
    return 0;
}
