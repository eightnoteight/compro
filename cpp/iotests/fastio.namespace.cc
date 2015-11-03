#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define ulong                                                   unsigned long
using namespace std;
const ulong mod = 1000000007ul;

struct Fastio {
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

    #define SCANIREF_FOR(intType) \
    inline void scan(intType& p) { \
        char c; \
        bool sign = false; \
        p = 0; \
        c = ignorewhits(); \
        if (c == '-') { \
            sign = true; \
            c = getchar_unlocked(); \
        } \
        while (c > 33) { \
            p = (p * 10) + (c - '0'); \
            c = getchar_unlocked(); \
        } \
        if (sign) \
            p *= -1; \
    }
    SCANIREF_FOR(int)
    SCANIREF_FOR(uint)
    SCANIREF_FOR(long)
    SCANIREF_FOR(ulong)

    template<class dType, class... Args>
    inline void scan(dType& dt, Args&... args) {
        scan(dt);
        scan(args...);
    }
    template<class T>
    inline Fastio& operator >> (T& item) {
        scan(item);
        return *this;
    }
    template<class T>
    inline Fastio& operator << (T& item) {
        print(item);
        return *this;
    }
    inline void print(char x) {

    }
};
Fastio fastio;

int main(int argc, char const *argv[]) {
    int varint1;
    int varint2;
    long varlong1;
    long varlong2;
    ulong varulong1;
    ulong varulong2;
    char str1[100];
    string str2;
    char varch;
    fastio >> \
        varint1 >> \
        varint2 >> \
        varlong1 >> \
        varlong2 >> \
        varulong1 >> \
        varulong2 >> \
        str1 >> \
        str2 >> \
        varch;
    cout << varint1 << ' ' << varint2 << ' ' << varlong1 << ' ' << varlong2 << ' ' << varulong1 << ' ' << varulong2 << ' ' << str1 << ' ' <<  str2 << ' ' << varch << '\n';
    return 0;
}
