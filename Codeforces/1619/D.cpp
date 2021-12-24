/*
    Author : Baptiste Prévost

    Idea : 
        - binary search
        - To check whether a res is possible or not, we should make sure that :
            1. We can pick 2 gifts from at least 1 shop
            2. We can find a gift for each friend that satisfies res
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    long long int t, m, n, mini, maxi, res, sat[500001];
    cin >> t;
    while(t--) {
        cin>>m>>n;
        mini = 1000000000;
        maxi = 0;

        string bitmask(n-1, 1);
        bitmask.resize(m, 0);

        for(long long int i=0; i<m; i++) {
            for(long long int j=0; j<n; j++) {
                cin >> sat[i*n+j];
                if(mini > sat[i*n+j]) mini = sat[i*n+j];
                if(maxi < sat[i*n+j]) maxi = sat[i*n+j];
            }
        }

        bool possible, cond1, cond2;
        while(maxi-mini>1) {
            // printf("Trying %lli (min is %lli, max is %lli)\n", res, mini, maxi);
            res = (mini + maxi)/2;
            vector<bool> able(n);

            cond1 = false; cond2 = true;

            for(long long int i=0; i<m; i++) {
                int count = 0;
                for(long long int j=0; j<n; j++) {
                    if(sat[i*n+j]>=res) {
                        able[j] = true;
                        count++;
                    }
                }
                if(count>1) cond1 = true;
            }

            for(bool b: able) {
                cond2 = cond2 && b;
            }

            possible = cond1 && cond2;

            if(possible) {
                // printf("\tPossible\n");
                mini = res;
            } else {
                // printf("\tNot possible\n");
                maxi = res;
            }
        }
        cout << mini << endl;
    }
    return 0;
}