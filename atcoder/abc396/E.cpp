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
    vll x(m+1), y(m+1), z(m+1);
    vector<vector<pair<ll,ll>>> adj(n+1);
    forn(i,1,m) {
        in(x[i]) in(y[i]) in(z[i]);
        adj[x[i]].push_back({y[i], z[i]});
        adj[y[i]].push_back({x[i], z[i]});
    }

    vll a(n+1);
    bool valid = true;
    
    ll mask = 1;
    forn(i,1,20) {
        vector<bool> seen(n+1, false);
        forn(u,1,n) {
            vector<pair<ll,ll>> q = {{u, 0}};
            while(!q.empty()) {
                pair<ll,ll> p = q.back();
                q.pop_back();
                if(a[p.first] != -1) {
                    if(a[p.first] != p.second) {
                        valid = false;
                        break;
                    }
                    continue;
                }
                
                a[p.first] = p.second;
                vals.push_back(p.first);
            
                for(auto neigh : adj[p.first]) q.push_back({neigh.first, neigh.second ^ p.second});

            }
        }


        mask <<= 1;
    }
    forn(i,1,n) {
        if(a[i] >= 0) continue;
        vll vals;
        ll mn = LLONG_MAX;

        while(!q.empty()) {
        }
        for(ll v : vals) a[v] -= mn;
    }

    if(valid) {
        forn(i,1,n) out(max(0ll, a[i]));
    } else out(-1)
    outln(' ');
    return 0;
}
