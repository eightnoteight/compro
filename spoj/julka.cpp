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

void subtract(char* n, char* k)
{
    int i = strlen(n)-1;
    int j = strlen(k)-1;
    while(j!=-1)
    {
        if (*(n+i) == *(k+j))
        {
            *(n+i) = '0';
            i--;
            j--;
            continue;
        }
        if (*(n+i) < *(k+j)) {
            --*(n+i-1);
            *(n+i) += 10;
            *(n+i) = *(n+i) - *(k+j) + '0';
            i--;
            j--;
            continue;
        }
        *(n+i) = *(n+i) - *(k+j) + '0';
        i--;
        j--;
    }
}
void divide_with_2(char* n, char* result)
{
    if (*n == 0){
        *result =0;
        return ;
    }
    if (*n == '1')
    {
        *(n+1) += 10;
        return divide_with_2(n+1,result);
    }
    if (((*n)-'0') % 2) 
    {
        *result = ((*n) - '0')/2 + '0';
        *(n+1) += 10;
        return divide_with_2(n+1,result+1);
    }
    else
    {
        *result = ((*n) - '0')/2 + '0';
        return divide_with_2(n+1,result+1);
    }
}
void add_k(char* num, char* k)
{
    int i = strlen(num)-1;
    int j = strlen(k)-1;
    int c = 0;
    while (j != -1)
    {
        int tmp = *(num+i) + *(k+j) - '0' - '0' +c;
        *(num+i) = tmp%10 + '0';
        c = tmp/10;
        j--;
        i--;
    }
    while (c && i>=0)
    {
        int tmp = *(num+i) -'0'  + c;
        *(num+i) = tmp%10 + '0';
        c = tmp/10;
        i--;
    }
    if (c)
        printf("%d", c);
    return ;
}
int main(int argc, const char *argv[])
{
    int t=10;
    char n[1000];
    char k[1000];
    char result[1000];
    char tmp_a[1000];
    while (t--)
    {
        scanf("%s%s", n,k);
        if (!strcmp(n,k)) {
            printf("0\n%s\n",n);
            continue;
        }
        subtract(n,k);
        char* num=n;
        while(*num == '0') num++;
        divide_with_2(num,result);
        strcpy(tmp_a,result);
        add_k(result, k);
        printf("%s\n%s\n", result, tmp_a);
    }
    return 0;
}
