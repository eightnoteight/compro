#include <bits/stdc++.h>
using namespace std;

int validsubstring(const string& parenthesis) {
    stack<int> chst({0});
    int length = 0;
    for (int i = 0; i < parenthesis.size(); ++i) {
        int k = chst.top(); chst.pop();
        if (parenthesis[i] == ')') {
            if (chst.size() && chst.top() == '(') {
                k += 2;
                chst.pop();
            }
            else {
                length = max(length, k);
                k = 0;
            }
        }
        else
            chst.push('(');
        chst.push(k);
    }
    if (chst.size())
        return max(length, chst.top());
    return length;
}

int main() {
    string parenthesis;
    cin >> parenthesis;
    cout << validsubstring(parenthesis) << endl;
}
