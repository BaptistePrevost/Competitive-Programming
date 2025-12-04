/*
    Problem : https://codeforces.com/contest/2154/problem/C
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

ll solve(const vll& a, ll n) {
    std::unordered_set<ll> divs;
    forn(i,1,n) {
        for(ll j=1; j*j<=a[i]; j++) {
            if (a[i]%j==0) {
                if (divs.find(j) != divs.end()) return 0;
                if (divs.find(a[i]/j) != divs.end()) return 0;
                if(j>1) divs.insert(j);
                if(a[i]/j>1) divs.insert(a[i]/j);
            }
        }
    }

    forn(i,1,n) {
        for(ll j=1; j*j<=a[i]; j++) {
            if (a[i]%j==0) {
                if(j>1) divs.erase(j);
                if(a[i]/j>1) divs.erase(a[i]/j);
            }
        }
        for(ll j=1; j*j<=a[i]+1; j++) {
            if ((a[i]+1)%j==0) {
                if (divs.find(j) != divs.end()) return 1;
                if (divs.find((a[i]+1)/j) != divs.end()) return 1;
            }
        }

        for(ll j=1; j*j<=a[i]; j++) {
            if (a[i]%j==0) {
                if(j>1) divs.insert(j);
                if(a[i]/j>1) divs.insert(a[i]/j);
            }
        }
    }
    
    return 2;
}

int main() {
    fastIO();
    int t; in(t)
    
    while(t--) {
        inll(n)
        inv(a,n) inv(b,n)
        
        outln(solve(a,n))

    }

    return 0;
}