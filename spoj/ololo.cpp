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
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <algorithm>


using namespace std;

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
int main(int argc, char *argv[])
{
    std::map<long long int, bool> cache;
    long long int n = glong();
    for (long long int i = 0; i < n; ++i) {
        long long int t = glong();
        try {
            cache.at(t) = false;
        }
        catch(exception e) {
            cache[t] = true;
        }
    }
    for (map<long long int, bool>::iterator it=cache.begin(); it != cache.end(); ++it){
        if (it->second){
            printf("%lld\n", it->first);
            break;
        }
    }

    return 0;
}
