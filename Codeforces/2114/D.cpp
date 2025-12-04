/*
    Problem : https://codeforces.com/contest/2114/problem/D
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

struct Pt {
    ll x, y, i;
};

vll x, y;

vector<Pt> solve(ll skip) {
    vector<Pt> pts = {{LLONG_MAX, 0, 0}, {LLONG_MIN, 0, 0}, {0, LLONG_MAX, 0}, {0, LLONG_MIN, 0}}; //leftMost, rightMost, topMost, botMost
    forn(i,1,x.size()-1) {
        if(i == skip) continue;
        if(x[i] < pts[0].x) {
            pts[0].x = x[i];
            pts[0].y = y[i];
            pts[0].i = i;
        }
        if(x[i] > pts[1].x) {
            pts[1].x = x[i];
            pts[1].y = y[i];
            pts[1].i = i;
        }
        if(y[i] < pts[2].y) {
            pts[2].x = x[i];
            pts[2].y = y[i];
            pts[2].i = i;
        }
        if(y[i] > pts[3].y) {
            pts[3].x = x[i];
            pts[3].y = y[i];
            pts[3].i = i;
        }
    }
    return pts;
}

int main() {
    fastIO();
    int t; in(t)
    
    while(t--) {
        inll(n)
        x.resize(n+1); y.resize(n+1);
        forn(i,1,n) {
            in(x[i]) in(y[i])
        }

        vector<Pt> pts = solve(0);
        ll ans = (pts[1].x - pts[0].x + 1) * (pts[3].y - pts[2].y + 1);
        if(ans==n) {
            outln(ans)
            continue;
        }
        forn(i,0,3) {
            vector<Pt> newPts = solve(pts[i].i);
            ll area = (newPts[1].x - newPts[0].x + 1) * (newPts[3].y - newPts[2].y + 1);
            if(area == n-1) {
                ans = min(ans, area + min(newPts[1].x - newPts[0].x + 1, newPts[3].y - newPts[2].y + 1));
            } else {
                ans = min(ans, area);
            }
        }
        outln(ans)
    }

    return 0;
}