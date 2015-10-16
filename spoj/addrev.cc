#include <bits/stdc++.h>
using namespace std;
#define builtin_gcd __gcd
char nl = '\n';

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);cin.tie(0);
    int testcases;
    cin >> testcases;
    while(testcases--) {
        string a, b, c;
        cin >> a >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        c = to_string(stoll(a) + stoll(b));
        reverse(c.begin(), c.end());
        cout << c.substr(c.find_first_not_of("0")) << nl;
    }
    return 0;
}
