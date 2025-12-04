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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    forn(i,1,n) cin >> a[i-1];
    sort(a.begin(), a.end());
    
    ll ans = 0;
    for(auto it = a.rbegin(); it != a.rend(); it++) {
        m -= *it;
        ans++;
        if(m <= 0) break;
    }

    cout << ans << endl;

    return 0;
}
