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
#include <stack>
#include <limits>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <algorithm>
using namespace std;

int mat[3003][3003];
char X[3003];
char Y[3003];

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

int min(int a, int b, int c)
{
    return min(a, min(b, c));
}
int edist(char* X, char* Y, int n, int m)
{
    for (int x = 0; x < n + 1; ++x)
    {
        mat[x][0] = x;
    }
    for (int x = 0; x < m + 1; ++x)
    {
        mat[0][x] = x;
    }
    for (int x = 1; x < n + 1; ++x)
    {
        for (int y = 1; y < m + 1; ++y)
        {
            mat[x][y] = min(
                    mat[x - 1][y - 1] + (X[x - 1] != Y[y - 1]),
                    mat[x - 1][y] + 1,
                    mat[x][y - 1] + 1);
        }
    }
    return mat[n][m];
}
void getstr(char* x)
{
    *x = getchar_unlocked();
    while(*x < 65)
        *x = getchar_unlocked();
    while(*x >= 65)
        *(++x) = getchar_unlocked();
    *x = '\0';
}
int main(int argc, char *argv[])
{
    int t;
    t = gint();
    while(t--)
    {
        getstr(X);
        getstr(Y);
        pint(edist(X, Y, strlen(X), strlen(Y)));
    }
    return 0;
}
