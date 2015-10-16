#include <stdio.h>
#include <stdlib.h>
inline long long int get_int(long long int n)
{   
    n=0;
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
void bitseti(int n, int* a)
{
    int i=0;
    while(i<35)
    {
        *(a+i)=(n&1);
        n=n>>1;
        i++;
    }
}
int main(int argc, const char *argv[])
{
    long long int n;n=get_int(n);
    long long int a;a=get_int(a);
    long long int b;b=get_int(b);
    long long int ar[n];
    long long int num=0;
    long long int count=0;
    int bit[35];
    for (long long int i = 0; i < n; i++)
        ar[i] = get_int(ar[i]);
    long long int tmp = 1 << n;
    while(num<tmp)
    {
        long long int sum=0;
        bitseti(num,bit);
        for (long long int i = 0; i < n; i++)
            if (bit[i])
                sum+=ar[i];
        if (sum<=b and sum >=a)
            count++;
        num++;
    }
    printf("%d", count);
    return 0;
}
