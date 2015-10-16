#include <bits/stdc++.h>
#define endl                        ('\n')
#define i32inf                      (0x7fffffff)
#define i32_inf                     (-0x7fffffff-1)
#define i64inf                      (0x7fffffffffffffff)
#define i64_inf                     (-0x7fffffffffffffff-1)
#define ui32inf                     (0xffffffffu)
#define ui64inf                     (0xffffffffffffffffu)
#define bitcounti32                 __builtin_popcount
#define bitcounti64                 __builtin_popcountll
using namespace std;
int testcases;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    string t;
    getline(cin, t); testcases = stoi(t);
    map<string, string> dict = {
        {"8", "ate"},
        {"w8", "wait"},
        {"gr8", "great"},
        {"4", "for"},
        {"b4", "before"}
    };
    for (int test = 1; test <= testcases; ++test) {
        string line, word;
        getline(cin, line);
        stringstream strs(line);
        auto it = line.begin();
        while(strs >> word) {
            while(*it == ' ') cout << *(it++);
            if (dict.find(word) == dict.end())
                cout << word;
            else
                cout << dict[word];
            while(*it != ' ') it++;
        }
        while(*it == ' ') cout << *(it++);
        cout << endl;
    }
    return 0;
}
