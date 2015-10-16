#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#define setbitcounti32                 __builtin_popcount
#define setbitcounti64                 __builtin_popcountll
#define clzui32                        __builtin_clz
using namespace std;
int testcases;
template <class number>
void input(number *ptr) {
    char c = getchar_unlocked();
    bool sign = false;
    while (c < 33)
        c = getchar_unlocked();
    *ptr = 0;
    if (c == '-'){
        sign = true;
        c = getchar_unlocked();
    }
    while (c > 33){
        *ptr = (*ptr * 10) + (c - '0');
        c = getchar_unlocked();
    }
    if (sign)
        *ptr *= -1;
}
void print(const char* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    char c;
    char num[20];
    int i = 0, j;
    long n;
    while (format[i] != '\0') {
        if (format[i] != '{')
            putchar_unlocked(format[i++]);
        else {
            i += 2;
            n = va_arg(arguments, int64_t);
            j = 0;
            do{
                num[j++] = n%10 + 48;
                n /= 10;
            }  while (n != 0);
            j--;
            while (j >= 0)
                putchar_unlocked(num[j--]);
        }
    }
    va_end(arguments);
}
int main() {
    input(&testcases);
    vector<unsigned int> logt(2002);
    for (unsigned int x = 2; x < 2002; ++x)
        logt[x] = 32 - clzui32(x) - (setbitcounti32(x) == 1);
    for (int test = 1; test <= testcases; ++test) {
        int64_t n, m, k;
        input(&n); input(&m); input(&k);
        print("Case #{}: {} {}\n", test, n*m*k - 1, logt[n] + logt[m] + logt[k]);
    }
    return 0;
}
