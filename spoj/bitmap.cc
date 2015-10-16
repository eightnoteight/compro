#include <bits/stdc++.h>
using namespace std;

char matrix[200][200];
int32_t answer[200][200];

void rippleIt(int32_t i, int32_t j, int32_t n, int32_t m) {
    int32_t curDist = 0;
    queue< pair<int32_t, int32_t> > Q;
    Q.push(make_pair(i, j));
    Q.push(make_pair(-1, -1));
    while(Q.size() > 1) {
        pair<int32_t, int32_t> node = Q.front();
        Q.pop();
        if (node.first == -1 && node.second == -1) {
            curDist++;
            Q.push(node);
            continue;
        }
        if (answer[node.first][node.second] <= curDist) {
            continue;
        }
        answer[node.first][node.second] = curDist;
        if (node.first != 0) {
            Q.push(make_pair(node.first - 1, node.second));
        }
        if (node.second != 0) {
            Q.push(make_pair(node.first, node.second - 1));
        }
        if (node.first != (n - 1)) {
            Q.push(make_pair(node.first + 1, node.second));
        }
        if (node.second != (m - 1)) {
            Q.push(make_pair(node.first, node.second + 1));
        }
    }
    return;
}

void bitmap(int32_t n, int32_t m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(matrix[i][j] == '1') {
                rippleIt(i, j, n, m);
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int32_t testcases;
    cin >> testcases;
    for (int32_t test = 1; test <= testcases; ++test) {
        int32_t n, m;
        cin >> n >> m;
        for (int32_t i = 0; i < n; ++i){
            cin >> matrix[i];
        }
        for (int32_t i = 0; i < n; ++i) {
            for (int32_t j = 0; j < m; ++j) {
                answer[i][j] = 40000;
            }
        }
        bitmap(n, m);
        for (int32_t i = 0; i < n; ++i) {
            for (int32_t j = 0; j < m; ++j) {
                cout << answer[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}
