/*
    Problem : https://codeforces.com/contests/2057/problem/A
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

int main() {
    fastIO();
    int t;
    cin >> t;

    ll n, u, v;
    while(t--) {
        cin >> n;
        vector<ll> degree(n+1);
        vector<vector<ll>> adj(n+1, vector<ll>());
        ll maxDeg = 0;
        forn(i,1,n-1) {
            cin >> u >> v;
            degree[u]++;
            degree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
            maxDeg = max(maxDeg, degree[u]);
            maxDeg = max(maxDeg, degree[v]);
        }

        vector<unordered_set<ll>> inplace(n);
        forn(i,1,n) inplace[degree[i]].insert(i);

        ll ans = 0;
        unordered_set<ll> topNodes(inplace[maxDeg]);
        forv(u,topNodes) {
            ll score = maxDeg;
            
            forv(v, adj[u]) {
                inplace[degree[v]].erase(v);
                degree[v]--;
                inplace[degree[v]].insert(v);
            }
            ll nextMaxDeg = maxDeg;
            while(inplace[nextMaxDeg].empty() || (inplace[nextMaxDeg].size() == 1 && *inplace[nextMaxDeg].begin() == u)) nextMaxDeg--;
            score += nextMaxDeg-1;
            ans = max(ans, score);

            forv(v, adj[u]) {
                inplace[degree[v]].erase(v);
                degree[v]++;
                inplace[degree[v]].insert(v);
            }
            
        }
        cout << ans << endl;
    }

    return 0;
}
