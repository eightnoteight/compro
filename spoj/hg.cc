#include <bits/stdc++.h>
using namespace std;
#define endl                        ('\n')
#define i32inf                      (0x7fffffff)
#define i32_inf                     (-0x7fffffff-1)
#define i64inf                      (0x7fffffffffffffff)
#define i64_inf                     (-0x7fffffffffffffff-1)
#define ui32inf                     (0xffffffffu)
#define ui64inf                     (0xffffffffffffffffu)
#define gcd                         __gcd
#define bitcounti32                 __builtin_popcount
#define bitcounti64                 __builtin_popcountll

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n;
    vector<int> arra(n);
    for (auto& a: arra)
        cin >> a;
    cin >> m;
    vector<int> arrb(m);
    for (auto& b: arrb)
        cin >> b;
    int64_t result = 1;
    bool ioflag = false;
    for (auto a: arra) {
        for (auto& b: arrb) {
            int gcdab = gcd(a, b);
            result = result * gcdab;
            if (result > 1000000000) {
                ioflag = true;
                result %= 1000000000;
            }
            a /= gcdab;
            b /= gcdab;
        }
    }
    if (ioflag)
        cout << setfill('0') << setw(9);
    cout << result << endl;
    cout << ui64inf << endl;
    return 0;
}
