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
        vector<ll> a(n);
        forn(i,0,n-1) cin >> a[i];

        ll ans = 0;
        ll l=n/2-1;
        ll r=n/2;

        if(n%2) {
            r++;
            ans += (a[l] == a[n/2]); 
            ans += (a[r] == a[n/2]);
        } else {
            ans += (a[l] == a[r]);
        }
        l--; r++;

        while(r < n && l >= 0) {
            ans += min((a[l] == a[l+1]) + (a[r] == a[r-1]), (a[r] == a[l+1]) + (a[l] == a[r-1]));
            l--; r++;
        }
        
        cout << ans << endl;
    }

    return 0;
}
