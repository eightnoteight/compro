#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define ulong                                                   unsigned long
using namespace std;
const ulong mod = 1000000007ul;

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int t;
    cin >> t;
    while(t--) {
        string s;
        int d;
        cin >> s >> d;
        rotate(s.begin(), s.begin() + d - 1,  s.end());
        if ((s.size() - d) % 2 == 0) {
            reverse(s.end() - (d - 1), s.end());
        }
        cout << s << endl;
    }
    return 0;
}
