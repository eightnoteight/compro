#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define redirect_stdin FILE*spojtest=fopen("/tmp/spojtest.in","r");dup2(fileno(spojtest),STDIN_FILENO);


void isavl(int32_t* bst, int32_t n)
{
    int32_t depth[250];
    memset(depth, 0, sizeof(depth));
    int32_t x, i;
    for (i = 0; i < n; ++i)
    {
        x = i;
        if(bst[x] != -1){
            while(1) {
                depth[x] = ((depth[2*x + 1] > depth[2*x + 2])? (depth[2*x + 1]) : (depth[2*x + 2])) + 1;
                if(x == 0)
                    break;
                x = (x - 1) / 2;
                // printf("%d\n", x);
            }
        }
    }
    for (x = 0; x < n; ++x)
    {
        if(abs(depth[2*x + 1] - depth[2*x + 2]) > 1){
            printf("F\n");
            return;
        }
    }
    printf("T\n");
}

int main(int argc, char const *argv[])
{
    // redirect_stdin;
    int32_t t;
    int32_t n;
    int32_t i;
    int32_t bst[200];
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for (i = 0; i < n; ++i) {
            scanf("%d", &bst[i]);
        }
        isavl(bst, n);
    }
    return 0;
}
