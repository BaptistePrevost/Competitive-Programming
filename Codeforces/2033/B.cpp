/*
    Problem : 
    Author : Baptiste Prévost
    Subjects :

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>
#include <vector>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)

int main() {
    int t;
    cin >> t;

    ll n;
    while(t--) {
        cin >> n;
        vector<vector<ll>> a(n, vector<ll>(n));
        forn(i,0,n-1) {
            forn(j,0,n-1) cin >> a[i][j];
        }

        ll ans = 0;

        forn(i,1,n-1) {
            ll mn = 0;
            forn(j,0,n-1-i) {
                mn = min(mn, a[i+j][j]);
            }
            ans -= mn;
        }

        forn(i,0,n-1) {
            ll mn = 0;
            forn(j,0,n-1-i) {
                mn = min(mn, a[j][i+j]);
            }
            ans -= mn;
        }
        
        cout << ans << endl;
    }

    return 0;
}
