#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#ifndef __mr__
    #define endl                                               '\n'
#endif
using namespace std;

int mat[3][3] = {
    {1, 2, 3},
    {4, 6, 5},
    {3, 2, 1}
};

int cnt = 0;

map<tuple<int, int, int>, int> cache;
int pathCount(int n, int m, int k) {
    if (n == 0 && m == 0 && k == mat[0][0])
        return 1;
    if (k <= 0)
        return 0;
    if (cache.find(make_tuple(n, m, k)) != cache.end())
        return cache[make_tuple(n, m, k)];
    cnt++;
    if (m == 0)
        return cache[make_tuple(n, m, k)] = pathCount(n - 1, m, k - mat[n][m]);
    else if (n == 0)
        return cache[make_tuple(n, m, k)] = pathCount(n, m - 1, k - mat[n][m]);
    else
        return cache[make_tuple(n, m, k)] = pathCount(n, m - 1, k - mat[n][m]) + pathCount(n - 1, m, k - mat[n][m]);
}

int main(int argc, char const *argv[]) {
    cout << pathCount(2, 2, 12) << " " ; cout << cnt << endl;
    return 0;
}
