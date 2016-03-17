#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
using namespace std;

template<class T>
vector<uint> genlps(T arr) {
    vector<uint> overlap({0});
    for (uint x = 1u, k = 0u; x < arr.size(); ++x) {
        while (k > 0 && arr[x] != arr[k])
            k = overlap[k - 1];
        if (arr[x] == arr[k])
            k++;
        overlap.push_back(k);
    }
    return move(overlap);
}

template<class T>
vector<uint> kmp(T txt, T pat) {
    uint n = txt.size();
    uint m = pat.size();
    vector<uint> overlap = genlps(pat);
    vector<uint> matches;
    for (uint x = 0u, y = 0u; x < txt.size(); ++x) {
        while (y > 0 && txt[x] != pat[y])
            y = overlap[y - 1];
        if (txt[x] == pat[y]) {
            y++;
            if (y == pat.size()) {
                matches.push_back(x + 1 - y);
                y = overlap[y - 1];
            }
        }
    }
    return move(matches);
}

int main(int argc, char const *argv[]) {
    cout << genlps(string("inini")) << endl;
    cout << kmp(string("srininininininininininivas"), string("ini")) << endl;
    return 0;
}
