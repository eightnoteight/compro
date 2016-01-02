#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define len(x)                                                  (uint)(x).size()
#define int                                                     int32_t
#define uint                                                    uint32_t
#define ulong                                                   uint64_t
#define long                                                    int64_t
using namespace std;
const ulong mod = 1000000007ull;

char* normalisepath(char* path) {
    int cd = 0;
    int path_len = strlen(path);
    for (int i = path_len - 1; i >= 0; --i) {
        if (path[i] == '/' && i > 0 && path[i - 1] == '.' && i > 1 && path[i - 2] == '.' && i > 2 && path[i - 3] == '/') {
            if (cd != 0)
                cd--;
            cd += 2;
            continue;
        }
        if (cd != 0) {
            if (path[i] == '/')
                cd--;
            path[i] = -1;
        }
    }
    int i = 0, j = 0;
    while (j < path_len) {
        if (path[i] != -1)
            i++;
        j++;
        swap(path[i], path[j]);
    }
    path[i] = '\0';
    return path;
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    char path[] = "/a/b/c/../../pa.txt";
    cout << normalisepath(path) << endl;
    return 0;
}
