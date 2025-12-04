/*
    Problem : https://codeforces.com/contest/2163/problem/D
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

ll query(ll l, ll r) {
    out('?') out(l) outln(r)
    inll(ret)
    return ret;
}

int main() {
    fastIO();
    int t; in(t)
    
    while(t--) {
        inll(n) inll(q)
        vpll ranges(q+1, {0,0});
        forn(i,1,q) {
            in(ranges[i].first) in(ranges[i].second);
        }

        // Find where 0 is
        ll firstHalf = query(1, n/2);
        ll secondHalf = query(n/2 + 1, n);
        ll leftMost = 1, rightMost = n;
        if (firstHalf == secondHalf) {
            out('!') outln(0);
            continue;
        } else if (firstHalf > secondHalf) {
            rightMost = n/2;
        } else {
            leftMost = n/2 + 1;
        }


        // Only keep non-dominating ranges (no range is contained in any other range) that overlap [leftMost, rightMost]
        // There are at most n/2 such ranges
        sort(ranges.begin(), ranges.end(), [](const pll& r1, pll& r2) {
            if (r1.first == r2.first) return r1.second > r2.second;
            return r1.first < r2.first;

        });
        ll prv = 0;
        ll ans = 0;
        forn(i,1,q) {
            if (ranges[i].second <= prv) continue;
            if (ranges[i].first > rightMost) continue;
            if (ranges[i].second < leftMost) continue;
            ans = max(ans, query(ranges[i].first, ranges[i].second));
            prv = ranges[i].second; 
        }
        out('!') outln(ans)
    }

    return 0;
}