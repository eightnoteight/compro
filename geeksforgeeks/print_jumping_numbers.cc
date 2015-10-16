#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#ifndef __mr__
    #define endl                                               '\n'
#endif
using namespace std;

vector<int> jumpingnumbers(int n) {
    vector<int> jn;
    queue<int> Q({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    while (Q.size()) {
        int v = Q.front(); Q.pop();
        if (v < n) {
            jn.push_back(v);
            int k = v % 10;
            if (k == 0) {
                if (v != 0) {
                    Q.push(v*10 + 1);
                }
            }
            else if (k == 9) {
                Q.push(v*10 + 8);
            }
            else {
                Q.push(v*10 + v%10 - 1);
                Q.push(v*10 + v%10 + 1);
            }
        }
    }
    return move(jn);
}


int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    cout << jumpingnumbers(n) << endl;
    return 0;
}
