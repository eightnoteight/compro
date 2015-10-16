#include <bits/stdc++.h>
#ifdef __lucy__
    #include "prettyprint.hpp"
#endif
#define endl                                        ('\n')
#define i32max                                      (0x7fffffff)
#define i32min                                      (-0x7fffffff-1)
#define i64max                                      (0x7fffffffffffffff)
#define i64min                                      (-0x7fffffffffffffff-1)
#define ui32max                                     (0xffffffffu)
#define ui64max                                     (0xffffffffffffffffu)
#define bitcounti32                                 __builtin_popcount
#define bitcounti64                                 __builtin_popcountll
#define len(x)                                      ((uint32_t)(x).size())
#define esort(x)                                    (sort((x).begin(), (x).end()))
#define ersort(x)                                   (sort((x).rbegin(), (x).rend()))
#define name(x)                                     (#x)
#define uint                                        uint32_t
#define int                                         int32_t
#define ulong                                       uint64_t
#define long                                        int64_t
using namespace std;

struct unionfind {
    size_t length;
    uint32_t *roots, *weights;
    unionfind(){}
    unionfind(size_t n) {
        init(n);
    }
    void init(size_t n) {
        length = n;
        roots = new uint32_t[n];
        weights = new uint32_t[n];
        for (int i = 0; i < n; ++i) {
            roots[i] = i;
            weights[i] = 1;
        }
    }
    void connect(uint32_t a, uint32_t b) {
        uint32_t aroot = find_root(a);
        uint32_t broot = find_root(b);
        if(aroot == broot) {
            return;
        }
        else if(weights[aroot] > weights[broot]) {
            roots[broot] = aroot;
            weights[aroot] += weights[broot];
            weights[broot] = 0;
        }
        else {
            roots[aroot] = broot;
            weights[broot] += weights[aroot];
            weights[aroot] = 0;
        }
    }
    bool is_connected(uint32_t a, uint32_t b) {
        return find_root(a) == find_root(b);
    }
    int32_t find_root(uint32_t a) {
        while(roots[a] != a) {
            roots[a] = roots[roots[a]];
            a = roots[a];
        }
        return a;
    }
    ~unionfind() {
        delete[] roots;
        delete[] weights;
    }
};

class slotmanager
{
private:
    uint slots;
    unionfind slotmachine;
    int* freeslots;
    int* mapfree;
public:
    slotmanager(uint totalslots): slots(totalslots) {
        slotmachine.init(slots);
        freeslots = new int[slots];
        fill(freeslots, freeslots + slots, 1);
        mapfree = new int[slots];
        for (int i = 0; i < slots; ++i)
            mapfree[i] = i - 1;
    }
    uint size() {
        return slots;
    }
    uint pick(uint maxslots, int deadline) {
        uint unpicked = maxslots;
        int x = deadline - 1;
        if (freeslots[x]) {
            unpicked--;
            freeslots[x] = 0;
        }
        while(unpicked > 0 && mapfree[x] != -1) {
            while(mapfree[x] != -1 && freeslots[mapfree[x]] == 0) {
                slotmachine.connect(x, mapfree[x]);
                tie(x, mapfree[x]) = make_tuple(mapfree[x], mapfree[mapfree[x]]);
            }
            if (mapfree[x] != -1) {
                freeslots[mapfree[x]] = 0;
                unpicked--;
                slotmachine.connect(x, mapfree[x]);
                tie(x, mapfree[x]) = make_tuple(mapfree[x], mapfree[mapfree[x]]);
            }
        }
        return maxslots - unpicked;
    }
    ~slotmanager(){
        delete[] freeslots;
    }

};

int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    uint testcases;
    cin >> testcases;
    for(uint test = 1; test <= testcases; ++test) {
        uint n;
        cin >> n;
        array<uint, 3> jobs[n];
        uint totalslots = 0;
        for (uint i = 0; i < n; ++i) {
            cin >> jobs[i][0] >> jobs[i][1] >> jobs[i][2];
            totalslots = max(totalslots, jobs[i][1]);
        }
        sort(jobs, jobs + n, [](const array<uint, 3>& x, const array<uint, 3>& y) {
            return x[2] < y[2];
        });
        slotmanager slots(totalslots);
        ulong profit = 0;
        for (int i = n - 1; i >= 0; --i)
            profit += slots.pick(jobs[i][0], jobs[i][1])*jobs[i][2];
        cout << profit << endl;
    }
    return 0;
}

