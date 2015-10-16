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
    char c;
    char num[20];
    int i = 0, j;
    long n;
    while (format[i] != '\0'){
        if (format[i] != '{')
            putchar_unlocked(format[i++]);
        else{
            i += 2;
            n = va_arg(arguments, int);
            j = 0;
            do {
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
    int n;
    input(&n);
    int arr[n], k;
    for (int i = 0; i < n; ++i) {
        input(&arr[i]);
    }
    input(&k);
    multiset<int> tree;
    for (int i = 0; i < k - 1; ++i) {
        tree.insert(arr[i]);
    }
    for (int i = k - 1; i < n; ++i) {
        tree.insert(arr[i]);
        print("{} ", *tree.rbegin());
        tree.erase(tree.find(arr[i - k + 1]));
    }
    return 0;
}
