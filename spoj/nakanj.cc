#include <bits/stdc++.h>
using namespace std;

/*input
3
a1 h8
a1 c2
h8 c3
*/

int32_t bfs(pair<int32_t, int32_t> initial, pair<int32_t, int32_t> final)
{
    bool board[8][8];
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            board[i][j] = true;
    queue<pair<int32_t, int32_t> > Q;
    Q.push(initial);
    Q.push(make_pair(-1, -1));
    int32_t count = 0;
    while(Q.size() > 1)
    {
        pair<int32_t, int32_t> node = Q.front();
        Q.pop();
        if(node == final)
            break;
        // cout << "pint";
        if(node == make_pair(-1, -1))
        {
            count++;
            Q.push(node);
            continue;
        }
        int32_t i, j;
        i = node.first;
        j = node.second;
        int32_t xcor[] = {
            i - 1, i - 2, i - 2, i - 1, i + 1, i + 2, i + 2, i + 1};
        int32_t ycor[] = {
            j - 2, j - 1, j + 1, j + 2, j + 2, j + 1, j - 1, j - 2};
        for(int32_t k = 0; k < 8; k++)
        {
            int32_t x = xcor[k];
            int32_t y = ycor[k];
            if(((0 <= x) and (x < 8)) and ((0 <= y) and (y < 8)) and board[x][y])
            {
                Q.push(make_pair(x, y));
                board[x][y] = false;
            }
        }
    }
    return count;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);cin.tie(0);
    int32_t t;
    cin >> t;
    while(t--)
    {
        char p1[10], p2[10];
        cin >> p1 >> p2;
        cout << bfs(
            make_pair(p1[0] - 'a', p1[1] - '1'),
            make_pair(p2[0] - 'a', p2[1] - '1')) << '\n';
    }
    return 0;
}
