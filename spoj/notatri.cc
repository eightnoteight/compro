#include <bits/stdc++.h>
using namespace std;
#define usingcincout ios::sync_with_stdio(0);cin.tie(0);

/*GleanStart
3
4 2 10
3
1 2 3
4
5 2 9 6
0
GleanEnd*/

template <class T>
void gint(T& n) {
    n = 0;
    int sign=1;
    register char c=0;
    while(c<33)
        c=getchar_unlocked();
    if (c=='-'){
        sign=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        n=(n<<3)+(n<<1)+(c-'0');
        c=getchar_unlocked();
    } n *= sign;
}
template <class T>
void dint(T a) {
    char num[20];
    int i = 0;
    if(a < 0) {
        putchar_unlocked('-');
        a *= -1;
    }
    do {
        num[i++] = a%10 + 48;
        a /= 10;
    }  while (a != 0);
    i--;
    while (i >= 0)
        putchar_unlocked(num[i--]);
    putchar_unlocked('\n');
}
int main(int argc, char *argv[])
{
    int n;
    gint(n);
    while(n)
    {
        int sides[n], ans = 0;
        for (int x = 0; x < n; ++x)
            gint(sides[x]);
        sort(sides, sides + n);
        for (int x = 0; x < n; ++x) {
            int i = 0;
            int j = x - 1;
            while(i < j)
            {
                if (sides[x] <= sides[j] + sides[i]){
                    j--;
                }
                else{
                    ans += j - i;
                    i++;
                }
            }
        }
        dint(ans);
        gint(n);
    }
    return 0;
}
