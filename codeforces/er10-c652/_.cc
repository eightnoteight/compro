#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <algorithm>

#define N 255
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
#ifdef _DEBUG
    freopen("ip.txt","r",stdin);
    //freopen("op.txt","w",stdout);
#endif
    int h1,h2,a,b;
    cin>>h1>>h2>>a>>b;
    ll h = 0,day = 0;
    h = h1+8*a; // 2pm - 10pm day 0
    if(h >= h2)
        cout<<"0\n";
    else{
        ++day;
        h -= 12*b; // 10pm - 10am day 1
        h += 4*a; //10am - 2pm day 1
        if(h <= h1)
            cout<<"-1\n";
        else{
            h += 8*a; // 2pm - 10pm day 1
            while(h < h2){
                ++day;
                h -= 12*b; //10pm - 10am
                h += 12*a; //10am - 10pm
            }
            cout<<day<<"\n";
        }
    }
    return 0;
}
