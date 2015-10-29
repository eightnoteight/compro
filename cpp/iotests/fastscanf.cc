#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define ulong                                                   unsigned long
using namespace std;
const ulong mod = 1000000007ul;

namespace fastio {
    inline char ignorewhits() {
        char c;
        do {
            c = getchar_unlocked();
        } while(c != -1 && c < 33);
        return c;
    }
    inline void scan(char& x) {
        x = ignorewhits();
    }
    inline void scan(char* w) {
        *w = ignorewhits();
        if (*w == -1) {
            *w = 0;
            return;
        }
        while ((*++w = getchar_unlocked()) >= 33) 
            if (*w == -1)
                break;
        *w = 0;
    }
    inline void scan(string& w) {
        w.clear();
        w.push_back(ignorewhits());
        if (w.back() == -1) {
            w.pop_back();
            return;
        }
        w.push_back(0);
        while ((w.back() = getchar_unlocked()) >= 33) {
            if (w.back() == -1)
                break;
            w.push_back(0);
        }
        w.pop_back();
    }
    template<class intType>
    inline void scan(intType& p) {
        char c;
        bool sign = false;
        p = 0;
        c = ignorewhits();
        if (c == '-') {
            sign = true;
            c = getchar_unlocked();
        }
        while (c > 33) {
            p = (p * 10) + (c - '0');
            c = getchar_unlocked();
        }
        if (sign)
            p *= -1;
    }
    template<class dType, class... Args>
    inline void scan(dType& dt, Args&... args) {
        scan(dt);
        scan(args...);
    }
}

int main(int argc, char const *argv[]) {
    ulong* arr = new ulong[10000001];
    uint k = 0;
    for_each(arr, arr + 10000001, [&k](ulong& x){
        fastio::scan(x);
        k += __builtin_popcountll(x);
    });
    return 0;
}
