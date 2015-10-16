#include <bits/stdc++.h>
using namespace std;
#define usingcincout ios::sync_with_stdio(0);cin.tie(0);

template<class T> void gint(T& n);
template<class T> void pint(T a);

void matmul(int64_t mat1[], int64_t mat2[], int64_t res[], int64_t mod)
{
    int64_t* mat3 = new int64_t[16];
    for (int8_t x = 0; x < 16; ++x)
        mat3[x] = 0;
    for (int8_t x = 0; x < 4; ++x)
        for (int8_t y = 0; y < 4; ++y)
            for (int8_t z = 0; z < 4; ++z)
                mat3[x * 4 + y] = (mat3[x * 4 + z] + mat1[x * 4 + z] * mat2[z * 4 + y]) % mod;
    for (int x = 0; x < 16; ++x)
        res[x] = mat3[x];
    delete mat3;
}
void matexp(int64_t mat[], int64_t mat3[], vector<int64_t*>& matpow, int64_t n, int64_t mod)
{
    for (int x = 0; x < 4; ++x)
        for (int y = 0; y < 4; ++y)
        {
            if(x == y)
                mat3[x * 4 + y] = 1;
            else
                mat3[x * 4 + y] = 0;
        }
    while(n){
        int32_t pos = log2(n);
        matmul(matpow[pos + 1], mat3, mat3, mod);
        n -= 1 << pos;
    }
    return ;
}
int64_t tetranacci(int64_t n, vector<int64_t*>& matpow, int64_t mod)
{
    if(n < 3)
        return 0;
    else if(n == 3)
        return 1;
    int64_t mat[] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0};
    int64_t* matn3 = new int64_t[16];
    matexp(mat, matn3, matpow, n - 3, mod);
    return matn3[0] % mod;
}

int main(int argc, char *argv[])
{
    int32_t t;
    gint(t);

    return 0;
}














template<class T>
void gint(T& n)
{
    n = 0;
    int sign=1;
    register char c=0;
    while(c<33)
        c=getchar_unlocked();
    if (c=='-')
    {
        sign=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9')
    {
        n=(n<<3)+(n<<1)+(c-'0');
        c=getchar_unlocked();
    }
    n *= sign;
return;
}
template<class T>
void pint(T a)
{
    char num[20];
    int i = 0;
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
