#include <bits/stdc++.h>
using namespace std;
#define builtin_gcd __gcd
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        long long int n;
        cin >> n;
        cout << ((((n*(n + 1)) / 2)*((n*(n + 1)) / 2)) - ((n*(n + 1)*(2*n + 1)) / 6)) / 2 << '\n';
    }
    return 0;
}
