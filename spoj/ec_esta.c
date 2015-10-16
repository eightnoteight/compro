#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <errno.h>

/*
 * All we have to do is to construct a perfectly balanced binary tree
 * so that we can always get the median in O(1). and each insertion at
 * most takes O(log(n)), but it's rather too complicated to construct
 * a perfectly balanced binary search tree, so we keep 2 Queues as
 * the two branches of this perfectly balanced binary tree.
 *
 */
inline int gint()
{
    int n = 0;
    int sign=1;
    char c=0;
    while(c<33)
        c=getchar_unlocked();
    if (c=='-')
    {
        sign=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        n=(n<<3)+(n<<1)+(c-'0');
        c=getchar_unlocked();
    }
return n*sign;
}

inline long long int glong()
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

int longlongcmp(const void* a, const void* b)
{
    return (int)(*(long long int*)a - *(long long int*)b);
}

typedef struct PQueue {
	long long int n,maxsize;
	long long int * keys;
} pq;

void pqswap(pq * Q, long long int i, long long int j) 
{
	long long int temp = Q->keys[i];
	Q->keys[i] = Q->keys[j];
	Q->keys[j] = temp;
}
void *pqmalloc(size_t n) {
	void *p;
	p = malloc(n);
	if (p == NULL) {
		fprintf(stderr, "malloc of %u bytes failed", (unsigned int) n);
		exit(1);
	}
	return p;
}
long long int pqextractmin(pq * Q) {
	long long int i,c;
	long long int t = Q->keys[1];
	Q->keys[1]=Q->keys[Q->n--];
	for(i=1;(c=2*i)<=Q->n;i=c)
	{
		if( ( c + 1 <= Q->n ) && ( Q->keys[c+1] < Q->keys[c] ) ) {
			c++;
		}
		if( Q->keys[i] <= Q->keys[c] ) {
			break;
		}
		pqswap(Q,c,i);
	}
	return t;
}
pq pqinit(long long int n) {
	pq Q;
	Q.maxsize = n;
	Q.keys = (long long int *) pqmalloc((Q.maxsize+1)*(sizeof(int *)));
	Q.n=0;
	return Q;
}
void pqfree(pq* Q){
    free(Q->keys);
}
void pqinsert(pq * Q, long long int key) {
	long long int i,p;
	Q->n++;
	Q->keys[Q->n] = key;
	for(i = Q->n;( i > 1) && (Q->keys[p=i/2] > Q->keys[i]); i=p)
	{
		pqswap(Q,p,i);
	}
}
int main(int argc, char *argv[])
{
    long long int t = gint();
    long long int i, n, tmp;
    pq Q1 = pqinit(100005); 
    pq Q2 = pqinit(100005);
    long long int median;
    while(t--)
    {
        n = glong();
        median = -1;
        Q1.n = 0;
        Q2.n = 0;
        for (i = 0; i < n; ++i)
        {
            tmp = glong();
            if (tmp <= median)
                pqinsert(&Q1, -tmp);
            else
                pqinsert(&Q2, tmp);
            while(Q1.n - Q2.n > 1)
                pqinsert(&Q2, -pqextractmin(&Q1));
            while(Q2.n > Q1.n)
                pqinsert(&Q1, -pqextractmin(&Q2));
            if(Q1.n - Q2.n == 1) {
                printf("%lld\n", -Q1.keys[1]);
                median = -Q1.keys[1];
            }
            else{
                if((-Q1.keys[1] + Q2.keys[1]) % 2){
                    printf("%lld.5\n", (-Q1.keys[1] + Q2.keys[1]) / 2);
                }
                else{
                    printf("%lld\n", (-Q1.keys[1] + Q2.keys[1]) / 2);
                }
                median = (-Q1.keys[1] + Q2.keys[1]) / 2;
            }
        }
    }
    return 0;
}
