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


bool is_same_tree(int* pr,int* in,int* po, int prn, int inn, int pon)
{
    int n = pon;
    if (n==0)
        return true;
    if (n == 1) 
        return *pr == *in and *in == *po;
    if (*pr != *(po+n-1)) 
        return false;
    int* tmp;
    if ((tmp=std::find(in,in+n,*pr)) == in+inn) 
        return false;
    return is_same_tree(pr+1,in,po,tmp-in,tmp-in,tmp-in)
           &&
           is_same_tree(pr+1+(tmp-in),tmp+1,po+(tmp-in),n-1-(tmp-in),n-1-(tmp-in),n-1-(tmp-in));
}

int main(int argc, const char *argv[])
{
    int n;
    std::cin >> n ;
    int preorder[n];
    int inorder[n];
    int postorder[n];
    for (int i = 0; i < n; i++)
        std::cin >> preorder[i];
    for (int i = 0; i < n; i++)
        std::cin >> postorder[i];
    for (int i = 0; i < n; i++)
        std::cin >> inorder[i];
    std::cout << (is_same_tree(preorder,inorder,postorder,n,n,n)?("yes"):("no"))  << std::endl ;
    return 0;
}
