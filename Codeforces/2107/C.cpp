/*
    Problem : https://codeforces.com/contest/2107/problem/C
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

int main() {
    fastIO();
    int t; in(t)

    const ll INF=1e17;
    
    while(t--) {
        inll(n) inll(k)
        ins(s)
        inv(a,n)

        ll sm=0, mx=0;
        forn(i,1,n) {
            if(s[i-1]=='0') {
                sm=0;
                a[i]=-INF;
                continue;
            }
            sm+=a[i];
            if(sm<=0) sm=0;
            if(sm>mx) mx=sm;
        }
        bool done=(mx==k);
        if(mx <= k) {
            forn(i,1,n) {
                if(s[i-1]=='1') continue;
                if(done) continue;
                ll before=0, after=0;
                if(i>1 && s[i-2]=='1') {
                    ll pref=0;
                    ll j=i-1;
                    while(j>0 && s[j-1]=='1') {
                        pref+=a[j];
                        before=max(before,pref);
                        j--;
                    }
                }
                if(i<n && s[i]=='1') {
                    ll suff=0;
                    ll j=i+1;
                    while(j<=n && s[j-1]=='1') {
                        suff+=a[j];
                        after=max(after,suff);
                        j++;
                    }
                }
                a[i]=k-before-after;
                done=true;
            }
        }

        yon(done);
        if(done) {
            forn(i,1,n) out(a[i])
            outln(" ")
        }
    }
    

    return 0;
}
