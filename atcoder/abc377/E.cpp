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

ll binPow(ll x, ll exp, ll mod) {
    if(mod <= 1) return 0;
    ll ans = 1;
    while(exp > 0) {
        if(exp&1) ans = (ans * x) % mod;
        x = (x*x) % mod;
        exp >>= 1; 
    }
    return ans;
}


int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n+1);
    forn(i,1,n) cin >> p[i];

    vector<ll> ans(n+1);
    vector<bool> vis(n+1, false);
    forn(i,1,n) {
        ll cur = p[i];
        vector<ll> cycle;
        while(!vis[cur]) {
            vis[cur] = true;
            cycle.push_back(cur);
            cur = p[cur];
        }
        ll shift = binPow(2, k, cycle.size());
        forn(j,1,cycle.size()) {
            ans[cycle[j-1]] = cycle[(j-1 + shift) % cycle.size()];
        }
    }

    forn(i,1,n) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
