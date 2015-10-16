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

int main(int argc, const char *argv[])
{
    int t;
    std::cin >> t ;
    while(t--)
    {
        int x,y;
        std::cin >> x >> y ;
        if ((x==y) || (x == y+2)) {
            if (x == y)
                std::cout << 4*(x/2) + x%2  << std::endl ;
            else
                std::cout << 2 + (x/2 -1)*2 +y  << std::endl ;
        }
        else
            std::cout << "No Number"  << std::endl ;
    }
    return 0;
}
