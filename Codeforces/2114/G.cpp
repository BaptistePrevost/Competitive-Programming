/*
    Problem : https://codeforces.com/contest/2114/problem/G
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

ull custom_pgcd(ull u, ull v) {
    while(u > 0) {
        if(u < v) swap(u, v);
        u = u%v;
    }
    return v;
}

int main() {
    fastIO();
    int t; in(t)

    while(t--) {
        inll(n) inll(k)
        inv(a,n)
        vll b(n+1);
        forn(i,1,n) {
            ll f=1;
            while(a[i]%2==0) {
                f*=2;
                a[i]/=2;
            }
            b[i]=f;
        }
        vll afterLeft(n+1), afterRight(n+1);
        afterLeft[1]=b[1];
        forn(i,2,n) {
            if(a[i]!=a[i-1] || b[i]<b[i-1]) afterLeft[i]=b[i];
            else afterLeft[i]=(b[i]-2*b[i-1]+1);
        }
        afterRight[n]=b[n];
        rofn(i,n-1,1) {
            if(a[i]!=a[i+1] || b[i]<b[i+1]) afterRight[i]=b[i];
            else afterRight[i]=(b[i]-2*b[i+1]+1);
        }
        vll pref(n+1);
        forn(i,1,n) pref[i]=pref[i-1]+afterRight[i];
        vll suff(n+2);
        rofn(i,n,1) suff[i]=suff[i+1]+afterLeft[i];
        ll mx=0;
        forn(i,1,n) {
            mx=max(mx,pref[i-1]+suff[i+1]+b[i]);
        }
        yon((k>=n&&k<=mx));
    }

    return 0;
}