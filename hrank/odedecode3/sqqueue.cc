#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define ulong                                                   unsigned long
using namespace std;
const ulong mod = 1000000007ul;

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int n;
    cin >> n;
    queue<uint> myq;
    map<uint, uint> mym;
    for (uint i = 0; i < n; ++i) {
        string qu;
        uint num;
        cin >> qu;
        if (qu[1] == 'U') {
            cin >> num;
            myq.push(num);
            mym[num]++;
        }
        else if (qu[1] == 'O') {
            cout << myq.front() << endl;
            mym[myq.front()]--;
            if (mym[myq.front()] == 0)
                mym.erase(mym.find(myq.front()));
            myq.pop();
        }
        else {
            cout << mym.begin()->first << endl;
        }

    }
    return 0;
}
