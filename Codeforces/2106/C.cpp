/*
    Problem : https://codeforces.com/contest/2106/problem/C
    Author : Baptiste Prévost
    Subjects : bitset

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
typedef vector<bool> vb;

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

ll solve(vll &a, vll &b, ll n, ll k) {
    ll smin = LLONG_MIN;
    ll smax = LLONG_MAX;
    ll cnt=0;
    forn(i,1,n) {
        if(b[i] == -1) {
            cnt++;
            if(smin<a[i]) smin=a[i];
            if(smax>a[i]+k) smax=a[i]+k;
        } else {
            if(smax<a[i]+b[i]) return 0;
            if(smin>a[i]+b[i]) return 0;
            smin = a[i]+b[i];
            smax = a[i]+b[i];
        }
    }
    if(cnt==0) return 1;
    if(smin>smax) return 0;
    return smax-smin+1;
}

int main() {
    fastIO();
    int t; in(t)
    
    while(t--) {
        inll(n) inll(k)
        inv(a,n)
        inv(b,n)
        outln(solve(a,b,n,k));
        
    }
    

    return 0;
}
