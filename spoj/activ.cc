#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#define endl                        ('\n')
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    while ((cin >> n) && n != -1) {
        vector<pair<int32_t, int32_t> > activities(n);
        for (auto& x: activities)
            cin >> x.first >> x.second;
        sort(activities.rbegin(), activities.rend());
        vector<int> search = {1000000001}, answer = {1};
        for (auto& x: activities) {
            answer.push_back((
                answer[answer.size() - 1 - (lower_bound(search.rbegin(), search.rend(), x.first) - search.rbegin())] +
                answer[answer.size() - 1 - (lower_bound(search.rbegin(), search.rend(), x.second) - search.rbegin())]) % 100000000);
            search.push_back(x.first);
        }
        if (answer[answer.size() - 1] == 0)
            cout << "99999999" << endl;
        else
            cout << setfill('0') << setw(8) << answer[answer.size() - 1] - 1 << endl;
    }
    return 0;
}
