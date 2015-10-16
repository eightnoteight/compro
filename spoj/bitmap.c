#include <stdlib.h>
#include <stdio.h>

typedef int Queue_key;

struct Queue_Node {
    Queue_key key;
    struct Queue_Node* next;
};

struct Queue{
    struct Queue_Node *head, *tail;
};

struct Queue* Queue_Create(){
  struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
  struct Queue_Node* s = (struct Queue_Node*)malloc(sizeof(struct Queue_Node));
  s->next = NULL;
  q->head = q->tail = s; /* sentinel */
  return q;
}

int Queue_Empty(struct Queue* q){
  return q->head == q->tail;
}

void Queue_Destroy(struct Queue* q){
  struct Queue_Node* p;
  while(q->head){
    p = q->head;
    q->head = q->head->next;
    free(p);
  }
  free(q);
}

struct Queue* Queue_Enqueue(struct Queue* q, Queue_key x){
  struct Queue_Node* p = (struct Queue_Node*)malloc(sizeof(struct Queue_Node));
  p->key = x;
  p->next = NULL;
  q->tail->next = p;
  q->tail = p;
  return q;
}

Queue_key Queue_Dequeue(struct Queue* q){
  struct Queue_Node* p = q->head->next;
  Queue_key x = p->key;
  q->head->next = p->next;
  if(q->tail == p)
    q->tail = q->head;
  free(p);
  return x;
}

int d(int mat[], int i, int j, int n, int m) {
    int mn = m * n;
    int iter;
    int ans = 0;
    int c;
    if (mat[i * m + j] == 1) {
        return 0;
    }
    int mark[34225];
    for (iter = 0; iter < 34225; iter++) {
        mark[iter] = 0;
    }
    struct Queue* Q = Queue_Create();
    Queue_Enqueue(Q, i * m + j);
    Queue_Enqueue(Q, -1);
    mark[i * m + j] += 1;
    while (1) {
        c = Queue_Dequeue(Q);
        if (c == -1) {
            Queue_Enqueue(Q, -1);
            ans += 1;
            continue;
        }
        if ((c % m) && (!mark[c - 1])) {
            if (mat[c - 1] == 1) {
                return ans + 1;
            }
            Queue_Enqueue(Q, c - 1);
            mark[c - 1] += 1;
        }
        if (((c + 1) % m) && (!mark[c + 1])) {
            if (mat[c + 1] == 1) {
                return ans + 1;
            }
            Queue_Enqueue(Q, c + 1);
            mark[c + 1] += 1;
        }
        if (((0 <= (c + m)) && ((c + m) < mn)) && (!mark[c + m])) {
            if (mat[c + m] == 1) {
                return ans + 1;
            }
            Queue_Enqueue(Q, c + m);
            mark[c + m] += 1;
        }
        if (((0 <= (c - m)) && ((c - m) < mn)) && (!mark[c - m])) {
            if (mat[c - m] == 1) {
                return ans + 1;
            }
            Queue_Enqueue(Q, c - m);
            mark[c - m] += 1;
        }
    }
}

inline int get_int()
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
    while(c>='0'&&c<='9')
    {
        n=(n<<3)+(n<<1)+(c-'0');
        c=getchar_unlocked();
    }
return n*sign;
}

int main(int argc, const char *argv[])
{
    int t = get_int();
    int m, n;
    int iter1, iter2;
    int mat[34225];
    char string[185];
    while(t--){
        scanf("%d%d", &n, &m);
        for (iter1 = 0; iter1 < n; iter1++) {
            scanf("%s", string);
            for (iter2 = 0; iter2 < m; iter2++) {
                if (string[iter2] == '0') {
                    mat[iter1 * m + iter2] = 0;
                }
                else {
                    mat[iter1 * m + iter2] = 1;
                }
            }
        }
        for (iter1 = 0; iter1 < n; iter1++) {
            for (iter2 = 0; iter2 < m; iter2++) {
                printf("%d ", d(mat, iter1, iter2, n, m));
            }
            printf("\n");
        }
    }
    return 0;
}
