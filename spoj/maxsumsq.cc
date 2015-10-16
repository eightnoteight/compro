#include <bits/stdc++.h>
using namespace std;

pair<int32_t, int32_t> rollover(int32_t* a, int32_t lo, int32_t hi, int32_t mid)
{
    if(hi - lo == 2)
    {
        if(a[lo] == 0 or a[lo + 1] == 0)
            return make_pair(a[lo] + a[lo + 1], 2);
        else
            return make_pair(a[lo] + a[lo + 1], 1);
    }
    pair<int32_t, int32_t> left;
    left.first = a[mid - 1];
    left.second = 1;
    int32_t leftmax = left.first;
    for (int32_t i = mid - 2; i >= lo; --i)
    {
        left.first += a[i];
        if (left.first > leftmax) {
            left.first = leftmax;
            left.second = 1;
        }
        else if(left.first == leftmax) {
            left.second += 1;
        }
    }
    pair<int32_t, int32_t> right;
    right.first = a[mid];
    right.second = 1;
    int32_t rightmax = right.first;
    for (int32_t i = mid + 1; i <= hi; ++i)
    {
        right.first += a[i];
        if (right.first > rightmax) {
            right.first = rightmax;
            right.second = 1;
        }
        else if(right.first == rightmax) {
            right.second += 1;
        }
    }
    left.first = leftmax;
    right.first = rightmax;
    return make_pair(left.first + right.first, left.second*right.second);
}


pair<int32_t, int32_t> maxsumq(int32_t* a, int32_t lo, int32_t hi)
{
    if(hi - lo == 1)
        return make_pair(a[lo], 1);
    if(hi - lo <= 0)
        return make_pair(numeric_limits<int32_t>::min(), 0);
    int32_t mid = lo + (hi - lo) / 2;
    pair<int32_t, int32_t> left = maxsumq(a, lo, mid);
    pair<int32_t, int32_t> right = maxsumq(a, mid, hi);
    pair<int32_t, int32_t> lr = rollover(a, lo, hi, mid);
    if(left.first == right.first and right.first == lr.first)
        return make_pair(left.first, left.second + right.second + lr.second);
    else if(left.first == right.first and left.first > lr.first)
        return make_pair(left.first, left.second + right.second);
    else if(left.first == lr.first and left.first > right.first)
        return make_pair(left.first, left.second + lr.second);
    else if(right.first == lr.first and right.first > left.first)
        return make_pair(right.first, right.first + lr.first);
    else if (left.first > right.first and left.first > lr.first)
        return left;
    else if (right.first > left.first and right.first > lr.first)
        return right;
    else
        return lr;
}


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);cin.tie(0);
    int32_t t;
    cin >> t;
    while(t--)
    {
        int32_t n;
        cin >> n;
        int32_t a[n];
        for (int32_t i = 0; i < n; ++i)
            cin >> a[i];
        pair<int32_t, int32_t> mc;
        mc = maxsumq(a, 0, n);
        cout << mc.first << ' ' << mc.second << '\n';
    }
    return 0;
}
