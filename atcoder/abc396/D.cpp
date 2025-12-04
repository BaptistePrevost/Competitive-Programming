/*
    Problem : 
    Author : Baptiste Prévost
    Subjects :

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>

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
typedef vector<ll> vll;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)
#define yon(t) cout << (t ? "Yes" : "No") << endl;
#define in(n) cin >> n;
#define out(x) cout << x << " ";
#define outln(x) cout << x << endl;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();
    ll n, m; in(n); in(m);
    vector<vector<pair<ll,ll>>> adj(n+1);
    ll u, v, w;
    forn(i,1,m) {
        in(u) in(v) in(w)
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    ll ans = LLONG_MAX;
    function<void(ll, ll, vector<bool>&)> dfs = [&](ll u, ll x, vector<bool> &seen) {
        if(u == n) {
            ans = min(ans, x);
            return;
        }
        for(auto p : adj[u]) {
            if(!seen[p.first]) {
                seen[p.first] = true;
                dfs(p.first, x ^ p.second, seen);
                seen[p.first] = false;
            }
        }
    };
    vector<bool> seen(n+1);
    seen[1] = true;
    dfs(1, 0, seen);
    outln(ans);

    return 0;
}
