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
    vector<ll> cnt(m+1);
    ll a;
    forn(i,1,n) {
        cin >> a;
        cnt[a]++;
    }
    
    ll ans = 0;
    forn(i,1,m) {
        forn(j,i+1,m) {
            ans += cnt[i]*cnt[j];
        }
    }
    
    cout << ans << endl;
    return 0;
}
