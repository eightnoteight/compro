#include <bits/stdc++.h>
using namespace std;
int32_t primes[65] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313}; // there are 446 primes under 10000000

int32_t sieve(int32_t n, int32_t* primes)
{
    vector<bool> arr(n, true);
    for (int32_t x = 4; x < n; x += 2)
    {
        arr[x] = false;
    }
    int32_t csn = ceil(sqrt(n));
    for (int32_t x = 3; x < csn; ++x)
        if(arr[x])
            for (int32_t y = x*x; y < n; y += 2*x)
                arr[y] = false;
    primes[0] = 2;
    csn = 1;
    for (int x = 3; x < n; x += 2)
        if(arr[x])
            primes[csn++] = x;

    return csn;
}

int32_t factors(int32_t n, int32_t* arr)
{
    arr[0] = 1;
    if (n == 1)
    {
        return 1;
    }
    int32_t arri = 1;
    for(int32_t i = 0; i < 65;i++)
    {
        if(primes[i] > n)
            break;
        while((n % primes[i]) == 0)
        {
            n /= primes[i];
            arr[arri++] = primes[i];
        }
    }
    if(n != 1)
        arr[arri++] = n;
    return arri;
}

inline long long int glong()
{
    long long int n = 0;
    int sign=1;
    register char c=0;
    while(c<33){
        c=getchar_unlocked();
        if(c == -1)
            return -1;
    }
    if (c=='-')
    {
        sign=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9')
    {
        n=(n<<3)+(n<<1)+(c-'0');
        c=getchar_unlocked();
        if(c == -1)
            return n*sign;
    }
return n*sign;
}
void pint(int32_t a)
{
    register char c;
    char num[20];
    int16_t i = 0;
    if(a < 0){
        putchar_unlocked('-');
        a *= -1;
    }
    do
    {
        num[i++] = a%10 + 48;
        a /= 10;
    }  while (a != 0);
    i--;
    while (i >= 0)
        putchar_unlocked(num[i--]);
}
int32_t modpow(int32_t a, int32_t b, int32_t mod)
{
    if(b == 1)
        return a % mod;
    if(b % 2){
        int32_t tmp = modpow(a, b / 2, mod);
        return (a * ((tmp*tmp) % mod)) % mod;
    }
    else {
        int32_t tmp = modpow(a, b / 2, mod);
        return (tmp*tmp) % mod;
    }
}
void divmod(int32_t a, int32_t b, int32_t& q, int32_t& r)
{
    q = a / b;
    r = a % b;
}
bool try_composite(int32_t a, int32_t s, int32_t d, int32_t n)
{
    if(modpow(a, d, n) == 1)
        return false;
    for(int16_t i = 0; i < s; i++)
        if(modpow(a, pow(2, i)*d, n) == n - 1)
            return false;
    return true;
}
bool is_probable_prime(int32_t n)
{
    // error for n < 2

    if(n == 2)
        return true;
    if ((n % 2) == 0)
        return false;
    int32_t s = 0;
    int32_t d = n - 1;
    while(true)
    {
        int32_t q, r;
        divmod(d, 2, q, r); // get this thing
        if(r == 1)
            break;
        s++;
        d = q;
    }
    for(int16_t i = 0; i < 5; i++) {
        int32_t a = random() % (n - 2) + 2;
        if(try_composite(a, s, d, n))
            return false;
    }
    return true;
}
void fermatfactors(int32_t n, int32_t& f1, int32_t& f2)
{
    long long int a = ceilf(sqrt(n));
    long long int b2 = a*a - n;
    if (n % 2 == 0)
    {
        f1 = 2;
        f2 = n / 2;
        return;
    }
    //cout << a <<" " << b2<< '\n';
    while(fabs(sqrt(b2) - round(sqrt(b2))) > 0.0001) {
        a++;
        b2 = a*a - n;
    }
    f1 = (int32_t)(a - sqrt(b2));
    f2 = (int32_t)(a + sqrt(b2));
    return;
}
int32_t fermatfactorize(int32_t n, int32_t* arr)
{
    arr[0] = 1;
    if(n == 1) {
        return 1;
    }
    stack<int32_t> st;
    if(is_probable_prime(n)){
        arr[1] = n;
        return 2;
    }
    int32_t arri = 1;
    st.push(n);
    while(st.size() != 0) {  // check it's complexity in cppman
        int32_t f1, f2;
        n = st.top();
        st.pop();
        fermatfactors(n, f1, f2);
        cout << "-----" << "n = " << n << "; f1 = " << f1 << "; f2 = " << f2 << '\n';
        if(f1 > 1 and is_probable_prime(f1))
            arr[arri++] = f1;
        else if(f1 > 1)
            st.push(f1);
        if(f2 > 1 and is_probable_prime(f2))
            arr[arri++] = f2;
        else if(f2 > 1)
            st.push(f2);
    }
    sort(arr, arr + arri);
    return arri;
}
int main(int argc, char *argv[])
{
    int32_t arr[30];
    int32_t count;
    long long int n;
    //sieve(ceil(sqrt(100001)), primes);
    while((n = glong()) != -1)
    {
        //count = fermatfactorize(n, arr);
        count = factors(n, arr);
        //pint(n);
        //putchar_unlocked(':');
        pint(1);
        for (int x = 1; x < count; ++x)
        {
            putchar_unlocked(' ');
            putchar_unlocked('x');
            putchar_unlocked(' ');
            pint(arr[x]);
        }
        putchar_unlocked('\n');
    }
    return 0;
}

