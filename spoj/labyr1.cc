// i'm broken, Damn spoj is giving me a wrong answer
//
//
//
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
#include <stack>
#include <limits>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <algorithm>

using namespace std;


inline int gint()
{
    int n = 0;
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

pair<pair<int, int>, int> deepestNode(vector<char*> s, int c, int r, int i, int j)
{
    int length = 0;
    pair<int, int> minus1(-1, -1);
    queue< pair<int, int> > Q;
    Q.push(minus1);
    Q.push(pair<int, int>(i, j));
    set<int> visited;
    visited.insert(i*c + j);
    pair<int, int> node;
    while(true)
    {
        node = Q.front();
        Q.pop();
        if (node == minus1)
        {
            length += 1;
            Q.push(minus1);
            continue;
        }
        if ((node.second < (c - 1)) and (s[node.first][node.second + 1] == '.') and (visited.find(node.first*c + node.second + 1) == visited.end()))
        {
            Q.push(pair<int, int>(node.first, node.second + 1));
            visited.insert(node.first*c + node.second + 1);
        }
        if ((node.second > 0) and (s[node.first][node.second - 1] == '.') and (visited.find(node.first*c + node.second - 1) == visited.end()))
        {
            Q.push(pair<int, int>(node.first, node.second - 1));
            visited.insert(node.first*c + node.second - 1);
        }
        if ((node.first < (r - 1)) and (s[node.first + 1][node.second] == '.') and (visited.find((node.first + 1)*c + node.second) == visited.end()))
        {
            Q.push(pair<int, int>(node.first + 1, node.second));
            visited.insert((node.first + 1)*c + node.second);
        }
        if ((node.first > 0) and (s[node.first - 1][node.second] == '.') and (visited.find((node.first - 1)*c + node.second) == visited.end()))
        {
            Q.push(pair<int, int>(node.first - 1, node.second));
            visited.insert((node.first - 1)*c + node.second);
        }
        if(Q.size() == 1)
            break;
    }
    return pair<pair<int, int>, int>(node, length - 1);
}

int longestPathLength(vector<char*>& s, int c, int r)
{
    bool breakpoint = false;
    pair<pair<int, int>, int> node;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(s[i][j] == '.')
            {
                node = deepestNode(s, c, r, i, j);
                breakpoint = true;
                break;
            }
        }
        if(breakpoint)
            break;
    }
    return deepestNode(s, c, r, node.first.first, node.first.second).second;
}

int main(int argc, char *argv[])
{
    int t;
    t = gint();
    while(t--)
    {
        int c = gint();
        int r = gint();
        vector<char*> s;
        for (int x = 0; x < r; ++x)
        {
            char* tmp;
            tmp = new char[c + 2];
            scanf("%s", tmp);
            s.push_back(tmp);
        }
        printf("Maximum rope length is %d.\n", longestPathLength(s, c, r));
    }
    return 0;
}
