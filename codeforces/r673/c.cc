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
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> firstloc(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i]--;
        if (firstloc[arr[i]] == -1)
            firstloc[arr[i]] = i;
    }

    vector<int> maincounter(n);
    for (int i = 0; i < n; ++i) {
        vector<int> counter(n);
        counter[firstloc[arr[i]]]++;
        int moc = i;
        // cout << i << ' ' << i + 1 << ' ' << moc << ' ' << arr[moc] << endl;
        maincounter[firstloc[arr[moc]]]++;
        for (int j = i + 1; j < n; ++j) {
            counter[firstloc[arr[j]]]++;
            if (counter[firstloc[arr[moc]]] < counter[firstloc[arr[j]]])
                moc = j;
            else if (counter[firstloc[arr[moc]]] == counter[firstloc[arr[j]]] && arr[moc] > arr[j])
                moc = j;
            // cout << i << ' ' << j + 1 << ' ' << moc << ' ' << arr[moc] << endl;
            maincounter[firstloc[arr[moc]]]++;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << maincounter[i] << " ";
    }
    cout << endl;


    return 0;
}
