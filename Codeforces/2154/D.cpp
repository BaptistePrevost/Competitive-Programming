/*
    Problem : https://codeforces.com/contest/2154/problem/D
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
        inll(n)
        vector<unordered_set<ll>> adj(n+1, unordered_set<ll>());
        forn(i,1,n-1) {
            inll(u) inll(v)
            adj[u].insert(v);
            adj[v].insert(u);
        }

        // Root tree in n
        vll parent(n+1, -1);
        parent[n]=n;
        vll sz(n+1, 0);
        vll rk(n+1, 0);
        function<ll(ll)> dfs = [&](ll u) {
            sz[u] = 1;
            forv(v,adj[u]) {
                if(parent[v]!=-1) continue;
                parent[v] = u;
                rk[v] = rk[u]+1;
                sz[u] += dfs(v);
            }
            return sz[u];
        };
        dfs(n);
        queue<ll> evenLeaves, oddLeaves;
        forn(u,1,n-1) {
            if (adj[u].size() > 1) continue;
            if (rk[u]&1) oddLeaves.push(u);
            else evenLeaves.push(u);
        }

        bool state = (rk[1]&1);
        vpll ans;
        ll deletedLeaves=0;
        while(!oddLeaves.empty() || !evenLeaves.empty()) {
            queue<ll>& q = oddLeaves;
            if (state) q = evenLeaves;
            
            if (!q.empty()) {
                ll u = q.back();
                q.pop();
                ans.push_back({2,u});
                deletedLeaves++;
                for (ll v : adj[u]) {
                    if(v==n) continue;
                    adj[v].erase(u);
                    if (adj[v].size() == 1) {
                        if (rk[v]&1) oddLeaves.push(v);
                        else evenLeaves.push(v);
                    }
                }
            }
            
            ans.push_back({1,0});

            state ^= 1;
        }

        forn(i,1,n) ans.push_back({1,0});

        outln(ans.size())
        for(auto p : ans) {
            if (p.first==1) outln(1)
            else {
                out(2) outln(p.second);
            }
        }
        outln(' ')

    }

    return 0;
}