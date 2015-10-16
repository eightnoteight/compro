#include <bits/stdc++.h>
using namespace std;

template <class T>
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
    putchar_unlocked('\n');
}
void set_them(priority_queue<int>& smaller, priority_queue<int,vector<int>,greater<int> >& larger)
{
    while (smaller.size() > larger.size() + 1){
        larger.push(smaller.top());
        smaller.pop();
    }
    while(smaller.size() < larger.size() + 1){
        smaller.push(larger.top());
        larger.pop();
    }
}
void make_them_equal(priority_queue<int>& smaller, priority_queue<int,vector<int>,greater<int> >& larger)
{
    while (smaller.size() > larger.size()){
        larger.push(smaller.top());
        smaller.pop();
    }
    while(smaller.size() < larger.size()){
        smaller.push(larger.top());
        larger.pop();
    }
}
int main(int argc, char *argv[])
{
    int n;
    priority_queue<int> smaller;
    priority_queue<int,vector<int>,greater<int> > larger;
    gint(n);
    for(int t = 0; t < n; t++)
    {
        int x;
        gint(x);
        smaller.push(x);
        if(smaller.size() && larger.size())
            while(smaller.top() > larger.top()){
                larger.push(smaller.top());
                smaller.pop();
            }
        if ((smaller.size() + larger.size()) % 2)
            set_them(smaller, larger);
        else
            make_them_equal(smaller, larger);
        dint(smaller.top());
        if(smaller.size() && larger.size())
            while(smaller.top() > larger.top()){
                larger.push(smaller.top());
                smaller.pop();
            }
        if ((smaller.size() + larger.size()) % 2)
            set_them(smaller, larger);
        else
            make_them_equal(smaller, larger);
    }
    return 0;
}
