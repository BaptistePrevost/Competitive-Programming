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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

typedef long long ll;
typedef unsigned long long ull;
typedef unordered_map<long long, long long, custom_hash> safeMap;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)
#define yon(t) cout << (t ? "YES" : "NO") << endl;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool solve(ll n, ll m, ll k) {
    if(n < k && m < k) return false;
    if(n > m) {

    }
}

int main() {
    fastIO();
    int t;
    cin >> t;

    ll n;
    while(t--) {
        cin >> n;
        vector<unordered_set<ll, custom_hash>> adj(n+1);
        vector<ll> a(n+1);
        vector<bool> ans(n+1);
        forn(i,1,n) cin >> a[i];
        ll u, v;
        forn(i,1,n-1) {
            cin >> u >> v;
            if(a[u] == a[v]) ans[a[u]] = true;
            if(adj[u].find(a[v]) != adj[u].end()) ans[a[v]] = true;
            if(adj[v].find(a[u]) != adj[v].end()) ans[a[u]] = true;
            adj[u].insert(a[v]);
            adj[v].insert(a[u]);
        }
        forn(i,1,n) cout << ans[i];
        cout << endl;
    }

    return 0;
}