#include <bits/stdc++.h>
using namespace std;
char c = 0;

template <class T>
bool gint(T& n)
{
    n = 0;
    int8_t sign=1;
    c=0;
    while(c<33){
        c=getchar_unlocked();
        if (c == -1)
            return false;
    }
    if (c=='-')
    {
        sign=-1;
        c=getchar_unlocked();
        if(c == -1)
            return false;
    }
    while(c>='0'&&c<='9')
    {
        n=(n<<3)+(n<<1)+(c-'0');
        c=getchar_unlocked();
        if(c == -1)
        {
            n *= sign;
            return true;
        }
    }
    n *= sign;
return true;
}
template<class T>
void pint(T a)
{
    char num[21];
    int8_t i = 0;
    if(a < 0) {
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
    putchar_unlocked('\n');
}
class RangeSum
{
public:
    int32_t* tree;
    RangeSum(int32_t n)
    {
        int32_t size = (2 * (1 << ((int32_t)ceil(log2(n))))) + 1;
        tree = new int32_t[size];
        for (int32_t i = 0; i < size; ++i)
            tree[0] = 0;
    }
    void add(
        int32_t lo, 
        int32_t hi, 
        int32_t pos, 
        int32_t val, 
        int32_t ind)
    {
        if((hi - lo) == 1)
        {
            tree[ind] += val;
            return;
        }
        int32_t mid = lo + ((hi - lo ) / 2);
        if (pos < mid) {
            tree[ind] += val;
            add(lo, mid, pos, val, 2 * ind + 1);
        }
        else {
            tree[ind] += val;
            add(mid, hi, pos, val, 2 * ind + 2);
        }
    }
    int32_t find(
        int32_t lo,
        int32_t hi,
        int32_t qlo,
        int32_t qhi,
        int32_t ind)
    {
        if((qhi <= lo) or (qlo >= hi))
            return 0;
        int32_t mid = lo + ((hi - lo) / 2);
        if ((qlo <= lo)  and (hi <= qhi))
            return tree[ind];
        else if (qhi <= mid) 
            return find(lo, mid, qlo, qhi, 2 * ind + 1);
        else if (mid <= qlo) 
            return find(mid, hi, qlo, qhi, 2 * ind + 2);
        else
            return find(lo, mid, qlo, mid, 2 * ind + 1) + \
                find(mid, hi, mid, qhi, 2 * ind + 2);
    }
    ~RangeSum()
    {
        delete tree;
    }
    
};
bool gstr(char* s)
{
    c = getchar_unlocked();
    while(c < 33){
        c = getchar_unlocked();
        if (c == -1)
            return false;
    }
    s[0] = c;
    s[1] = getchar_unlocked();
    s[2] = getchar_unlocked();
    s[3] = getchar_unlocked();
    return true;
}
int main(int argc, char const *argv[])
{
    int32_t n, q;
    // cout << "test";
    gint(n);
    // cout << "test";
    gint(q);
    RangeSum rsum(n);
    for (int i = 0; i < q; ++i)
    {
        int32_t a, b;
        char s[5];
        gstr(s);
        if(s[0] == 'f')
        {
            gint(a);
            gint(b);
            pint(rsum.find(0, n, a - 1, b, 0));
        }
        else
        {
            gint(a);
            gint(b);
            rsum.add(0, n, a - 1, b, 0);
        }
    }
    return 0;
}
