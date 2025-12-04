/*
    Problem : https://codeforces.com/contest/2114/problem/E
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


vll a;
vector<vll> adj;
vll ans;
void dfs(ll u, ll prev, ll sz, ll sm, ll mx, ll mn) {
    if(sz&1) {
        sm += a[u];
        if(mn<0) ans[u] = sm-mn;
        else ans[u] = sm;
        mx = max(mx, sm);
    } else {
        sm -= a[u];
        if(mx>0) ans[u] = mx-sm;
        else ans[u]= -sm;
        mn = min(mn, sm);
    }
    sz++;
    forv(v, adj[u]) {
        if(v == prev) continue;
        dfs(v, u, sz, sm, mx, mn);
    }
}
int main() {
    fastIO();
    int t; in(t)
    
    while(t--) {
        inll(n)
        a.resize(n+1);
        ans.resize(n+1);
        forn(i,1,n) in(a[i])
        adj = vector<vll>(n+1);
        forn(i,1,n-1) {
            inll(u) inll(v)
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0, 1, 0, 0, 0);
        forn(i,1,n) {
            out(ans[i])
        }
        outln("")
    }

    return 0;
}