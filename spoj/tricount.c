#include <stdio.h>

int main(int argc, const char *argv[])
{
    
    long long int triangles[1000001], t, x, n, i, tmp;
    triangles[0] = 0;
    for (x = 1; x < 1000001; x++){
        triangles[x] = (x*(x+1))/2;
        tmp = (x - 1)/2;
        triangles[x] += tmp*(tmp + 1);
        triangles[x] += (x - 1)*((x - 1) % 2) + triangles[x - 1];
    }
    scanf("%lld", &t);
    for (i = 0; i < t; i++){
        scanf("%lld", &n);
        printf("%lld\n", triangles[n]);
    }
    return 0;
}
