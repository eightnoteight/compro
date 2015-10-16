#include <bits/stdc++.h>
using namespace std;

inline int64_t lastzero(int64_t n) {
    int i = 0;
    while(n) {
        n >>= 1;
        i++;
    }
    return i;
}
inline int64_t xormax(vector<int64_t>& arr) {
    int64_t result = 0;
    int64_t m, tmp;
    do {
        m = *max_element(arr.begin(), arr.end());
        if ((result ^ m) > result) {
            result ^= m;
        }
        tmp = lastzero(m);
        for (int64_t i = 0; i < arr.size(); ++i){
            if(arr[i] & (1 << (tmp - 1)))
                arr[i] ^= m;
        }
    } while(m);
    return result;
}
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
int main()
{
    int64_t n;
    cin >> n;
    vector<int64_t> arr(n);
    for (int64_t i = 0; i < n; ++i) {
        input(&arr[i]);
    }
    print("{}\n", xormax(arr));
    return 0;
}
