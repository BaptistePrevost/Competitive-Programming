#include <iostream>
#include <math.h>
#include <list>

using namespace std;

int main() {
    long int N, K;

    while(scanf("%li %li\n", &N, &K) && N!=0) {
        if(K == 0) {
            printf("%li\n", N-1);
        }  else {
            long int weight = 0;
            long int parents = 0, nodesCount = 1;
            list<long int> sons(K, 0);
            sons.push_front(1);
            for(long int i = 1; i < N; i++) {
                weight += nodesCount;
                if(weight >= 1234567890) break;
                parents += sons.front() - sons.back();
                nodesCount += parents;
                sons.pop_back();
                sons.push_front(parents);
            }
            printf("%li\n", weight);
        }
    }
    return 0;
}

/*
Input:
10000 0
101 1
10 2
1221 128
0 0


Output:
9999
5050
221
2147483647
*/