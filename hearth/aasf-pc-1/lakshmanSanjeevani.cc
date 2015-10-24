#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#ifndef __mr__
    #define endl                                               '\n'
#endif
using namespace std;

template <class number>
inline void input(number& p){
    register char c = getchar_unlocked();
    bool sign = false;
    while (c < 33)
        c = getchar_unlocked();
    p = 0;
    if (c == '-'){
        sign = true;
        c = getchar_unlocked();
    }
    while (c > 33){
        p = (p * 10) + (c - '0');
        c = getchar_unlocked();
    }
    if (sign)
        p *= -1;
}
inline void print(const char* format, ...){
    va_list arguments;
    va_start(arguments, format);
    register char c;
    char num[20];
    int i = 0, j;
    uint64_t n;
    while (format[i] != '\0'){
        if (format[i] != '{')
            putchar_unlocked(format[i++]);
        else{
            i += 2;
            n = va_arg(arguments, uint64_t);
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

template<class T>
void genprimes(uint32_t n, T iter) {
    array<int, 10001> sieve;
    for (int i = 0; i < 10001; ++i)
        sieve[i] = 1;
    uint32_t sqrt_limit = static_cast<uint32_t>(sqrt(n));
    sieve[0] = sieve[1] = 0;
    for (uint32_t x = 2; x < sqrt_limit; ++x)
        if (sieve[x])
            for (uint32_t y = x*x; y < n; y += x)
                sieve[y] = 0;
    for (uint32_t x = 0; x < n; ++x)
        if (sieve[x])
            *(iter++) = x;
}


template<class T>
uint64_t squarefree(int n, T& primes) {
    uint64_t cnt = 0;
    uint32_t sqrt_limit = static_cast<uint32_t>(sqrt(n)) + 10;
    for(auto prime: primes) {
        if (prime > sqrt_limit || n == 1)
            break;
        if (n % prime == 0) {
            cnt++;
            while(n % prime == 0) {
                n /= prime;
            }
        }
    }
    if (n > 1)
        cnt++;
    return ((uint64_t)1) << cnt;
}

int main(int argc, char const *argv[]) {
    int n;
    array<int, 10001> primes;
    genprimes(10001, primes.begin());
    input(n);
    uint64_t sanjeevani = 0;
    for (int i = 0; i < n; ++i) {
        int tmp;
        input(tmp);
        uint64_t k = 0;
        while(tmp) {
            if (tmp & 1)
                k++;
            tmp >>= 1;
        }
        sanjeevani += ((uint64_t)1) << k;
    }
    print("{}\n", sanjeevani);
    return 0;
}
