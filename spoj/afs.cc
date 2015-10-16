#include <bits/stdc++.h>
using namespace std;
#define builtin_gcd __gcd
template <class number>
void input(number *ptr){
    register char c = getchar_unlocked();
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
void print(const char* format, ...){
    va_list arguments;
    va_start(arguments, format);
    register char c;
    char num[20];
    int64_t i = 0, j;
    int64_t n;
    while (format[i] != '\0'){
        if (format[i] != '{')
            putchar_unlocked(format[i++]);
        else{
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
int main(int argc, char const *argv[])
{
    int64_t *facSum = new int64_t[1000001];
    for (int64_t i = 0; i < 1000001; ++i) {
        facSum[i] = 0;
    }
    for (int64_t i = 1; i < 1000001; ++i) {
        for (int64_t j = 2*i; j < 1000001; j += i) {
            facSum[j] += i;
        }
    }
    int64_t *seq = new int64_t[1000001];
    seq[0] = 0;
    for (int i = 1; i < 1000001; ++i) {
        seq[i] = seq[i - 1] + facSum[i];
    }
    int64_t testcases;
    input(&testcases);
    while(testcases--) {
        int64_t n;
        input(&n);
        print("{}\n", seq[n]);
    }
    return 0;
}
