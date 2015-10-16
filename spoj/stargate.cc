#include <bits/stdc++.h>
using namespace std;


class unionfind
{
public:
    int32_t length;
    vector<int32_t> roots;
    vector<int32_t> weights;
    unionfind(int32_t n) {
        length = n;
        roots.resize(n);
        weights.resize(n);
        for (int i = 0; i < n; ++i) {
            roots[i] = i;
            weights[i] = 1;
        }
    }
    void reinit(int32_t n) {
        length = n;
        roots.resize(n);
        weights.resize(n);
        for (int i = 0; i < n; ++i) {
            roots[i] = i;
            weights[i] = 1;
        }
    }
    ~unionfind(){
        roots.clear();
        weights.clear();
    }
    void connect(int32_t a, int32_t b) {
        int32_t aroot = find_root(a);
        int32_t broot = find_root(b);
        if(aroot == broot) {
            return;
        }
        else if(weights[aroot] > weights[broot]) {
            roots[broot] = aroot;
            weights[aroot] += weights[broot];
            weights[broot] = 0;
        }
        else {
            roots[aroot] = broot;
            weights[broot] += weights[aroot];
            weights[aroot] = 0;
        }
    }
    bool is_connected(int32_t a, int32_t b) {
        return find_root(a) == find_root(b);
    }

    int32_t find_root(int32_t a) {
        while(roots[a] != a) {
            roots[a] = roots[roots[a]];
            a = roots[a];
        }
        return a;
    }
};
char cop;
int32_t ci;
bool start = false;
unionfind uf(10);
char strline[100];
int32_t op[5];
void connectthem(int32_t src, int32_t dest, int32_t nnn, int32_t deststep, int32_t srcstep)
{
    if(nnn == 0)
        nnn = 1;
    if(deststep == 0)
        deststep = 1;
    int32_t count = 0;
    for(int32_t i = src, j = dest; count < nnn; i += srcstep, j += deststep, count++) {
        uf.connect(i, j);
    }
}
void querythem(int32_t src, int32_t dest, int32_t nnn, int32_t deststep, int32_t srcstep)
{
    if(nnn == 0)
        nnn = 1;
    if(deststep == 0)
        deststep = 1;
    int32_t count = 0;
    int32_t c = 0;
    int32_t dc = 0;
    for(int32_t i = src, j = dest; count < nnn; i += srcstep, j += deststep, count++) {
        if(uf.is_connected(i, j))
            c++;
        else
            dc++;
    }
    printf("%d %d\n", c, dc);
}
void performop(char* token) {
    if(!isalpha(token[0])) {
        op[ci++] = atoi(token);
        return;
    }
    if(start) {
        if(cop == 'D' or cop == 'd') {
            // cout << "uf.reset(" << op[0] << ")\n";
            uf.reinit(op[0]);
        }
        if(cop == 'C' or cop == 'c') {
            // cout << "connectthem(" << op[0] << ", " << op[1] << ", " << op[2] << ", " << op[3] << ", " << op[4] << ")\n";
            connectthem(op[0], op[1], op[2], op[3], op[4]);
        }
        if(cop == 'Q' or cop == 'q') {
            // cout << "querythem(" << op[0] << ", " << op[1] << ", " << op[2] << ", " << op[3] << ", " << op[4] << ")\n";
            querythem(op[0], op[1], op[2], op[3], op[4]);
        }
    }
    ci = 0;
    cop = token[0];
    op[0] = 0;
    op[1] = 0;
    op[2] = 0;
    op[3] = 0;
    op[4] = 0;
    start = true;
}

int main(int argc, char const *argv[])
{
    char* arr;
    gets(strline);
    while((arr = strtok(strline, " \n\0")) != NULL)
    {
        char* tok = arr;
        while(tok != NULL)
        {
            // cout << tok << '\n';
            performop(tok);
            tok = strtok(NULL, " \n\0");
        }
        if(gets(strline) == NULL)
            break;
    }
    if(cop == 'D' or cop == 'd') {
        uf.reinit(op[0]);
    }
    if(cop == 'C' or cop == 'c') {
        connectthem(op[0], op[1], op[2], op[3], op[4]);
    }
    if(cop == 'Q' or cop == 'q') {
        querythem(op[0], op[1], op[2], op[3], op[4]);
    }
    return 0;
}
