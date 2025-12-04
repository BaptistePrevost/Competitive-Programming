/*
    Problem : https://codeforces.com/contest/2112/problem/C
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
        vector<vll> adj(n+1);
        forn(i,1,n-1) {
            inll(u) inll(v)
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool valid=false;
        int u=-1;
        forn(i,1,n) {
            if(adj[i].size()==2) {
                valid=true;
                u=i;
                break;
            }
        }
        yon(valid)
        if(valid) {
            unordered_set<ll> vis;
            vis.insert(u);
            for(int i=0; i<2; i++) {
                vector<pair<ll,bool>> q;
                if (i&1) {
                    out(u) outln(adj[u][i])
                    q.push_back(make_pair(adj[u][i], true));
                } else {
                    out(adj[u][i]) outln(u)
                    q.push_back(make_pair(adj[u][i], false));
                }
                while(!q.empty()) {
                    auto p = q.back();
                    q.pop_back();
                    vis.insert(p.first);
                    for(const ll &v : adj[p.first]) {
                        if(vis.find(v) != vis.end()) continue;
                        q.push_back(make_pair(v, p.first==u || !p.second));
                        if(p.second) {
                            out(v) outln(p.first);
                        } else {
                            out(p.first) outln(v);
                        }
                    }
                }
            }
        }
    }

    return 0;
}