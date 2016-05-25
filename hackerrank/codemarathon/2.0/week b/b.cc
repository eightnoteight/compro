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

void shash(char* s, uint* h) {
    *h = 0;
    while(*s) {
        uint tmp = *(h++) * 101 + *(s++);
        *h = tmp;
    }
}

uint powmod(uint x, uint a) {
    uint y = 1;
    while(a) {
        if (a & 1)
            y = (y * x);
        x = (x * x);
        a >>= 1;
    }
    return y;
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int t;
    cin >> t;
    char *a, *b;
    a = new char[1100011];
    b = new char[1100011];
    uint *ha = new uint[1100011];
    uint *hb = new uint[1100011];
    while(t--) {
        cin >> a >> b;
        uint la = strlen(a);
        uint lb = strlen(b);
        shash(a, ha);
        shash(b, hb);
        uint m = 0;
        for (uint x = 1; x <= min(la, lb); ++x) {
            if (hb[x] == (uint)(ha[la] - ha[la - x] * powmod(101, x))) {
                m = max(m, x);
            }
        }
        cout << a << (b + m) << '\n';
    }
    return 0;
}
