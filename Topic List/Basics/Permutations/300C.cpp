/*
    Problem : https://codeforces.com/contest/300/problem/C
    Author : Baptiste Prévost
    Subjects : combinatorics

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)
#define yon(t) cout << (t ? "YES" : "NO") << endl;

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

void prec(ll a, ll b, ll x, ll mx, unordered_set<ll> &s) {
    if(x>mx) return;
    s.insert(x);
    prec(a, b, 10*x+a, mx, s);
    prec(a, b, 10*x+b, mx, s);
}

bool valid(ll x, ll a, ll b) {
    while(x) {
        if(x%10!=a && x%10!=b) return false;
        x/=10;
    }
    return true;
}

int main() {
    fastIO();

    const ll N = 1e6+9;
    const ll MOD = 1e9+7;
    Combinatorial c(N, MOD);

    ll a, b, n;
    cin >> a >> b >> n;
    
    ll ans = 0;
    forn(i,0,n) {
        ll x = i*a + (n-i)*b;
        if(!valid(x,a,b)) continue;
        ans = (ans+c.among(i,n)) % MOD;
    }
    cout << ans << endl;
    return 0;
}