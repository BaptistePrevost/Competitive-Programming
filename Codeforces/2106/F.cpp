/*
    Problem : https://codeforces.com/contest/2106/problem/F
    Author : Baptiste Prévost
    Subjects : DSU

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

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef unordered_map<long long, long long, custom_hash> safeMap;
typedef vector<ui> vui;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<ll,ll> pll;

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

struct DSU {
    public:
        DSU(ll n) {
            parent_.resize(n+1, 0);
            forn(i,1,n) parent_[i] = i;
            size_.resize(n+1, 1);
        }

        ll find(ll u) {
            if(parent_[u]==u) return u;
            return parent_[u] = find(parent_[u]);
        }

        void merge(ll u, ll v) {
            u = find(u);
            v = find(v);
            if(u==v) return;
            if(size_[u]<size_[v]) swap(u,v);
            parent_[v]=u;
            size_[u]+=size_[v];
        }

        ll size(ll u) {
            return size_[find(u)];
        }

    vll parent_;
    vll size_;
};

bool overlap(const pll &n1, const pll &n2) {
    return n2.first < n1.second && n1.first < n2.second;
}

int main() {
    fastIO();
    int t; in(t)

    while(t--) {
        inll(n) ins(s);
        vector<pll> nodes(2*n);
        forn(i,0,n-1) {
            if(s[i] == '1') {
                nodes[2*i] = {-1, -1};
                nodes[2*i+1] = {i, i+1};
            } else {
                nodes[2*i] = {0,i};
                nodes[2*i+1] = {i+1,n};
            }
        }
        DSU dsu(2*n);
        forn(i,0,2*n-1) dsu.size_[i] = nodes[i].second - nodes[i].first;
        forn(i,1,n-1) {
            if(overlap(nodes[2*i], nodes[2*i-2])) dsu.merge(2*i, 2*i-2);
            if(overlap(nodes[2*i], nodes[2*i-1])) dsu.merge(2*i, 2*i-1);
            if(overlap(nodes[2*i+1], nodes[2*i-2])) dsu.merge(2*i+1, 2*i-2);
            if(overlap(nodes[2*i+1], nodes[2*i-1])) dsu.merge(2*i+1, 2*i-1);
        }

        ll ans = 0;
        forn(i,0,2*n-1) {
            ans = max(ans, dsu.size(i));
        }
        outln(ans)
    }
    

    return 0;
}
