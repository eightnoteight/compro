#include <bits/stdc++.h>
using namespace std;
#define usingcincout ios::sync_with_stdio(0);cin.tie(0);

template <class T>
void gint(T& n) {
    n = 0;
    int sign=1;
    register char c=0;
    while(c<33)
        c=getchar_unlocked();
    if (c=='-'){
        sign=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        n=(n<<3)+(n<<1)+(c-'0');
        c=getchar_unlocked();
    } n *= sign;
}
template <class T>
void dint(T a) {
    char num[20];
    int i = 0;
    if(a < 0) {
        putchar_unlocked('-');
        a *= -1;
    }
    do {
        num[i++] = a%10 + 48;
        a /= 10;
    }  while (a != 0);
    i--;
    while (i >= 0)
        putchar_unlocked(num[i--]);
}
void dstr(char* s)
{
    while(*s)
        putchar_unlocked(*(s++));
}
bool is_suspicious(int32_t gender[], int32_t start, vector<int32_t> interations[], int32_t status)
{
    gender[start] = status;
    queue<int32_t> Q;
    Q.push(start);
    while(Q.size())
    {
        int32_t node = Q.front();
        Q.pop();
        for(vector<int32_t>::iterator mate = interations[node].begin(); mate != interations[node].end(); mate++)
        {
            if(gender[*mate] == 0)
            {
                if(gender[node] == 1){
                    gender[*mate] = 2;
                }
                else{
                    gender[*mate] = 1;
                }
                Q.push(*mate);
            }
            else if(gender[*mate] == gender[node]){
                return true;
            }
        }
    }
    return false;
}
int main(int argc, char *argv[])
{
    int32_t t;
    gint(t);
    for(int32_t _ = 0; _ < t; _++)
    {
        int32_t n, i;
        gint(n);
        gint(i);
        vector<int32_t> interations[n];
        for (int32_t x = 0; x < i; ++x)
        {
            int32_t a, b;
            gint(a);
            gint(b);
            interations[a - 1].push_back(b - 1);
            interations[b - 1].push_back(a - 1);
        }
        int32_t arr[n];
        memset(arr, 0, sizeof(int32_t)*n);
        dstr("Scenario #");
        dint(_ + 1);
        putchar_unlocked(':');
        putchar_unlocked('\n');
        bool flag = true;
        for(int32_t x = 0; x < n; x++)
        {
            if((arr[x] == 0) and (is_suspicious(arr, x, interations, 1)))
            {
                dstr("Suspicious bugs found!\n");
                flag = false;
                break;
            }
        }
        if(flag)
            dstr("No suspicious bugs found!\n");
    }
    return 0;
}
