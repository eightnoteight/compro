#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#ifndef __mr__
    #define endl                                               '\n'
#endif
using namespace std;

int main(int argc, char const *argv[]) {
    int tt;
    cin >> tt;
    while(tt--) {
        string s, t;
        cin >> s >> t;
        map<char, int> socc, tocc;
        for(auto& ch: s)
            socc[ch]++;
        for(auto& ch: t)
            tocc[ch]++;
        int count = 0;
        for (int i = 0; i < 256; ++i) {
            if (socc[i] > tocc[i]) {
                count = -1;
                break;
            }
            if (socc[i] < tocc[i])
                count++;
        }
        cout << count << endl;
    }
    return 0;
}
