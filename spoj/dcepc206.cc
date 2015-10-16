#include <bits/stdc++.h>
using namespace std;
class segment_tree
{
public:
    int size, upidx, upval, qlo, qhi;
    vector<int> tree;
    segment_tree(int n) {
        size = n;
        tree.resize(2*pow(2, (int32_t)ceil(log2(size))) + 1);
    }
    void uputil(int lo, int hi, int ind) {
        if(hi - lo == 1) {
            if(lo == upidx)
                tree[ind] = upval;
            return;
        }
        int mid = lo + ((hi - lo) / 2);
        if (upidx < mid)
            uputil(lo, mid, 2*ind + 1);
        else
            uputil(mid, hi, 2*ind + 2);
        tree[ind] = tree[2*ind + 1] + tree[2*ind + 2];
    }
    void update(int idx, int val) {
        upidx = idx;
        upval = val;
        uputil(0, size, 0);
    }
    int query(int lo, int hi) {
        qlo = lo;
        qhi = hi;
        return qutil(0, size, 0);
    }
    int qutil(int lo, int hi, int ind) {
        if (qhi <= lo or qlo >= hi or lo >= hi)
            return 0;
        if (qlo <= lo and hi <= qhi)
            return tree[ind];
        int mid = lo + ((hi - lo) / 2);
        return qutil(lo, mid, 2*ind + 1) + qutil(mid, hi, 2*ind + 2);
    }

};

class BIT
{
public:
    int n;
    vector<unsigned long long int> tree;
    BIT(int size) {
        n = size;
        tree.resize(n);
        for (int i = 0; i < n; ++i)
            tree[i] = 0;
    }
    unsigned long long int query(long long int idx) {
        unsigned long long int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
    void update(long long int idx, unsigned long long int val) {
        while(idx < n) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
};
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    int arr[1000001];
    cin >> t;
    while(t--) {
        int n;
        unsigned long long int result = 0;
        cin >> n;
        BIT bit(1000001);
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; ++i)
        {
            unsigned long long int tmp;
            cin >> tmp;
            if(tmp == 0)
                continue;
            arr[tmp] += tmp;
            result += bit.query(tmp - 1);
            bit.update(tmp, tmp);
        }
        cout << result << '\n';
    }
    return 0;
}
