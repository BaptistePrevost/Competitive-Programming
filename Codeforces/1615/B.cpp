/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include <iostream>
#include "math.h"
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;
int t, l, r, ans, count[200010][20];

int main() {
    //preprocessing
    for(int i=1; i<=200000; i++) {
        for(int j = 0; j<18; j++) {
            count[i][j] = count[i-1][j] + ((i&(1<<j))==0);
        }
    }

    cin >> t;

    while(t--) {
        cin >> l >> r;
        ans = 1e9;
        forn(j, 18) {
            ans = min(ans, count[r][j]-count[l-1][j]);
        }
        cout << ans << endl;
    }

    return 0;
}
