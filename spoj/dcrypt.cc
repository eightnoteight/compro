#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#define endl                        ('\n')
#define i32inf                      (0x7fffffff)
#define i32_inf                     (-0x7fffffff-1)
#define i64inf                      (0x7fffffffffffffff)
#define i64_inf                     (-0x7fffffffffffffff-1)
#define ui32inf                     (0xffffffffu)
#define ui64inf                     (0xffffffffffffffffu)
#define bitcounti32                 __builtin_popcount
#define bitcounti64                 __builtin_popcountll
using namespace std;
int testcases;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> testcases;
    for (int test = 1; test <= testcases; ++test) {
        int key;
        string encrypted, decrypted;
        cin >> key >> encrypted;
        for (char c: encrypted) {
            if (c == '.')
                decrypted += ' ';
            else
                decrypted +=
                    ((c - (isupper(c)?'A':'a')) + key) % 26 +
                    ((((bool)isupper(c)) == (key <= 25))?'A':'a');
        }
        cout << decrypted << endl;
    }
    return 0;
}
