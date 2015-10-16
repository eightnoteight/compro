/*ACCEPTED!!!!!!!!!!!!!!!!!!!!!!!!!*/
#include <stdio.h>

inline long long int get_int()
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


int main(int argc, const char *argv[])
{
    long long int t = 0;
    long long int n, i, k, x, j, ans;
    long long int c[1001];
    long long int xl[104];
    while (1){
        t += 1;
        n = get_int();
        if(n == -1)
            break;
        for (i = 0; i < n+1; i++) {
            c[i] = get_int();
        }
        k = get_int();
        for (i = 0; i < k; i++) {
            xl[i] = get_int();
        }
        printf("Case %lld:\n", t);
        for (i = 0; i < k; i++) {
            x = xl[i];
            ans = c[0];
            for (j = 1; j < n + 1; j++) {
                ans = ans*x + c[j];
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
