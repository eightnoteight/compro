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
int main(int argc, char *argv[])
{
    int n, s[101], efd[1000001], abc[1000001], i, e, f, d, j, tn, t1, t2, k;
    long long int count;
    n = glong();
    for (i = 0; i < n; ++i){
        s[i] = glong();
    }
    count = 0;
    i = 0;
    for (e = 0; e < n; ++e)
    {
        for (f = 0; f < n; ++f)
        {
            for (d = 0; d < n; ++d)
            {
                efd[i] = (s[e] + s[f]) * s[d];
                if(s[d] == 0)
                    efd[i] = numeric_limits<int>::min();
                abc[i] = (s[e] * s[f]) + s[d];
                i++;
            }
        }
    }
    sort(efd, efd + i);
    sort(abc, abc + i);
    j = 0;
    k = 0;
    while((j < i) && (k < i))
    {
        if(efd[j] == abc[k])
        {
            tn = efd[j];
            t1 = 0;
            t2 = 0;
            while((j < i) && (efd[j] == tn))
            {
                j++;
                t1++;
            }
            while((k < i) && (abc[k] == tn))
            {
                k++;
                t2++;
            }
            count += t1*t2;
        }
        else if(efd[j] > abc[k])
            k++;
        else
            j++;
    }
    /*
    map<int, int> efdh;
    for (j = 0; j < i; ++j)
    {
        try{
            efdh.at(efd[j]) += 1;
        }
        catch(out_of_range ex){
            efdh[efd[j]] = 1;
        }
    }
    for(j = 0; j < i; ++j)
    {
        try{
            count += efdh.at(abc[j]);
        }
        catch(out_of_range ex){

        }
    }*/
    printf("%lld\n", count);
    return 0;
}
