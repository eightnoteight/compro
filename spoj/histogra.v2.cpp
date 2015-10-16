#include <functional>
#include <numeric>
#include <limits>
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
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <algorithm>

using namespace std;

long long int maxarea(vector<long long int>& arr)
{
    stack<long long int> st;
    long long int i = 0;
    long long int max_area = -1;
    long long int top;
    long long int area_with_top;
    while(i < arr.size())
    {
        if ((st.empty()) or (arr[st.top()] <= arr[i]))
        {
            st.push(i);
            i++;
        }
        else
        {
            top = st.top();
            st.pop();
            if(not st.empty())
                area_with_top = arr[top] * (i - st.top() - 1);
            else
                area_with_top = arr[top] * i;
            max_area = max(max_area, area_with_top);
        }
    }
    while(st.empty() == false)
    {
        top = st.top();
        st.pop();
        if (st.empty() == false)
            area_with_top = arr[top] * (i - st.top() - 1);
        else
            area_with_top = arr[top] * i;
        max_area = max(max_area, area_with_top);
    }
    return max_area;
}
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
int main(int argc, char *argv[])
{
    while(true)
    {
        long long int length = glong();
        if (length == 0)
            break;
        vector<long long int> histogram;
        for (long long int x = 0; x < length; ++x)
        {
            histogram.push_back(glong());
        }
        plong(maxarea(histogram));
    }
    return 0;
}
