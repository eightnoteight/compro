#include <bits/stdc++.h>
using namespace std;
#define usingcincout ios::sync_with_stdio(0);cin.tie(0);
/*GleanStart
2

5 3
1 2 2 4 5
1 2
1 5
4 5

3 1
1 1 1
1 3

GleanEnd*/
void gint(int32_t& n) {
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
void dint(int32_t a) {
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
}

void gstr(char* s)
{
    while(*s)
        putchar_unlocked(*(s++));
}
int main(int argc, char *argv[])
{
    int32_t testcases;
    gint(testcases);
    for(int32_t tcase = 1; tcase <= testcases; tcase++)
    {
        gstr("Case ");
        dint(tcase);
        putchar_unlocked(':');
        putchar_unlocked('\n');
        int32_t n, q, num = 0;
        gint(n);
        gint(q);
        int32_t arr[n];
        gint(arr[0]);
        int32_t prev = arr[0];
        arr[0] = 0;
        for (int32_t x = 1; x < n; ++x){
            int32_t curr;
            gint(curr);
            if(curr != prev)
                num++;
            arr[x] = num;
            prev = curr;
        }
        for (int32_t x = 0; x < q; ++x)
        {
            int32_t i, j;
            gint(i);
            gint(j);
            dint(arr[j - 1] - arr[i - 1] + 1);
            putchar_unlocked('\n');
        }
    }
    return 0;
}


