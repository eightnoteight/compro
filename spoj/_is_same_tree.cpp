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

bool is_same_tree(char* pr,char* in,char* po, int prn, int inn, int pon)
{
    if (prn != inn or inn != pon)
        return false;
    int n = pon;
    if (n==0)
        return true;
    if (n == 1)
        return *pr == *in and *in == *po;
    if (*pr != *(po+n-1))
        return false;
    char* tmp;
    if ((tmp=std::find(in,in+n,*pr)) == in+inn)
        return false;
    return is_same_tree(pr+1,in,po,tmp-in,tmp-in,tmp-in)
           &&
           is_same_tree(pr+1+(tmp-in),tmp+1,po+(tmp-in),n-1-(tmp-in),n-1-(tmp-in),n-1-(tmp-in));
}

int main(int argc, const char *argv[])
{
    std::cout << is_same_tree("abedcfg","cbdafeg","cdbfgea",7,7,7)  << std::endl ;
    return 0;
}
