#include <cstdio>
#include <list>
using namespace std;

void plong(long long int a)
{
    register char c;
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
    putchar_unlocked('\n');
}
inline long long int glong()
{
    long long int n = 0;
    int sign=1;
    register char c=0;
    while(c<33){
        c=getchar_unlocked();
        if (c == EOF)
            return -2;
    }
    if (c=='-')
    {
        sign=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9')
    {
        if (c == EOF)
            return n*sign;
        n=(n<<3)+(n<<1)+(c-'0');
        c=getchar_unlocked();
    }
return n*sign;
}
int main(int argc, char *argv[])
{
    long long int n;
    list<long long int> elem;
    list<long long int>::iterator med = elem.begin();
    n = glong();
    int count = 0;
    while (n != -2)
    {
        if(n == -1)
        {
            plong(*med);
            med = elem.erase(med);
            count--;
            if((count % 2) == 0)
                med--;
            n = glong();
            continue;
        }
        if(n == 0)
        {
            elem.clear();
            count = 0;
            putchar_unlocked('\n');
            n = glong();
            continue;
        }
        elem.push_back(n);
        count++;
        if (count == 1)
            med = elem.begin();
        else if (count % 2)
            med++;
        n = glong();
    }
    return 0;
}
