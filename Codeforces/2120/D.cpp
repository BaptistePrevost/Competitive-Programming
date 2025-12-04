/*
    Problem : https://codeforces.com/contest/2120/problem/D
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


struct Combinatorial {
    vector<ll> fact, ifact, twoPows;
    ll n;
    ll MOD;

    ll binaryExponentiation(ll base, ll exp) {
        ll ans = 1;
        while(exp > 0) {
            if(exp & 1) {
                ans = (ans*base) % MOD;
            }
            base = (base*base) % MOD;
            exp >>= 1;
        }
        return ans;
    }

    ll among(ll k, ll n) {
        if(k<0 || k>n) return 0;
        return (fact[n]*((ifact[k]*ifact[n-k])%MOD))%MOD;
    }
    
    ll twoPow(ll exp) {
        return twoPows[exp];
    }

    Combinatorial(ll n, ll MOD) : n(n), MOD(MOD) {
        fact.resize(n+1);
        ifact.resize(n+1);
        twoPows.resize(n+1);

        fact[0] = 1;
        forn(i,1,n) fact[i] = (fact[i-1]*i)%MOD;
        ifact[n] = binaryExponentiation(fact[n], MOD-2);
        rofn(i,n-1,0) ifact[i] = (ifact[i+1]*(i+1))%MOD;
        twoPows[0] = 1;
        forn(i,1,n) twoPows[i] = (twoPows[i-1]*2)%MOD;
    }
};

const ll MOD = 1e9+7;
int main() {
    fastIO();
    int t; in(t)

    Combinatorial c(1e5+1, MOD);
    
    while(t--) {
        inll(a) inll(b) inll(k)
        ll n = k*(a-1) + 1;
        ll m = ((k*(b-1) % MOD) * c.ifact[a]) % MOD;
        forn(i,1,a) {
            m = (m*((n-i+1)%MOD)) % MOD;
        }
        m++;
        while(m<0) m+=MOD;
        out(n % MOD) outln(m % MOD)
    }

    return 0;
}