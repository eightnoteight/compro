#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                    '\n'
#endif
#define len(x)                      (uint)(x).size()
#define int                         int32_t
#define uint                        uint32_t
#define ulong                       uint64_t
#define long                        int64_t
#define t_max(x)                    numeric_limits<x>::max()
#define t_min(x)                    numeric_limits<x>::min()
using namespace std;
const ulong mod = 1000000007ul;

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int n, m, p;
    cin >> n >> m >> p;
    string str, op;
    cin >> str;
    cin >> op;
    map<int, char> editor;
    for (int i = 0; i < n; ++i) {
        editor[i] = str[i];
    }
    auto ipos = editor.begin();
    advance(ipos, p - 1);
    for (int i = 0; i < m; ++i){
        switch(op[i]) {
            case 'L':
                if (ipos != editor.begin()) {
                    ipos--;
                }
                break;
            case 'R':
                if (++ipos == editor.end()) {
                    ipos--;
                }
                break;
            case 'D':
                int st = 1;
                if (ipos->second == '(') {
                    editor.erase(ipos++);
                    st = 1;
                    while(st) {
                        if (ipos->second == ')')
                            st--;
                        else
                            st++;
                        editor.erase(ipos++);
                    }
                    if (ipos == editor.end()) {
                        ipos--;
                    }
                }
                else {
                    ipos--;
                    st = 1;
                    while(st) {
                        if (ipos->second == ')')
                            st++;
                        else
                            st--;
                        if (ipos != editor.begin() && st != 0) {
                            ipos--;
                        }
                    }
                    editor.erase(ipos++);
                    st = 1;
                    while(st) {
                        if (ipos->second == ')')
                            st--;
                        else
                            st++;
                        editor.erase(ipos++);
                    }
                    if (ipos == editor.end()) {
                        ipos--;
                    }
                }
                break;
        }
    // for(auto x = editor.begin(); x != editor.end(); ++x) {
    //     cout << x->second;
    // }
    // cout << endl;
    }
    string ans;
    for(auto x = editor.begin(); x != editor.end(); ++x) {
        ans += x->second;
    }
    cout << ans << endl;
    return 0;
}
