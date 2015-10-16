#include <bits/stdc++.h>
using namespace std;
int32_t tmp;
/*input
1
20
2 2
2 3
1 2
*/
template <class T>
bool gint(T& n)
{
    n = 0;
    int8_t sign=1;
    register char c=0;
    while(c<33)
        c=getchar_unlocked();
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
    register char c;
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
int main(int argc, char const *argv[])
{
    int32_t t;
    gint(t);
    while(t--)
    {
        int32_t p, n, m;
        gint(p);
        gint(n);
        gint(m);
        priority_queue<tuple<int32_t, int32_t, int32_t>, vector<tuple<int32_t, int32_t, int32_t> >, greater<tuple<int32_t, int32_t, int32_t> > > apq;
        priority_queue<tuple<int32_t, int32_t, int32_t>, vector<tuple<int32_t, int32_t, int32_t> >, greater<tuple<int32_t, int32_t, int32_t> > > bpq;
        for (int32_t i = 0; i < n; ++i) {
            gint(tmp);
            apq.push(make_tuple(tmp, tmp, 2));
        }
        for (int32_t i = 0; i < m; ++i) {
            gint(tmp);
            bpq.push(make_tuple(0, tmp, 1));
        }
        int32_t tasks = 0;
        int32_t ga_findings = 0;
        while(true)
        {
            tuple<int32_t, int32_t, int32_t> d = apq.top();
            apq.pop();
            if(get<0>(d) >= p)
                break;
            ga_findings += 1;
            apq.push(make_tuple(
                    get<0>(d) + get<1>(d)*get<2>(d),
                    get<1>(d), get<2>(d) + 1));
            //cout << "pass1\n";
            tuple<int32_t, int32_t, int32_t> w = bpq.top();
            bpq.pop();
            if((max(get<0>(d), get<0>(w)) + get<1>(w)*get<2>(w)) < p){
                tasks += 1;
                bpq.push(
                    make_tuple(
                        max(get<0>(d), get<0>(w)) + get<1>(w)*get<2>(w),
                        get<1>(w), get<2>(w) + 1));
            }
        }
        pint(tasks);
    }
    return 0;
}
