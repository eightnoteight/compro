#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return num - ((int)((num - 1) / 9)) * 9;
    }
};

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    Solution sol;
    while (t--) {
        int n;
        cin >> n;
        cout << sol.addDigits(n) << endl;
    }
    return 0;
}
