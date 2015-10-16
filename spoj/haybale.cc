#include <bits/stdc++.h>
using namespace std;
void print(const char* format, ...);
template <class number>
void input(number *ptr);

class SegmentTree {
 private:
    int _calc_size(int n) {
        int x = 1;
        while ((1 << x) < n)
            x++;
        return x;
    }
    void _rangeadd(int lo, int hi, int idx, int par) {
        if (lo >= hi)
            return;
        tree[idx] += par;
        if (ra_hi <= lo || ra_lo >= hi)
            return;
        if (ra_lo <= lo && hi <= ra_hi) {
            tree[idx] += prop_val;
            return;
        }
        int mid = lo + ((hi - lo) / 2);
        _rangeadd(lo, mid, 2*idx + 1, tree[idx]);
        _rangeadd(mid, hi, 2*idx + 2, tree[idx]);
        tree[idx] = 0;
    }
    void _push_prop(int lo, int hi, int idx, int par) {
        if (lo >= hi)
            return;
        if (hi - lo == 1)  {
            tree[idx] += par;
            arr[lo] = tree[idx];
            tree[idx] = 0;
            return;
        }
        int mid = lo + ((hi - lo) / 2);
        _push_prop(lo, mid, 2*idx + 1, tree[idx] + par);
        _push_prop(mid, hi, 2*idx + 2, tree[idx] + par);
        tree[idx] = 0;
    }
    vector<int> tree;
    int ra_lo;
    int prop_val;
    int ra_hi;

 public:
    vector<int> arr;
    SegmentTree(size_t n) {
        arr.resize(n);
        tree.resize((1 << (_calc_size(n) + 1)) + 1);
    }
    void rangeadd(int a, int b) {
        ra_lo = a;
        ra_hi = b;
        prop_val = 1;
        _rangeadd(0, arr.size(), 0, 0);
    }
    void push_prop() {
        _push_prop(0, arr.size(), 0, 0);
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k;
    input(&n);
    input(&k);
    SegmentTree segt(n);
    for (int i = 0; i < k; ++i) {
        int a, b;
        input(&a); input(&b);
        segt.rangeadd(a - 1, b);
    }
    segt.push_prop();
    sort(segt.arr.begin(), segt.arr.end());
    print("{}\n", segt.arr[n / 2]);
    return 0;
}

template <class number>
void input(number *ptr){
    register char c = getchar_unlocked();
    bool sign = false;
    while (c < 33)
        c = getchar_unlocked();
    *ptr = 0;
    if (c == '-'){
        sign = true;
        c = getchar_unlocked();
    }
    while (c > 33){
        *ptr = (*ptr * 10) + (c - '0');
        c = getchar_unlocked();
    }
    if (sign)
        *ptr *= -1;
}
void print(const char* format, ...){
    va_list arguments;
    va_start(arguments, format);
    register char c;
    char num[20];
    int i = 0, j;
    long n;
    while (format[i] != '\0'){
        if (format[i] != '{')
            putchar_unlocked(format[i++]);
        else{
            i += 2;
            n = va_arg(arguments, long);
            j = 0;
            do{
                num[j++] = n%10 + 48;
                n /= 10;
            }  while (n != 0);
            j--;
            while (j >= 0)
                putchar_unlocked(num[j--]);
        }
    }
    va_end(arguments);
}
