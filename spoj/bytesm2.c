#include <stdio.h>

inline long long int get_int()
{ 
    long long int n = 0;
    int sign=1;
    char c=0;
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
return n*sign;
}
long long int table[102][102];
long long int room[102][102];
long long int max(long long int i, long long int j, long long int k)
{
    if (i >= j && i >= k)
        return i;
    else if (j >= k && j >= i)
        return j;
    else
        return k;
}
long long int maxtable(long long int h, long long int w)
{
    long long int i, j;
    for (i = h - 1; i >= 0; i--) {
        for (j = 0; j < w; j++) {
            if(j == 0)
                table[i][j] = room[i][j] + max(
                        table[i + 1][j],
                        0,
                        table[i + 1][j + 1]);
            else
                table[i][j] = room[i][j] + max(
                        table[i + 1][j],
                        table[i + 1][j - 1],
                        table[i + 1][j + 1]);
        }
    }
    long long int maximum = 0;
    for (i = 0; i < w; i++) {
        maximum = max(maximum, table[0][i], 0);
    }
    return maximum;
}
int main(int argc, const char *argv[])
{
    long long int t, i, j;
    long long int h = 0;
    long long int w = 0;
    t = get_int();
    for (i = 0; i < 102; i++) {
        for (j = 0; j < 102; j++) {
            table[i][j] = 0;
        }
    }
    while(t--){
        h = get_int();
        w = get_int();
        for (i = 0; i < h + 1; i++)
            for (j = 0; j < w + 1; j++)
                table[i][j] = 0;
        for (i = 0; i < h; i++)
            for (j = 0; j < w; j++)
                room[i][j] = get_int();
        printf("%lld\n", maxtable(h, w));
    }
    return 0;
}
