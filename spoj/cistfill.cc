#include <bits/stdc++.h>
#define endl                        ('\n')
using namespace std;
int testcases;

template<class Function>
double bsearch(double lo, double hi, Function check) {
    double tlo = lo, thi = hi;
    while(hi - lo > 0.001) {
        double mid = lo + ((hi - lo) / 2.0);
        if (check(mid))
            hi = mid;
        else
            lo = mid + 0.001;
    }
    if (abs(thi - lo) < 0.01 or abs(tlo - lo) < 0.01)
        throw runtime_error("exit");
    return lo;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> testcases;
    cout << fixed << setprecision(2);
    for (int test = 1; test <= testcases; ++test) {
        int32_t n, v;
        cin >> n;
        vector<array<int32_t, 4> > cisterns(n);
        for_each(cisterns.begin(), cisterns.end(), [](array<int32_t, 4>& x) {
            for_each(x.begin(), x.end(), [](int32_t& y) {
                cin >> y;
            });
        });
        cin >> v;
        try {
            cout << bsearch(0, 1040401, [&] (double h) -> bool {
                double volume = accumulate(
                    cisterns.begin(),
                    cisterns.end(),
                    0.00,
                    [&](double init, array<int32_t, 4>& cist) -> double {
                        return init + max(0.00, min(h - cist[0], (double)cist[1])*cist[3]*cist[2]);
                    });
                return volume >= v;
            }) << endl;
        } catch(runtime_error x) {
            cout << "OVERFLOW" << endl;
        }
    }
    return 0;
}
