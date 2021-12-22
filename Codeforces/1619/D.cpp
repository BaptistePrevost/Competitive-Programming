/*
    Author : Baptiste Prévost

    Idea : 
        - bruteforce over permutations
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main() {
    unsigned int t, m, n, a, b, inser, res, sat[500001];
    cin >> t;
    while(t--) {
        cin>>m>>n;

        string bitmask(n-1, 1);
        bitmask.resize(m, 0);

        for(unsigned int i=0; i<m; i++) {
            for(unsigned int j=0; j<n; j++) {
                cin >> sat[i*n+j];
            }
        }
        res=0;
        do {
            a=-1;
            for(unsigned int j=0; j<n; j++) {
                b=0;
                for(unsigned int i=0; i<m; i++) {
                    if (bitmask[i]) {
                        b=max(b, sat[i*n+j]);
                    }
                }
                a=min(a,b);
            }
            res = max(res,a);
        } while (std::prev_permutation(bitmask.begin(), bitmask.end()));

        cout<<res<<endl;
    }
    return 0;
}