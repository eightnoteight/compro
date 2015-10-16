#include <bits/stdc++.h>
using namespace std;

template <class T>
bool get_int(T& n)
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
void gstr(char* s)
{

    while(((*s) >= '0') && ((*s) <= '9'))
        *(s++) = getchar_unlocked();
    *s = '\0';
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
    int t;
    get_int(t);
    while(t--)
    {
        char c = 0;
        int shift = 0;
        while(c < 33){
            c = getchar_unlocked();
            if(c == -1){
                c = 0;
                break;
            }
        }
        int count = 0;
        while((c >= '0') and (c <= '9'))
        {
            char t = getchar_unlocked();
            if(t == c){
                count++;
            }
            else{
                shift += count;
                count = 0;
            }
            c = t;
        }
        pint((long long int)(1 << ((long long int)shift)));
    }
    return 0;
}
