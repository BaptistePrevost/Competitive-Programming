/*
    Problem : https://codeforces.com/contest/2107/problem/D
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

vector<unordered_set<ll>> adj;
pll dfs(ll u, ll prev, ll dist) {
    pll ret;
    forv(v, adj[u]) {
        if(v==prev) continue;
        dfs(v,u,dist+1);
    }
}
int main() {
    fastIO();
    int t; in(t)

    const ll INF=1e17;
    
    while(t--) {
        inll(n)
        adj=vector<unordered_set<ll>>(n+1);
        forn(i,1,n-1) {
            inll(u) inll(v)
            adj[u].insert(v);
            adj[v].insert(u);
        }

        vll roots = {1};
        struct Element {
            ll u;
            ll from;
            ll dist;
        };
        while(true) {
            for(ll root : roots) {
                
                vector<Element> dfs;
                Element mxElt = {1,0,0};
                dfs.push_back(mxElt);
                while(!dfs.empty()) {
                    Element elt = dfs.back();
                    dfs.pop_back();
                    if(elt.dist>mxElt.dist) mxElt=elt;
                    forv(v, adj[elt.u]) {
                        if(v==elt.from) continue;
                        dfs.push_back({v, elt.u, elt.dist+1});
                    }
                }
            }
        }
    }
    

    return 0;
}
