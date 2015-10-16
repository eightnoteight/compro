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
inline long long int glong()
{
    long long int n = 0;
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
void plong(long long int a)
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
}
int main(int argc, char *argv[])
{
    long long int n, k, count = 0;
    n = glong();
    k = glong();
    set<long long int> v;
    for(long long int i = 0; i < n; i++)
        v.insert(glong());
    for(set<long long int>::iterator it = v.begin(); it != v.end(); it++)
    {
        if(v.find((*it) + k) != v.end())
            count++;
        if(v.find((*it) - k) != v.end())
            count++;
    }
    plong(count/2);
    return 0;
}
