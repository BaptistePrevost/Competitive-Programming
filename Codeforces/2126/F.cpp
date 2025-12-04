/*
    Problem : https://codeforces.com/contest/2126/problem/F
    Author : Baptiste Prévost
    Subjects : 

    Idea : The key idea is to root the tree. By doing so, each node only needs to notify its direct parent.

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
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<pll> vpll;


#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)
#define yon(t) cout << (t ? "Yes" : "No") << endl;
#define in(n) cin >> n;
#define inll(n) ll n; in(n);
#define inv(a,n) vll a(n+1); forn(i,1,n) in(a[i]);
#define inc(c) char c; in(c);
#define ins(s) string s; in(s);
#define out(x) cout << x << " ";
#define outln(x) cout << x << endl;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();
    int t; in(t)
    
    while(t--) {
        inll(n) inll(q)
        inv(color,n)
        vector<unordered_map<ll, ll>> adj(n+1);
        ll total=0;
        forn(i,1,n-1) {
            inll(u) inll(v) inll(c)
            total += c*(color[u]!=color[v]);
            adj[u][v] = c;
            adj[v][u] = c;
        }

        vector<unordered_map<ll, ll>> cnt(n+1);
        vll parent(n+1);

        function<void(ll, ll)> dfs = [&](ll u, ll v) {
            if (cnt[v].find(color[u]) == cnt[v].end()) cnt[v][color[u]] = 0;
            cnt[v][color[u]] = cnt[v][color[u]]+adj[u][v];
            parent[u]=v;
            for (const auto& [w, c] : adj[u]) {
                if (w == v) continue;
                dfs(w, u);
            }
        };

        dfs(1,0);

        forn(i,1,q) {
            inll(v) inll(x)
            if (color[v] != x) {
                if (color[v] == color[parent[v]]) total += adj[v][parent[v]];
                if (x == color[parent[v]]) total -= adj[v][parent[v]];
                if (cnt[v].find(color[v]) != cnt[v].end()) total += cnt[v][color[v]];
                if (cnt[v].find(x) != cnt[v].end()) total -= cnt[v][x];
                if (parent[v] > 0) cnt[parent[v]][color[v]] -= adj[parent[v]][v];
                if (cnt[parent[v]].find(x) == cnt[parent[v]].end()) cnt[parent[v]][x] = 0;
                cnt[parent[v]][x] += adj[parent[v]][v];
            }
            color[v]=x;
            outln(total);
        }
    }

    return 0;
}