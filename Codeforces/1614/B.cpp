/*
    Author : Baptiste Prévost

    Idea : 
        - Basic greedy algorithm
*/

#include <iostream>
#include <list>
#include <utility>
#include "math.h"
using namespace std;

int main() {
    long long int t, n, a;
    long long int ret[200002];
    scanf("%lld", &t);
    while(t--) {
        list< pair< long long int, long long int> > v;
        scanf("%lld", &n);
        for(long long int i = 1; i <= n; i++) {
            scanf("%lld", &a);
            v.push_back(make_pair(-a, i));
        }
        v.sort();
        long long int dist = 0, done = 0;
        for(list< pair< long long int, long long int> >::iterator it = v.begin(); it != v.end(); it++) {
            dist += (done/2 + 1)*(-it->first)*2;
            ret[it->second] = pow(-1, done)*(done/2 + 1);
            done++;
        }
        printf("%lld\n0", dist);
        for(long long int i = 0; i < n; i++) {
            printf(" %lld", ret[i+1]);
        }
        printf("\n");
    }
    return 0;
}