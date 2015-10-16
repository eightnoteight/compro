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
    int a[35],n;
    std::cin >> n ;
    bitseti(n,a);
    for (int i = 0; i < 35; i++) {
        std::cout << a[i];
    }
    std::cout  << std::endl ;
    return 0;
}
