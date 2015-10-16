#include <bits/stdc++.h>
using namespace std;
#define builtin_gcd __gcd
#define endl '\n'

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);cin.tie(0);
    int32_t testcases;
    cin >> testcases;
    while(testcases--) {
        int32_t n, zeros = 0;
        cin >> n;
        for (int32_t x = pow(5, 13); x >= 5; x /= 5) {
            zeros += n / x;
        }
        cout << zeros << endl;
    }
    return 0;
}
