/*
    Problem : https://codeforces.com/contest/2117/problem/F
    Author : Baptiste Prévost
    Subjects : dynamic programming, number theory, gcd, factors

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

ull custom_pgcd(ull u, ull v) {
    while(u > 0) {
        if(u < v) swap(u, v);
        u = u%v;
    }
    return v;
}

ll solve(ll x, ll k) {
    vll factors;
    ll d=1;
    while(d*d<=x) {
        if(x%d==0) {
            factors.push_back(d);
            factors.push_back(x/d);
        }
        d++;
    }
    sort(factors.rbegin(), factors.rend());
    safeMap dp;
    forv(f, factors) {
        dp[f] = LLONG_MAX;
    }
    dp[x]=0;
    forv(f, factors) {
        if(dp[f] == LLONG_MAX) continue;
        forv(g, factors) {
            if(g>k) continue;
            if(f%g!=0) continue;
            ll v = f/g;
            dp[v]=min(dp[v], dp[f] + 1);
        }
    }
    return dp[1];
}
const ll MOD = 1e9+7;

ll fastPow(ll a, ll b) {
    ll res=1;
    while(b) {
        if(b&1) res = (res*a)%MOD;
        a=a*a;
        b>>=1;
    }
    return res;
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
        vll leaves;
        forn(i,2,n) if(adj[i].size()==1) leaves.push_back(i);
        
        vll parent(n+1);
        parent[1]=1;
        vll s={1};
        while(!s.empty()) {
            ll u=s.back();
            s.pop_back();
            for(ll v : adj[u]) {
                if(parent[v]) continue;
                parent[v]=u;
                s.push_back(v);
            }
        }

        ll ans=0;
        if(leaves.size()==1) {
            ans = fastPow(2,n);
        } else if(leaves.size()==2) {
            ll left=leaves[0], right=leaves[1];
            ll m=n;
            while(true) {
                if(adj[left].size()>=3 || left==1) break;
                left=parent[left];
                m--;
                if(adj[right].size()>=3 || right==1) break;
                right=parent[right];
                m--;
            }
            ans = (ans + fastPow(2,m)) % MOD;
            
            left=leaves[1], right=leaves[0];
            m=n;
            while(true) {
                if(adj[left].size()>=3 || left==1) break;
                left=parent[left];
                m--;
                if(adj[right].size()>=3 || right==1) break;
                right=parent[right];
                m--;
            }
            ans = (ans + fastPow(2,m)) % MOD;
        }
        outln(ans)
    }

    return 0;
}