#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <map>
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
    putchar_unlocked('\n');
}
template<class arrtype, class type>
class RMQ
{
    arrtype& arr;
    type* tree;
    size_t size;
private:
    type constructTree(size_t lo, size_t hi, size_t ind)
    {
        if ((hi - lo) == 1)
        {
            tree[ind] = lo;
            return tree[ind];
        }
        size_t mid = lo + ((hi - lo) / 2);
        type tmp1, tmp2;
        tmp1 = constructTree(lo, mid, 2*ind + 1);
        tmp2 = constructTree(mid, hi, 2*ind + 2);
        if (arr[tmp1] <= arr[tmp2])
            tree[ind] = tmp1;
        else
            tree[ind] = tmp2;
        return tree[ind];
    }
    type callQuery(size_t beg, size_t end, size_t qbeg, size_t qend, size_t ind)
    {
        if ((beg >= qbeg) and (end <= qend))
            return tree[ind];

        if (((beg < qbeg) and (end <= qbeg)) or ((beg >= qend) and (end > qend)))
            return -1;

        size_t mid = beg + ((end - beg) / 2);
        type tmp1, tmp2;
        tmp1 = callQuery(beg, mid, qbeg, qend, 2*ind + 1);
        tmp2 = callQuery(mid, end, qbeg, qend, 2*ind + 2);
        if (tmp1 == -1)
            return tmp2;
        else if (tmp2 == -1)
            return tmp1;
        if (arr[tmp1] <= arr[tmp2])
            return tmp1;
        else
            return tmp2;
    }
public:
    RMQ(arrtype& array, size_t array_size) : arr(array)
    {
        size = array_size;
        tree = new type[size_t(2*(pow(2, ceil(log2(size)))) + 1)];
        constructTree(0, size, 0);
    }
    type query(size_t lo, size_t hi)
    {
        return callQuery(0, size, lo, hi, 0);
    }
};

long long int maxarea(vector<long long int>& arr, long long int lo, long long int hi, RMQ<vector<long long int>, long long int>& rangeminq)
{
    if(lo >= hi)
        return 0;
    if (hi - lo == 1)
        return arr[lo];
    if (hi - lo == 2)
        return min(arr[lo], arr[lo + 1])*2;
    long long int ind = rangeminq.query(lo, hi);
    return max(
        max(
            maxarea(arr, lo, ind, rangeminq),
            maxarea(arr, ind + 1, hi, rangeminq)
        ),
        arr[ind] * (hi - lo)
    );
}
int main(int argc, char *argv[])
{
    while(true)
    {
        long long int length = glong();
        long long int maximum_area = 0;
        vector<long long int> lst;
        if (length == 0)
            break;
        for (long long int x = 0; x < length; ++x)
        {
            lst.push_back(glong());
        }
        RMQ<vector<long long int>, long long int> rangeminq(lst, length);
        maximum_area = maxarea(lst, 0, length, rangeminq);
        plong(maximum_area);
    }
    return 0;
}
