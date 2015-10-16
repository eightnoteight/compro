#include <bits/stdc++.h>
using namespace std;

vector<string> tokenize_nondelim(const string& word, const string& ndelim) {
    vector<string> tokens;
    bool ns = true;
    for (char x: word) {
        if (find(ndelim.begin(), ndelim.end(), x) == ndelim.end()) {
            ns = true;
            continue;
        }
        if (ns)
            tokens.push_back(string());
        tokens.rbegin()->push_back(x);
        ns = false;
    }
    return move(tokens);
}
int64_t gcd(int64_t a, int64_t b) {
    int64_t tmp;
    while(b) {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    string word;
    int bullshit = 0;
    int diffwords = 0;
    set<string> uniq;
    while (cin >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        vector<string> tokens = tokenize_nondelim(word, "abcdefghijklmnopqrstuvwxyz");
        for (auto& str: tokens) {
            if (str == "bullshit") {
                diffwords += uniq.size();
                bullshit++;
                uniq.clear();
                continue;
            }
            uniq.insert(str);
        }
    }
    cout <<
        diffwords / gcd(diffwords, bullshit) <<
        " / " <<
        bullshit / gcd(diffwords, bullshit) <<
        endl;
    return 0;
}
