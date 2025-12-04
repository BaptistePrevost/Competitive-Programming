/*
    Problem : https://codeforces.com/contest/2159/problem/B
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

int main() {
    fastIO();
    int t; in(t)

    // b1 = f(a[1,1])
    // b2 = f(a[1,2]) + f(a[2,2])
    // b3 = f(a[1,3]) + f(a[2,3]) + f(a[3,3])
    //...
    
    while(t--) {
        inll(n)
        vll b(n+1);
        forn(i,1,n) in(b[i])
        vll a(n+1, 1);
        vll f(n+1, 1);
        vll g(n+1, 1);
        ll c = 1;
        forn(i,2,n) {
            if(b[i] == b[i-1] + i) {
                c++;
                a[i] = c;
            } else {
                a[i] = a[i-(b[i]-b[i-1])];
            }
        }
        forn(i,1,n) out(a[i])
        outln(" ")
    }

    return 0;
}