#include <bits/stdc++.h>
using namespace std;
char allizzwell[] = "ALLIZZWELL";
char matrix[105][105];
char old;


bool is_found(int32_t i, int32_t j, int32_t n)
{
    if(n == 10)
        return true;
    if(matrix[i][j] <= 0 or matrix[i][j] != allizzwell[n])
        return false;
    int old = matrix[i][j];
    matrix[i][j] = 2;
    bool result = is_found(i + 1, j - 1, n + 1) or
        is_found(i + 1, j + 1, n + 1) or
        is_found(i - 1, j - 1, n + 1) or
        is_found(i + 1, j, n + 1) or
        is_found(i, j - 1, n + 1) or
        is_found(i, j + 1, n + 1) or
        is_found(i - 1, j, n + 1) or
        is_found(i - 1, j + 1, n + 1);
    matrix[i][j] = old;
    return result;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int32_t t;
    cin >> t;
label:
    while(t--) {
        int32_t r, c;
        cin >> r >> c;
        for (int i = 0; i < r + 2; ++i)
            for (int j = 0; j < c + 2; ++j)
                matrix[i][j] = -1;
        for (int32_t i = 1; i <= r; i++)
            cin >> &matrix[i][1];
        for (int32_t i = 1; i <= r; i++) {
            for (int32_t j = 1; j <= c; j++) {
                if (is_found(i, j, 0)) {
                    cout << "YES\n";
                    goto label;
                }
            }
        }
        cout << "NO\n";
    }
    return 0;
}
