#include <bits/stdc++.h>
#ifdef __lucy__
    #include "prettyprint.hpp"
#endif
#define endl                                        ('\n')
#define i32max                                      (0x7fffffff)
#define i32min                                      (-0x7fffffff-1)
#define i64max                                      (0x7fffffffffffffff)
#define i64min                                      (-0x7fffffffffffffff-1)
#define ui32max                                     (0xffffffffu)
#define ui64max                                     (0xffffffffffffffffu)
#define bitcounti32                                 __builtin_popcount
#define bitcounti64                                 __builtin_popcountll
#define len(x)                                      ((uint32_t)(x).size())
#define esort(x)                                    (sort((x).begin(), (x).end()))
#define ersort(x)                                   (sort((x).rbegin(), (x).rend()))
#define name(x)                                     (#x)
#define uint                                        uint32_t
#define int                                         int32_t
#define ulong                                       uint64_t
#define long                                        int64_t
using namespace std;

ulong mod = 1000000007;

void roll_hash(char* str_x, ulong* hash_x, uint x) {
    *hash_x = 0;
    while(*str_x) {
        ulong h = ((*hash_x)*256 + *(str_x++)) % mod;
        *++hash_x = h;
    }
}

inline ulong powmod(ulong e, ulong x) {
    ulong a = 1;
    while(x) {
        if (x & 1)
            a = (a*e) % mod;
        e = (e*e) % mod;
        x >>= 1;
    }
    return a;
}

ulong strhash(ulong* hasharr, uint j, uint i) {
    long h = ((long)hasharr[i] - (long)((hasharr[j]*powmod(256, i - j)) % mod)) % mod;
    if (h < 0)
        h = (h + mod) % mod;
    return h;
}


uint longestCommonSubstring_n(char* str_x, char* str_y, uint x, uint y) {
    ulong hash_x[x + 1];
    ulong hash_y[y + 1];
    roll_hash(str_x, hash_x, x);
    roll_hash(str_y, hash_y, y);
    // cout << vector<ulong>(hash_x, hash_x + x + 1) << endl;
    // cout << vector<ulong>(hash_y, hash_y + y + 1) << endl;
    for (uint i = x; i > 0; --i) {
        unordered_set<ulong> visited;
        unordered_map<ulong, uint> hashkeys;
        for (uint j = 0; j + i <= x; ++j) {
            ulong h = strhash(hash_x, j, j + i);
            hashkeys[h] = j;
            visited.insert(h);
        }
        for (uint j = 0; j + i <= y; ++j) {
            auto vx = visited.find(strhash(hash_y, j, j + i));
            if (vx != visited.end() && strncmp(str_x + hashkeys[*vx], str_y + j, i) == 0)
                return i;
        }
    }
    return 0;
}

int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    char* strix = new char[100];
    char* striy = new char[100];
    while(cin) {
        cin.getline(strix, 100);
        if (!cin)
            continue;
        cin.getline(striy, 100);
        uint n = strlen(strix);
        uint m = strlen(striy);
        if (strix[n - 1] == '\n')
            strix[--n] = 0;
        if (striy[m - 1] == '\n')
            striy[--m] = 0;
        if (n > m) {
            swap(strix, striy);
            swap(n, m);
        }
        cout << longestCommonSubstring_n(strix, striy, n, m) << endl;
    }
    return 0;
}

