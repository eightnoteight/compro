/*input
20
30
40
50
50
60
312
142
234
5
7
*/
#include <bits/stdc++.h>
using namespace std;

int32_t sieve[100001];
void factor_sieve()
{
    sieve[0] = 0;
    sieve[1] = 1;
    for(int32_t x = 2; x < 100001; x += 2)
        sieve[x] = 2;
    for(int32_t x = 3; x < 100001; x += 3)
        sieve[x] = 3;
    for (int32_t x = 1; 6*x + 1 < 100001; x++) {
        if (sieve[6*x - 1] == 0)
            for(int32_t y = 6*x - 1; y < 100001; y += 6*x - 1)
                sieve[y] = 6*x - 1;
        if (sieve[6*x + 1] == 0)
            for(int32_t y = 6*x + 1; y < 100001; y += 6*x + 1)
                sieve[y] = 6*x + 1;
    }
}
template <class T>
bool gint(T& n)
{
    n = 0;
    int8_t sign=1;
    register char c=0;
    while(c<33){
        c=getchar_unlocked();
        if(c == -1)
            return false;
    }
    if (c=='-')
    {
        sign=-1;
        c=getchar_unlocked();
        if(c == -1)
            return false;
    }
    while(c>='0'&&c<='9')
    {
        n=(n<<3)+(n<<1)+(c-'0');
        c=getchar_unlocked();
        if(c == -1)
            break;
    }
    n = n*sign;
return true;
}
template<class T>
void pint(T a)
{
    register char c;
    char num[21];
    int8_t i = 0;
    if(a < 0) {
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
}
int main(int argc, char *argv[])
{
    //ios::sync_with_stdio(0);cin.tie(0);
    int32_t n;
    int32_t factors[30];
    // cout << "test";
    factor_sieve();

    // for (int i = 0; i < 100001; ++i)
    // {
    //     if (sieve[i] == 0)
    //         cout << i << '\n';
    // }
    while(gint(n))
    {
        int32_t i = 0;
        while(n != 1)
        {
            // cout << sieve[n] << '\n';
            factors[i++] = sieve[n];
            n /= sieve[n];
        }
        pint(1);
        for(int32_t j = i - 1; j >= 0; j--){
            putchar_unlocked(' ');
            putchar_unlocked('x');
            putchar_unlocked(' ');
            pint(factors[j]);
        }
        putchar_unlocked('\n');
    }
    return 0;
}
