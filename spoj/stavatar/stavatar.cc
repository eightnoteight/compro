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
    int i = 0, j;
    long n;
    while (format[i] != '\0'){
        if (format[i] != '{')
            putchar_unlocked(format[i++]);
        else{
            i += 2;
            n = va_arg(arguments, long);
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
    char carr[200];
    int n;
    gets(carr);
    n = atoi(carr);
    char s1[1000001];
    char s2[1000001];
    gets(s1);
    gets(s2);
    int m;
    gets(carr);
    m = atoi(carr);
    int arr[1000001];
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        input(&l); input(&r);
        r++;
        arr[l]++;
        arr[r]--;
    }
    int cursum = 0;
    for (int i = 0; i < n; ++i)
    {
        cursum = (cursum + arr[i]) % 2;
        if(cursum)
            swap(s1[i], s2[i]);
    }
    puts(s1);
    puts(s2);
    return 0;
}
