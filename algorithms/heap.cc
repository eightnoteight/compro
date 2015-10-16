// wrong algo
#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#ifndef __mr__
    #define endl                                               '\n'
#endif
using namespace std;

template<class T>
struct heap {
    vector<T> tree;
    heap(){}
    void push(T x) {
        tree.push_back(x);
        int pos = tree.size() - 1;
        int parentpos = (pos - 1) / 2;
        while (tree[parentpos] > tree[pos]) {
            swap(tree[parentpos], tree[pos]);
            pos = parentpos;
            parentpos = (pos - 1) / 2;
        }
    }
    T top() {
        return tree[0];
    }
    void pop() {
        swap(tree[0], tree[tree.size() - 1]);
        tree.pop_back();
        int pos = 0, child1 = 1, child2 = 2, minpos;
        while (child1 < tree.size()) {
            if (child2 == tree.size()) {
                if (tree[pos] > tree[child1])
                    swap(tree[pos], tree[child1]);
                break;
            }
            else if (tree[pos] <= tree[child1] && tree[pos] <= tree[child2]) {
                break;
            }
            else if (tree[child1] <= tree[pos] && tree[child1] <= tree[child2]) {
                swap(tree[pos], tree[child1]);
                pos = child1;
                child1 = 2*pos + 1;
                child2 = 2*pos + 2;
            }
            else {
                swap(tree[pos], tree[child2]);
                pos = child2;
                child1 = 2*pos + 1;
                child2 = 2*pos + 2;
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    heap<int> h;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        h.push(k);
    }
    vector<int> sarr;
    for (int i = 0; i < n; ++i)
    {
        sarr.push_back(h.top());
        h.pop();
    }
    cout << sarr << endl;
    return 0;
}
