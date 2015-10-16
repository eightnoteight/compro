#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
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
    cin >> testcases;
    for (int32_t test = 1; test <= testcases; ++test) {
        auto Hash = [](string& str) {
            int32_t h = 0;
            for (int32_t x = 1; x <= str.size(); ++x)
                h += x*str[x - 1];
            return (19*h) % 101;
        };
        vector<string> table(101, "$");
        int32_t operations;
        cin >> operations;
        int32_t count = 0;
        while(operations--) {
            string input;
            cin >> input;
            char op = input[0];
            input = input.substr(4);
            int32_t h = Hash(input);
            if (op == 'A') {
                bool ignore = false;
                for (int j = 0; j < 20; ++j) {
                    if (table[(h + j*j + 23*j) % 101] == input) {
                        ignore = true;
                        break;
                    }
                }
                if (ignore)
                    continue;
                for (int j = 0; j < 20; ++j) {
                    if (table[(h + j*j + 23*j) % 101] == "$") {
                        table[(h + j*j + 23*j) % 101] = input;
                        count++;
                        break;
                    }
                }
            }
            else {
                for (int j = 0; j < 20; ++j) {
                    if (table[(h + j*j + 23*j) % 101] == input) {
                        table[(h + j*j + 23*j) % 101] = "$";
                        count--;
                        break;
                    }
                }
            }
        }
        cout << count << endl;
        for (int x = 0; x < 101; ++x)
            if (table[x] != "$")
                cout << x << ":" << table[x] << endl;
    }
    return 0;
}
