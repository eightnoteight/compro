#include <bits/stdc++.h>
using namespace std;

class segment_tree {
public:
    struct node {
        int32_t openings;
        int32_t closings;
    };
    vector<node> tree;
    char* expression;
    int32_t size;
    segment_tree (int32_t n, char* expr) {
        expression = expr;
        size = n;
        tree.resize(2*pow(2, (int32_t)ceil(log2(size))) + 1);
        construct_tree(0, size, 0);
    }
    void construct_tree(int32_t low, int32_t high, int32_t index) {
        if (high - low == 1) {
            expression[low] == '(' ? (tree[index].openings = 1) : (tree[index].closings = 1);
            return;
        }
        int32_t left = 2 * index + 1;
        int32_t right = 2 * index + 2;
        int32_t mid = low + ((high - low) / 2);
        construct_tree(low, mid, left);
        construct_tree(mid, high, right);
        tree[index].openings = tree[left].openings + tree[right].openings - \
                               min(tree[left].openings, tree[right].closings);
        tree[index].closings = tree[left].closings + tree[right].closings - \
                               min(tree[left].openings, tree[right].closings);
    }
    void update(int32_t low, int32_t high, int32_t index, int32_t chindex) {
        if(high - low == 1) {
            if(expression[chindex] == ')')
                expression[chindex] = '(';
            else
                expression[chindex] = ')';
            swap(tree[index].openings, tree[index].closings);
            return;
        }
        int32_t mid = low + ((high - low) / 2);
        int32_t left = 2*index + 1;
        int32_t right = 2*index + 2;
        if (chindex >= mid)
            update(mid, high, right, chindex);
        else
            update(low, mid, left, chindex);
        tree[index].openings = tree[left].openings + tree[right].openings - \
                               min(tree[left].openings, tree[right].closings);
        tree[index].closings = tree[left].closings + tree[right].closings - \
                               min(tree[left].openings, tree[right].closings);
    }
    bool is_ok(){
        return ((tree[0].openings == tree[0].closings) and (tree[0].openings == 0));
    }

};

int main(int argc, const char *argv[])
{
    ios::sync_with_stdio(0);cin.tie(0);
    char expr[30003]; // well i like palindromes
    int32_t n;
    int32_t m;
    int32_t q;
    for (int32_t i = 1; i <= 10; i++) {
        cin >> n >> expr >> m;
        segment_tree segt(n, expr);
        cout << "Test " << i << ":\n";
        while(m--) {
            cin >> q;
            if(q)
                segt.update(0, n, 0, q - 1);
            else
                cout << (segt.is_ok() ? "YES\n" : "NO\n");
        }
    }
    return 0;
}
