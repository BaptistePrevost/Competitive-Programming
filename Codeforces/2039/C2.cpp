/*
    Problem : 
    Author : Baptiste Prévost
    Subjects :

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();
    int t;
    cin >> t;

    ull x, m;
    while(t--) {
        cin >> x >> m;

        ull ans = 0;
        for(ull y=1; y<x; y++) {
            if(y > m) break;
            if(((x^y) % x == 0) || ((x^y) % y == 0)) ans++;
        }

        if(x<=m) {
            ull mid, left=0, right=UINT64_MAX/(2*x);
            while(right-left > 1) {
                mid = (left+right) / 2;
                ull y = x^((2*mid-1)*x);
                if(y <= m) left = mid;
                else right = mid; 
            }
            ans += left;

            left=0, right=UINT64_MAX/(2*x);
            while(right-left > 1) {
                mid = (left+right) / 2;
                ull y = x^(2*mid*x);
                if(y <= m) left = mid;
                else right = mid; 
            }
            ans += left;
        }

        cout << ans << endl;
    }

    return 0;
}
