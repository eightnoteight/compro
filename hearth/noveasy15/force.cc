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
    uint a, b, n, m, t, ia, ib, tmp;
    cin >> t;
    uint* arr = new uint[1000001];
    uint* modarr = new uint[1000001];
    for (uint _ = 0; _ < t; ++_) {
        cin >> a >> b >> n >> m;
        arr[0] = a;
        arr[1] = b;
        ia = a;
        ib = b;
        uint ari = 2;
        for (uint cx = 2; cx < n; ++cx) {
            tmp = a;
            a = b;
            b = (tmp + b) % m;
            if (a == ia and b == ib) {
                ari--;
                break;
            }
            arr[ari++] = b;
        }
        memset(modarr, 0, 1000001*sizeof(int));
        for (uint x = 0; x < n % ari; ++x) {
            modarr[arr[x]] += 1;
        }
        for (uint x = 0; x < ari; ++x) {
            modarr[arr[x]] += n / ari;
        }
        ulong ans = 0;
        for (uint x = 0; x < m; ++x) {
            ans += (ulong)modarr[x] * (ulong)modarr[x];
        }
        cout << ans << endl;

    }

    return 0;
}
