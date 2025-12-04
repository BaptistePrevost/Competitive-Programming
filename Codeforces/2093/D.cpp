/*
    Problem : https://codeforces.com/contest/2091/problem/D
    Author : Baptiste Prévost
    Subjects : number theory, arithmetic

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

void rec1(ll x1, ll y1, ll x2, ll y2, ll low, ll high, ll x, ll y) {
    assert(x1 <= x && x <= x2);
    assert(y1 <= y && y <= y2);
    if(low == high) {
        outln(low)
        return;
    }
    ll t = high-low+1;
    if(x > (x1+x2)/2) {
        if(y > (y1+y2)/2) {
            rec1((x1+x2)/2+1, (y1+y2)/2+1, x2, y2, low+t/4, low+t/2-1, x, y);
        } else {
            rec1((x1+x2)/2+1, y1, x2, (y1+y2)/2, low+3*t/4, high, x, y);
        }
    } else {
        if(y > (y1+y2)/2) {
            rec1(x1, (y1+y2)/2+1, (x1+x2)/2, y2, low+t/2, low+3*t/4-1, x, y);
        } else {
            rec1(x1, y1, (x1+x2)/2, (y1+y2)/2, low, low+t/4-1, x, y);
        }
    }
}

void rec2(ll x1, ll y1, ll x2, ll y2, ll low, ll high, ll d) {
    if(low == high) {
        out(y1) outln(x1)
        return;
    }
    ll t = high-low+1;
    if(d >= low+3*t/4) rec2((x1+x2)/2+1, y1, x2, (y1+y2)/2, low+3*t/4, high, d);
    else if(d >= low+t/2) rec2(x1, (y1+y2)/2+1, (x1+x2)/2, y2, low+t/2, low+3*t/4-1, d);
    else if(d >= low+t/4) rec2((x1+x2)/2+1, (y1+y2)/2+1, x2, y2, low+t/4, low+t/2-1, d);
    else rec2(x1, y1, (x1+x2)/2, (y1+y2)/2, low, low+t/4-1, d);
}

int main() {
    fastIO();
    int t; in(t)

    while(t--) {
        ll n, q; in(n) in(q)
        char c;
        ll x, y, d;
        ll twon = 1, twotwon = 1;
        forn(i,1,n) twon*=2;
        forn(i,1,2*n) twotwon*=2;
        forn(i,1,q) {
            in(c) in(c)
            if(c=='>') {
                in(x) in(y)
                rec1(1, 1, twon, twon, 1, twotwon, y, x);
            } else {
                in(d)
                rec2(1, 1, twon, twon, 1, twotwon, d);
            }
        }
        
    }
    

    return 0;
}
