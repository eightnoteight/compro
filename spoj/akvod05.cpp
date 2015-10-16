// why am i getting wrong answer, locally
// the solution is identical to the python solution


#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

int main(int argc, const char *argv[])
{
    long long int te;
    std::cin >> te ;
    while (te--){
        long long int n, k;
        std::cin >> n >> k ;
        std::vector<int> t;
        for (long long int i = 0; i < k; i++) {
            long long int tmp;
            std::cin >> tmp ;
            t.push_back(tmp);
        }
        long long int mark[k + 1];
        for (long long int i = 0; i < k + 1; i++) {
            mark[i] = 0;
        }
        for (long long int i = 0; i < k; i++) {
            if(t[i] < (k + 1))
                mark[t[i]] = 1;
        }
        std::priority_queue<long long int> Q;
        for (long long int i = 0; i < k + 1; i++) 
            if(mark[i] != 1)
                Q.push(i);
        long long int i = 0;
        while(1){
            t.push_back(Q.top());
            Q.pop();
            if(Q.empty()){
                break;
            }
            if(t[i] <= k){
                Q.push(t[i]);
            }
            i++;
        }
        std::cout << t[t.size() - k - 1 + ((n - 1 - (t.size() - k - 1)) % (k + 1))]  << std::endl ;
    }
    return 0;
}
