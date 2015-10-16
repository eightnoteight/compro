#include <stdio.h>
#include <stdlib.h>

int knapsack(int** items, int critical, int n)
{
    int** ks = (int**)malloc(sizeof(int*)*(n + 1));
    int i,j;
    for (i = 0; i < n + 1; i++) {
        ks[i] = (int*)malloc(sizeof(int)*(critical + 1));
        for (j = 0; j < critical + 1; j++)
            ks[i][j] = 0;
    }
    for (i = 1; i < n + 1; i++) {
        /* code */
        for (j = 1; j < critical + 1; j++) {
            /* code */  
            if(items[i - 1][0] > j)
                ks[i][j] = ks[i - 1][j];
            else
                ks[i][j] = ks[i - 1][j] > ks[i - 1][j - items[i - 1][0]] + items[i - 1][1]?ks[i - 1][j]:ks[i - 1][j - items[i - 1][0]] + items[i - 1][1];
        }
    }

    return ks[n][critical];
}
int main(int argc, const char *argv[])
{
    int s, n,i;
    scanf("%d%d", &s, &n);
    int** items = (int**)malloc(sizeof(int*)*n);
    for (i = 0; i < n; i++) {
        items[i] = (int*)malloc(sizeof(int)*n);
        scanf("%d%d", &items[i][0], &items[i][1]);
    }
    printf("%d", knapsack(items, s, n));
    return 0;
}
