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

template<class T>
class heap {
private:
    vector<T> arr;
public:
    heap(){}
    void push(T x) {
        arr.push_back(x);
        heap_push(arr.begin(), arr.end());
    }
    T& top() {
        return arr[0];
    }
    uint size() {
        return arr.size();
    }
    void pop() {
        pop_heap(arr.begin(), arr.end());
        arr.pop_back();
    }
};

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    uint n;
    cin >> n;
    vector<pair<int, int>> segs(n);
    for (uint i = 0; i < n; ++i) {
        cin >> segs[i].first >> segs[i].second;
    }
    return 0;
}
