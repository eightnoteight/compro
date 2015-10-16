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
int cmps=0;

struct sequence {
    vector<int32_t> arr;
    sequence(size_t n) {
        arr.resize(n);
    }
    inline int32_t& operator[](const size_t k) {
        return arr[k];
    }
    inline bool operator<(const sequence& other) {
        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[i] < other.arr[i])
                return true;
            else if (arr[i] > other.arr[i])
                return false;
        }
        return false;
    }
    inline bool operator>(const sequence& other) {
        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[i] > other.arr[i])
                return true;
            else if (arr[i] < other.arr[i])
                return false;
        }
        return false;
    }
    inline bool operator==(const sequence& other) {
        for (size_t i = 0; i < arr.size(); ++i)
            if (arr[i] != other.arr[i])
                return false;
        return true;
    }
    inline bool operator!=(const sequence& other) {
        for (size_t i = 0; i < arr.size(); ++i)
            if (arr[i] != other.arr[i])
                return true;
        return false;
    }
    inline bool operator>=(const sequence& other) {
        return !(*this < other);
    }
    inline bool operator<=(const sequence& other) {
        return !(*this > other);
    }
};

template<typename Comparable>
pair<size_t, size_t> minmax(vector<Comparable>& arr, size_t lo, size_t hi) {
    if (hi - lo == 1) {
        return make_pair(lo, lo);
    }
    if (hi - lo == 2) {
        cmps++;
        if (arr[lo] < arr[lo + 1])
            return make_pair(lo, lo + 1);
        else
            return make_pair(lo + 1, lo);
    }
    size_t mid = lo + ((hi - lo) / 2);
    pair<size_t, size_t> left = minmax(arr, lo, mid);
    pair<size_t, size_t> right = minmax(arr, mid, hi);
    pair<size_t, size_t> result;
    cmps++;
    if (arr[left.first] < arr[right.first])
        result.first = left.first;
    else
        result.first = right.first;
    cmps++;
    if (arr[left.second] > arr[right.second])
        result.second = left.second;
    else
        result.second = right.second;
    return result;
}

template<typename Comparable>
pair<size_t, size_t> minmax(vector<Comparable>& arr) {
    size_t minIndex = 0;
    size_t maxIndex = 0;
    for (size_t x = 1; x < arr.size(); x++) {
        cmps++;
        if (arr[maxIndex] < arr[x]) {
            maxIndex = x;
        }
        else {
            cmps++;
            if (arr[minIndex] > arr[x]) {
                minIndex = x;
            }
        }
    }
    return make_pair(minIndex, maxIndex);
}
template<typename Comparable>
pair<size_t, size_t> _minmax(vector<Comparable>& arr, size_t lo, size_t hi) {
    size_t minIndex = lo;
    size_t maxIndex = lo;
    for (size_t x = lo + 1; x < hi; x++) {
        cmps++;
        if (arr[maxIndex] < arr[x]) {
            maxIndex = x;
        }
        else {
            cmps++;
            if (arr[minIndex] > arr[x]) {
                minIndex = x;
            }
        }
    }
    return make_pair(minIndex, maxIndex);
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, start, p;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l >> m >> n >> o >> start >> p;
    cout << m << endl;
    vector<sequence> arr(n, o);
    arr[0][o - 1] = start;
    for (int32_t x = o - 2; x >= 0; --x) {
        if (x >= p)
            arr[0][x] = (a*arr[0][x + 1]*arr[0][x + 1] + b*arr[0][x + 1] + c) % m;
        else
            arr[0][x] = (d*arr[0][x + 1]*arr[0][x + 1] + e*arr[0][x + 1] + f) % m;
    }
    for (int32_t x = 1; x < n; ++x) {
        for (int32_t y = 0; y < o; ++y) {
            if (y >= p)
                arr[x][y] = (g*arr[x - 1][y]*arr[x - 1][y] + h*arr[x - 1][y] + i) % m;
            else
                arr[x][y] = (j*arr[x - 1][y]*arr[x - 1][y] + k*arr[x - 1][y] + l) % m;
        }
    }
    // for (auto& x: arr)
    //     cout << x.arr << endl;
    // pair<size_t, size_t> mm = minmax(arr);
    // cout << mm.first << " " << mm.second << endl;
    pair<size_t, size_t> mm2 = _minmax(arr, 0, arr.size());
    cout << mm2.first << " " << mm2.second << endl;
    cout << "comparisions = " << cmps << endl;
    // cout << min_element(arr.begin(), arr.end()) - arr.begin() << " " << max_element(arr.begin(), arr.end()) - arr.begin() << endl;
    return 0;
}
