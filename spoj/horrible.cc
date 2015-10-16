#include <bits/stdc++.h>
using namespace std;

template <class number>
void input(number *ptr) {
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
void print(const char* format, ...) {
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

class SegmentTree
{
private:
    int64_t qlo, qhi, qval;
    vector<pair<int64_t, int64_t> > tree;
    int64_t _calc_tree_size(int n) {
        int64_t s = 1;
        while((1 << (++s)) < n);
        return 2*(1 << s) + 1;
    }
    int64_t _find(int lo, int hi, int idx, int64_t par) {
        if (lo >= hi) {
            return 0;
        }
        tree[idx].second += par;
        if (hi - lo == 1) {
            tree[idx].first += tree[idx].second;
            tree[idx].second = 0;
        }
        if (qlo <= lo && hi <= qhi) {
            return tree[idx].first + (hi - lo)*tree[idx].second;
        }
        if (qhi <= lo || qlo >= hi) {
            return 0;
        }
        int64_t mid = lo + ((hi - lo) / 2);
        int64_t tmp;
        tmp = _find(lo, mid, 2*idx + 1, tree[idx].second) +
            _find(mid, hi, 2*idx + 2, tree[idx].second);
        tree[idx].first = tree[2*idx + 1].first + \
            (mid - lo)*tree[2*idx + 1].second + \
            tree[2*idx + 2].first + \
            tree[2*idx + 2].second*(hi - mid);
        tree[idx].second = 0;
        return tmp;
    }
    void _addrange(int lo, int hi, int idx, int64_t par) {
        if (lo >= hi) {
            return;
        }
        tree[idx].second += par;
        if (hi - lo == 1) {
            tree[idx].first += tree[idx].second;
            tree[idx].second = 0;
        }
        if (qlo <= lo && hi <= qhi) {
            tree[idx].second += qval;
            if(hi - lo == 1) {
                tree[idx].first += tree[idx].second;
                tree[idx].second = 0;
            }
            return;
        }
        if (qhi <= lo || qlo >= hi || hi - lo == 1) {
            return;
        }
        int64_t mid = lo + ((hi - lo) / 2);
        _addrange(lo, mid, 2*idx + 1, tree[idx].second);
        _addrange(mid, hi, 2*idx + 2, tree[idx].second);
        tree[idx].first = tree[2*idx + 1].first + \
            (mid - lo)*tree[2*idx + 1].second + \
            tree[2*idx + 2].first + \
            tree[2*idx + 2].second*(hi - mid);
        tree[idx].second = 0;
    }

public:
    int size;
    vector<int64_t> arr;
    SegmentTree(int n) : size(n) {
        arr.resize(size);
        tree.resize(_calc_tree_size(size));
    }
    void addrange(int lo, int hi, int64_t val) {
        qlo = lo;
        qhi = hi;
        qval = val;
        _addrange(0, size, 0, 0);
    }
    int64_t find(int lo, int hi){
        qlo = lo;
        qhi = hi;
        return _find(0, size, 0, 0);
    }
    ~SegmentTree() {
    }
};


int main(int argc, char const *argv[]) {
    int t;
    input(&t);
    while (t--) {
        int n, c;
        input(&n);input(&c);
        SegmentTree segt(n);
        for (int i = 0; i < c; ++i) {
            int ci, p, q, v;
            input(&ci);
            if (ci == 0) {
                input(&p); input(&q); input(&v);
                segt.addrange(p - 1, q, v);
            }
            else {
                input(&p); input(&q);
                print("{}\n", segt.find(p - 1, q));
            }
        }
    }
    return 0;
}
