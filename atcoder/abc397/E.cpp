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
    ll n, k; in(n) in(k);
    vector<vll> adj(n*k+1);
    ll u, v;
    forn(i,1,n*k) {
        in(u) in(v)
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> seen(n*k+1);
    bool valid=true;
    function<ll(ll)> dfs = [&](ll u) {
        if(!valid) return (ll)0;
        ll cnt=1;
        ll deg=0;
        seen[u] = true;
        for(ll v : adj[u]) {
            if(seen[v]) continue;
            ll subCnt = dfs(v);
            if(subCnt) deg++;
            cnt += subCnt;
        }
        if(cnt>k) {
            valid=false;
        } else if(cnt<k) {
            valid &= deg<2;
        } else if(deg<=2) {
            cnt=0;
        } else {
            valid=false;
        }
        return cnt;
    };
    forn(i,1,n*k) {
        if(seen[i]) continue;
        valid &= (dfs(i)==0);
    }
    yon(valid);

    return 0;
}
