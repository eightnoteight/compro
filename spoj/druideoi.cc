#include <bits/stdc++.h>
#ifdef __lucy__
    #include "prettyprint.hpp"
#endif
#define endl                                        ('\n')
#define len(x)                                      ((uint32_t)((x).size()))
using namespace std;
inline void print() {}
template<typename _p, typename... _args>
inline void print(_p p, _args... args) {cout << p << ' '; print(args...);}
template<typename... _args>
inline void println(_args... args) {print(args...); cout << '\n';}
inline void write() { }
template<typename _p, typename... _args>
inline void write(_p p, _args... args) { cout << p; write(args...); }
template <typename _p>
inline _p getit() {_p p; cin >> p; return move(p);}
auto getint32 = getit<int32_t>; auto getuint32 = getit<uint32_t>;
auto getint64 = getit<int64_t>; auto getuint64 = getit<uint64_t>;
auto getstr = getit<string>; auto getcharacter = getit<char>;
inline void scan() { }
template<typename _p, typename... _args>
inline void scan(_p& p, _args&... args) { cin >> p; scan(args...); }
uint32_t testcases;

void work(vector<int32_t>& arr, vector<int32_t>& results) {
    vector<pair<int32_t, int32_t> > memory;
    for (uint32_t x = 0; x < len(arr); ++x) {
        while (len(memory) && arr[x] >= memory.back().first)
            memory.pop_back();
        if (len(memory))
            results[x] = memory.back().second;
        memory.push_back(make_pair(arr[x], x));
    }
    for (uint32_t x = 0; x < len(arr); ++x) {
        while (len(memory) && arr[x] >= memory.back().first)
            memory.pop_back();
        if (len(memory))
            results[x] = memory.back().second;
        memory.push_back(make_pair(arr[x], x));
    }
}

int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    cin >> testcases;
    for (uint32_t _ = 0; _ < testcases; _++) {
        int32_t n; scan(n);
        vector<int32_t> arr(n), lhs(n, -2), rhs(n, -2);
        for_each (arr.begin(), arr.end(), [](int32_t& x){
            scan(x);
        });
        work(arr, lhs);
        reverse(arr.begin(), arr.end());
        work(arr, rhs);
        reverse(rhs.begin(), rhs.end());
        for (int32_t x = 0; x < n; ++x)
            if (rhs[x] != -2)
                rhs[x] = n - rhs[x] - 1;
        for (auto x = lhs.begin(), y = rhs.begin(); x != lhs.end(); ++x, ++y)
            println(*x + 1, *y + 1);
    }
    return 0;
}
