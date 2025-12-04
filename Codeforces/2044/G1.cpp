/*
    Problem : https://codeforces.com/contests/2044/problems/A
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

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();
    int t;
    cin >> t;

    ll n;
    while(t--) {
        cin >> n;
        vector<ll> r(n+1);
        forn(i,1,n) cin >> r[i];
        
        ll u, v;
        vector<bool> vis(n+1, false);
        vector<ll> prev(n+1);
        vector<ll> cnt(n+1);
        ll ans=0;
        forn(i,1,n) {
            if(vis[i]) continue;            
            u=i;
            while(!vis[u]) {
                vis[u] = true;
                prev[r[u]] = u;
                u = r[u];
            }
            v=i;
            while(v!=u) {
                prev[r[v]] = v;
                v = r[v];
            }
            while(u!=i) {
                cnt[prev[u]] = cnt[u]+1;
                u = prev[u];
                ans = max(ans, cnt[u]);
            }
        }
        cout << ans+2 << endl;
    } 
    return 0;
}
