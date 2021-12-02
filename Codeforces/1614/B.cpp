/*
    Author : Baptiste Prévost

    Idea : 
        -
        -
*/

#include <iostream>
#include <list>
#include <utility>
#include "math.h"
using namespace std;

int main() {
    int t, n, a;
    int ret[200002];
    scanf("%i", &t);
    while(t--) {
        list< pair< int, int> > v;
        scanf("%i", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%i", &a);
            v.push_back(make_pair(-a, i));
        }
        v.sort();
        int dist = 0, done = 0;
        for(list< pair< int, int> >::iterator it = v.begin(); it != v.end(); it++) {
            dist += (done/2 + 1)*(-it->first)*2;
            ret[it->second] = pow(-1, done/2)*(done/2 + 1);
            done++;
        }
        printf("%i\n0", dist);
        for(int i = 0; i < n; i++) {
            printf(" %i", ret[i+1]);
        }
        printf("\n");
    }
    return 0;
}