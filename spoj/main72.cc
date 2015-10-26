#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#ifndef __mr__
    #define endl                                               '\n'
#endif
#define ulong                                                   unsigned long
#define uint                                                    unsigned int
#define uset                                                    unordered_set
#define umap                                                    unordered_map
using namespace std;

inline int totalsubsetsums(int* arr, int* tmp, int n) {
    uset<int> subsetsums({0});
    for (int i = 0; i < n; ++i) {
        int* tend = tmp;
        for(int x: subsetsums)
            *(tend++) = x + arr[i];
        subsetsums.insert(tmp, tend);
    }
    return accumulate(subsetsums.begin(), subsetsums.end(), 0);
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int t;
    cin >> t;
    int arr[101];
    int tmp[100001];
    while(t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        cout << totalsubsetsums(arr, tmp, n) << endl;
    }
    return 0;
}
