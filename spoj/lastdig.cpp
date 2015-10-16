#include <cstdio>
#include <cstdlib>
int b[]={1,1,4,4,2,1,1,4,4,2};
const int a[][6]={{0},{1},{2,4,8,6},{3,9,7,1},{4,6},{5},{6},{7,9,3,1},{8,4,2,6},{9,1}};
int main(int argc, const char *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int base;
        long long int expo;
        scanf("%d%lld",&base,&expo);
        if (expo == 0)
            printf("1\n");
        else
            printf("%d\n", a[base%10][(expo-1)%b[base%10]]);
    }
    return 0;
}
