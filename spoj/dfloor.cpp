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
inline int get_int(int n=0)
{   
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
bool mat[15][15];
bool solution[15*15];
int rows;
int cols;
int status=0;
bool is_it_check()
{
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++) 
            if (!mat[i][j])
                return false;
    return true;
}
bool can_i_flip(int st)
{
    int r=st/cols,c=st%cols;
    if (r && c)
    {
        if (mat[r-1][c] && mat[r][c-1])
            return false;
        return true;
    }
    else if (r)
    {
        if (mat[r-1][c])
            return false;
        return true;
    }
    else if (c)
    {
        if (mat[r][c-1])
            return false;
        return true;
    }
    return true;
}
void flipped(int st)
{
    int r = st/cols;
    int c = st%cols;
    if (r-1 >= 0)
        mat[r-1][c] ^=1;
    if (r+1 < rows)
        mat[r+1][c] ^=1;
    if (c-1 >= 0)
        mat[r][c-1] ^=1;
    if (c+1 < cols)
        mat[r][c+1] ^=1;

}
bool flip_till_1()
{
    if (status == rows*cols -1)
    {
        if (is_it_check())
            return true;
        mat[status/cols][status%cols] ^= 1; // try flipping
        flipped(status);
        solution[status] = true;
        if (is_it_check())
            return true;
        mat[status/cols][status%cols] ^= 1; // revert
        flipped(status);
        solution[status] = false;
        return false;
    }
    if(can_i_flip(status))
    {
        mat[status/cols][status%cols] ^= 1 ; // flip it damn you
        flipped(status);
        solution[status] = true;
        status++;
        if(flip_till_1())
            return true;
        status--;
        mat[status/cols][status%cols] ^= 1 ; // revert!!!!!!
        flipped(status);
        solution[status] = false;
    }
    status++;
    return flip_till_1();
}
int main(int argc, const char *argv[])
{
    int x = get_int();
    int y = get_int();
    while(x != 0 and y != 0)
    {
        status = 0;
        rows = y;
        cols = x;
        for (int i = 0; i < x*y; i++)
            solution[i] = false;
        for (int i = 0; i < y; i++) 
        {
            char tmp[x+1];
            scanf("%s", tmp);
            for (int j = 0; tmp[j]; j++) 
                mat[i][j] = tmp[j] - '0';
        }
        if (flip_till_1())
        {
            int count = 0;
            for (int i = 0; i < x*y; i++)
                if (solution[i])
                    count++;
            printf("%d\n", count);
            for (int i = 0; i < x*y; i++)
                if (solution[i])
                    printf("%d %d\n", i%cols +1, i/cols +1);
        }
        else
            printf("-1\n");
        x = get_int();
        y = get_int();
    }
    return 0;
}
