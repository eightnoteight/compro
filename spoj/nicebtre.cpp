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

void maxdepth(std::string& tree,int& ch,int& mdep, int root)
{
    if (tree[root] == 'l')
    {
        ch++;
        mdep++;
        return ;
    }
    else
    {
        int cch1 =0;
        int dep1 =0;
        maxdepth(tree,cch1,dep1,root+1);
        int cch2 =0;
        int dep2 =0;
        maxdepth(tree,cch2,dep2,root+cch1+1);
        ch += cch1+cch2+1;
        mdep += std::max(dep1,dep2)+1;
    }
}
int main(int argc, const char *argv[])
{
    int t;
    std::cin >> t;
    std::string tmp;
    std::getline(std::cin, tmp);// waste of cpu
    while (t--)
    {
        std::string tree;
        std::getline (std::cin, tree);
        int mdep=0;
        int ch=0;
        maxdepth(tree,ch,mdep,0);
        std::cout << mdep-1 << std::endl;
    }
    return 0;
}
